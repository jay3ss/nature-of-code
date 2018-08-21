add_library(jvector-2-03 jvector.hpp)
add_library(mover-2-03 mover.hpp)
add_executable(ex-03-gravity-scaled-by-mass ex-03-gravity-scaled-by-mass.cpp)
set_target_properties(jvector-2-03 PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(mover-2-03 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(
    ex-03-gravity-scaled-by-mass
    sfml-system 
    sfml-window 
    sfml-graphics 
    jvector-2-03
    mover-2-03)
