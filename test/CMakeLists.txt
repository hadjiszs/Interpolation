cmake_minimum_required(VERSION 3.0)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/test)

file(GLOB list_unit_test
  "*.cpp"
  )

foreach(FILE ${list_unit_test})
  # recupere le chemin de fichier sans l'extension
  get_filename_component(FILE_WE ${FILE} NAME_WE)

  message(STATUS "${FILE_WE}")

  add_executable(${FILE_WE} ${FILE})
  target_link_libraries (${FILE_WE} interpol)
  add_test(${FILE_WE} ${FILE_WE})
endforeach(FILE)
