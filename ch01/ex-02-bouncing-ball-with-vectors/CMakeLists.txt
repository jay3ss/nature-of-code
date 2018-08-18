add_library(jvector-1-02 jvector.cpp)
add_executable(ex-02-bouncing-ball-with-vectors ex-02-bouncing-ball-with-vectors.cpp)
target_link_libraries(ex-02-bouncing-ball-with-vectors sfml-system sfml-window sfml-graphics jvector-1-02)
