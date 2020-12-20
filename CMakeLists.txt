# CMakeList.txt : CMake project for MyCMakeProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("MyCMakeProject")

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Add source to this project's executable.
add_executable (MyCMakeProject "MyCMakeProject.cpp" "MyCMakeProject.h" "Object.h" "Object.cpp" "Character.h" "Character.cpp" "Animation.h" "Animation.cpp")

# TODO: Add tests and install targets if needed.
target_link_libraries(MyCMakeProject PRIVATE sfml-graphics)