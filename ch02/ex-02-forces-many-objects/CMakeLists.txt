add_library(jvector-2-02 jvector.hpp)
add_library(mover-2-02 mover.hpp)
add_executable(ex-02-forces-many-objects ex-02-forces-many-objects.cpp)
set_target_properties(jvector-2-02 PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(mover-2-02 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(
    ex-02-forces-many-objects
    sfml-system 
    sfml-window 
    sfml-graphics 
    jvector-2-02
    mover-2-02)
