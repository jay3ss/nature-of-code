add_library(jvector-1-10 jvector.hpp)
add_library(mover-1-10 mover.hpp)
add_executable(ex-10-accelerating-towards-mouse ex-10-accelerating-towards-mouse.cpp)
set_target_properties(jvector-1-10 PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(mover-1-10 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(
    ex-10-accelerating-towards-mouse
    sfml-system 
    sfml-window 
    sfml-graphics 
    jvector-1-10
    mover-1-10)
