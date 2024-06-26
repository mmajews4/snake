cmake_minimum_required(VERSION 3.26)
project(snake)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

# Windows specific config
# To możecie zmienić jeśli zainstalujecie SFML-a w innym miejscu
IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "C:/lib/SFML-2.5.1/lib/cmake/SFML")
    # Link sfml statically (Optional)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(snake
        main.cpp
        Array2D.h
        GameFont.cpp
        Button.cpp
        SnakeBoard.cpp
        Snake.cpp
        Controller.cpp
        MSSFMLView.cpp
        MSSFMLController.cpp
        MSSFMLMenuView.cpp
        MSSFMLMenuCtrl.cpp
        MSSFMLScoresView.cpp
        MSSFMLScoresCtrl.cpp)
target_link_libraries(snake sfml-graphics sfml-window sfml-system)