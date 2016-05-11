cmake_minimum_required(VERSION 3.0)

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

# executable
add_executable(exec main)
target_link_libraries(exec interpol ${Boost_LIBRARIES})
set_target_properties(interpol PROPERTIES LINKER_LANGUAGE CXX)
