cmake_minimum_required(VERSION 3.0)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(TEST_LIST
  test_determinant
  )

foreach(FILE ${TEST_LIST})
  add_executable(test_determinant test_determinant)
  target_link_libraries(test_determinant interpol)
  add_test(test_determinant test_determinant)
endforeach(FILE)
