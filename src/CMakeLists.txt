cmake_minimum_required(VERSION 3.0)

add_library(interpol simplexe matrice pavage point)
set_target_properties(interpol PROPERTIES LINKER_LANGUAGE CXX)
