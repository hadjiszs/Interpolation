#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

#include "pavage.hpp"

namespace po = boost::program_options;

template class Pavage<1, double>;
template class Pavage<2, double>;
template class Pavage<3, double>;

template<unsigned int DIM>
void do_stuff(std::string filename)
{
    //
    // Initialisation du pavage
    //
    std::vector<Point< DIM , double > > data;
    std::cout << "nom fichier : [" << filename << "]" << std::endl;

    std::ifstream ifs;
    std::string token, raw;
    double max_value = 0;

    try {
        ifs.open(filename.c_str(), std::ifstream::in);
    } catch(const std::exception& ex) {
        std::cerr << "Erreur à l'ouverture du fichier [" << filename << "] : " << ex.what() << std::endl;
    }

    if(ifs.fail() || !ifs.is_open())
    {
        std::cerr << "Erreur à l'ouverture du fichier [" << filename << "]" << std::endl;
        exit(EXIT_FAILURE);
    }

    while(getline(ifs, raw))
    {
        // std::cout << raw << std::endl;
        std::istringstream iss(raw);

        Point<DIM, double> curr;
        std::getline(iss, token, ';');
        curr.set_value(std::stod(token));

        unsigned int k = 0;
        while(std::getline(iss, token, ';'))
        {
            curr[k] = std::stod(token);
            if(fabs(curr[k]) > max_value)
                max_value = fabs(curr[k]) ;

            k++;
        }

        data.push_back(curr);
        std::cout << curr << std::endl;
    }

    ifs.close();

    // Tous les points sont maintenant dans le vector data

    //
    // creation du pavage et du vector data
    //

    std::cout << "MAX VAL : " << max_value << std::endl;

    Simplexe< DIM , double> simplexe_englobant;

    bool ok = true;
    do {
        ok = true;
        for(unsigned int i(0) ; i < DIM; i++)
        {
            simplexe_englobant[i][i]    = max_value;
            simplexe_englobant[DIM][i] = -max_value;
        }

        for(unsigned int i(0) ; i < data.size(); i++)
            if( ! simplexe_englobant.contient(data[i]) )
            {
                ok = false;
                max_value++;
                max_value *= 10.0;
                break;
            }

    } while( !ok );

    simplexe_englobant.update_det();

    Pavage< DIM , double > pavage(simplexe_englobant);

    for(unsigned int i(0); i < data.size(); i++)
        pavage.inserer(data[i], false);

    //
    // menu interactif
    //

    bool terminer = false;
    std::string command;

    while(!terminer)
    {
        std::cout << "\n\033[1;35m[$]\033[00m ";

        std::getline(std::cin, command);
        if(command == "quit" ||
           command == "q") {
            terminer = true;
            continue;
        }

        if(command == "help" ||
           command == "h") {
            std::cout << "x;y;z;w insertion du point x;y;z;w , les coord non renseignées sont égale à 0 par défaut" << std::endl;
            std::cout << "Exemples : " << std::endl;
            std::cout << std::endl;
            std::cout << "Demande de la valeur d'un point à la position (128.0 ; 127.450 ; 800.250 )" << std::endl;
            std::cout << "[$] 128.0 ; 127.450 ; 800.250" << std::endl;
            std::cout << std::endl;
            std::cout << "q ou quit \t\t quitter" << std::endl;
            std::cout << "h ou help \t\t affiche ce message" << std::endl;
            std::cout << std::endl;
            continue;
        }

        std::istringstream iss(command);
        Point<DIM, double> curr;
        curr.set_value(0.0);
        unsigned int k = 0;

        try {
            while(std::getline(iss, token, ';'))
            {
                if(k >= DIM)
                    throw "trop d'arguments";

                curr[k] = std::stod(token);
                k++;
            }
        } catch (const std::exception& ex) {
            std::cerr << "\033[1;31m erreur: " << ex.what() << "\033[00m" << std::endl;
            continue;
        } catch (const char * er) {
            std::cerr << "\033[1;31m erreur: " << er << "\033[00m" << std::endl;
            continue;
        }

        curr.set_value(pavage.inserer(curr));
        std::cout << "\033[1;32m" << curr << "\033[00m" << std::endl;
    }

    std::cout << "Leaving Interpol." << std::endl;
}

int main(int argc, char** argv)
{
    po::variables_map vm;
    // Parsing command line
    po::options_description general_opt("Options : ");
    general_opt.add_options()
        ("help,h", "affiche ce message")
        ("dimension,d", po::value< unsigned int >()->default_value(2), "dimension (max 7, pour dimension supérieur il faut instancier dans le main et recompiler)")
        ("fichier,f", po::value< std::string >()->required(), "fichier d'entré");

    if(vm.count("help"))
    {
        std::cout << "Utilisation: " << argv[0] << " [OPTION] ... \n"
                  << "Outil d'interpolation par pavage\n"
                  << general_opt << "\n";
        return 0;
    }

    // Vérification de la validité des arguments
    bool parse_ok = true;

    try {
        po::store(po::parse_command_line(argc, argv, general_opt), vm);
    } catch(const std::exception& ex) {
        parse_ok = false;
        std::cerr << "Erreur dans les options du programme: " << ex.what() << std::endl;
    }

    try
    {
        po::notify(vm);
    } catch(const std::exception& ex) {
        std::cerr << "Erreur dans les options du programme: " << ex.what() << std::endl;
    }

    if( !parse_ok || vm.count("help") || argc <= 1 )
    {
        std::cerr << "Utilisation: " << argv[0] << " [OPTION] ... \n"
                  << "Outil d'interpolation par pavage\n"
                  << general_opt << "\n";
        return 0;
    }

    unsigned int dimension = vm["dimension"].as< unsigned int >();
    if( ! ( 2 <= dimension && dimension <= 7 ) )
    {
        std::cerr << "Dimension borné à 7, il faut ajouter plus de dimension dans le main et recompiler" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string filename = vm["fichier"].as< std::string >();

    switch(dimension) {
    case 2: do_stuff<2>(filename);
        break;
    case 3: do_stuff<3>(filename);
        break;
    case 4: do_stuff<4>(filename);
        break;
    case 5: do_stuff<5>(filename);
        break;
    case 6: do_stuff<6>(filename);
        break;
    case 7: do_stuff<7>(filename);
        break;
    }

    return 0;
}
