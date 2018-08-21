add_library(jvector-2-04 jvector.hpp)
add_library(mover-2-04 mover.hpp)
add_executable(ex-04-including-friction ex-04-including-friction.cpp)
set_target_properties(jvector-2-04 PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(mover-2-04 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(
    ex-04-including-friction
    sfml-system 
    sfml-window 
    sfml-graphics 
    jvector-2-04
    mover-2-04)
