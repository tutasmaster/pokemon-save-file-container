# CMakeList.txt : CMake project for CMakeProject2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# Add source to this project's executable.
add_executable (PokemonSave "PokemonSave.cpp")
add_executable (wxPokemonSave WIN32 "wxPokemon.cpp")
target_link_libraries(wxPokemonSave ${wxWidgets_LIBRARIES})
# TODO: Add tests and install targets if needed.
