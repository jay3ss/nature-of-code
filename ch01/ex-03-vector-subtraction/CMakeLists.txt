add_library(jvector-1-03 jvector.cpp)
add_executable(ex-03-vector-subtraction ex-03-vector-subtraction.cpp)
target_link_libraries(ex-03-vector-subtraction sfml-system sfml-window sfml-graphics jvector-1-03)
