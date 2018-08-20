add_library(jvector-2-01 jvector.hpp)
add_library(mover-2-01 mover.hpp)
add_executable(ex-01-forces ex-01-forces.cpp)
set_target_properties(jvector-2-01 PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(mover-2-01 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(
    ex-01-forces
    sfml-system 
    sfml-window 
    sfml-graphics 
    jvector-2-01
    mover-2-01)
