add_library(jvector-1-04 jvector.cpp)
add_executable(ex-04-multiplying-a-vector ex-04-multiplying-a-vector.cpp)
target_link_libraries(ex-04-multiplying-a-vector sfml-system sfml-window sfml-graphics jvector-1-04)
