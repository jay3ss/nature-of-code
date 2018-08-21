add_library(jvector-2-05 jvector.hpp)
add_library(liquid-2-05 liquid.hpp)
add_library(mover-2-05 mover.hpp)
add_executable(ex-05-fluid-resistance ex-05-fluid-resistance.cpp)
set_target_properties(jvector-2-05 PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(liquid-2-05 PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(mover-2-05 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(
    ex-05-fluid-resistance
    sfml-system 
    sfml-window 
    sfml-graphics 
    jvector-2-05
    liquid-2-05
    mover-2-05)
