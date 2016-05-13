cmake_minimum_required(VERSION 3.0)

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(ColourBold  "${Esc}[1m")
  set(Red         "${Esc}[31m")
  set(Green       "${Esc}[32m")
  set(Yellow      "${Esc}[33m")
  set(Blue        "${Esc}[34m")
  set(Magenta     "${Esc}[35m")
  set(Cyan        "${Esc}[36m")
  set(White       "${Esc}[37m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldGreen   "${Esc}[1;32m")
  set(BoldYellow  "${Esc}[1;33m")
  set(BoldBlue    "${Esc}[1;34m")
  set(BoldMagenta "${Esc}[1;35m")
  set(BoldCyan    "${Esc}[1;36m")
  set(BoldWhite   "${Esc}[1;37m")
endif()

# ${list_src} contiendra toutes les .cpp du repertoire courant ( src/ )
file(GLOB_RECURSE list_src
  "*.cpp"
  "*.hpp"
  )

# on enlève main.cpp contenu dans ${list_src}
file(GLOB to_remove main.cpp)
list(REMOVE_ITEM list_src ${to_remove})

# librairie
add_library(interpol ${list_src})
set_target_properties(interpol PROPERTIES LINKER_LANGUAGE CXX)

# --[ Recherche des packages
add_definitions(-DBOOST_LOG_DYN_LINK)
find_package( Boost 1.40 QUIET COMPONENTS program_options REQUIRED )
if(${Boost_PROGRAM_OPTIONS_FOUND})
  message(STATUS "${BoldGreen}[OK] composant boost_program_options${ColourReset}")
else()
  message(FATAL_ERROR "${BoldRed}[KO] composant boost_program_options\n\t-> package à installer: installe le paquet ${BoldGreen}libboost-program-options${BoldRed} avec X >= 1.40 (cf README du dépôt)${ColourReset}")
endif()

include_directories( ${Boost_INCLUDE_DIR} )
target_link_libraries(interpol ${Boost_LIBRARIES} )

# executable
add_executable(exec main)
target_link_libraries(exec interpol ${Boost_LIBRARIES})
set_target_properties(interpol PROPERTIES LINKER_LANGUAGE CXX)
