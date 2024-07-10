cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME FreePictureSplitter)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)

find_package(wxWidgets COMPONENTS core base html OPTIONAL_COMPONENTS net adv xml)
   if(wxWidgets_FOUND)
        include(${wxWidgets_USE_FILE})
        # and for each of your dependent executable/library targets:
        target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
    endif()
include_directories(include)
add_executable(${PROJECT_NAME} src/FPSApp.cpp src/FPSMain.cpp src/SplitThread.cpp src/fpsSplit.cpp)
