cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME FreePictureSplitter)
project(${PROJECT_NAME} VERSION 1.0.2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)

configure_file(include/version.h.in include/version.h)

include_directories(include)
add_executable(${PROJECT_NAME} src/FPSApp.cpp src/FPSMain.cpp src/SplitThread.cpp src/fpsSplit.cpp)
find_package(wxWidgets COMPONENTS core base html OPTIONAL_COMPONENTS adv xml xrc)
if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})
    target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
endif()
