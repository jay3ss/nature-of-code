add_library(jvector-1-07 jvector.hpp)
add_library(mover-1-07 mover.hpp)
add_executable(ex-07-motion-101 ex-07-motion-101.cpp)
set_target_properties(jvector-1-07 PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(mover-1-07 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(ex-07-motion-101 sfml-system sfml-window sfml-graphics jvector-1-07 mover-1-07)
