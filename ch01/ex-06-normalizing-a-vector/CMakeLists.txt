add_library(jvector-1-06 jvector.cpp)
add_executable(ex-06-normalizing-a-vector ex-06-normalizing-a-vector.cpp)
target_link_libraries(ex-06-normalizing-a-vector sfml-system sfml-window sfml-graphics jvector-1-06)
