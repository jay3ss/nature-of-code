add_library(jvector-1-11 jvector.hpp)
add_library(mover-1-11 mover.hpp)
add_executable(ex-11-array-of-movers ex-11-array-of-movers.cpp)
set_target_properties(jvector-1-11 PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(mover-1-11 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(
    ex-11-array-of-movers
    sfml-system 
    sfml-window 
    sfml-graphics 
    jvector-1-11
    mover-1-11)
