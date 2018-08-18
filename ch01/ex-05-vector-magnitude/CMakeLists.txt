add_library(jvector-1-05 jvector.cpp)
add_executable(ex-05-vector-magnitude ex-05-vector-magnitude.cpp)
target_link_libraries(ex-05-vector-magnitude sfml-system sfml-window sfml-graphics jvector-1-05)
