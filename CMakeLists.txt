cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME FreePictureSplitter)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)

find_package(wxWidgets COMPONENTS core base html OPTIONAL_COMPONENTS net adv xml)
add_executable(${PROJECT_NAME} src/FPSApp.cpp src/FPSMain.cpp src/SplitThread.cpp src/fpsSplit.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE
                      wx::core wx::base wx::html)
