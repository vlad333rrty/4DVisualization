cmake_minimum_required(VERSION 3.17)
project(4DVisualization)

set(CMAKE_CXX_STANDARD 17)

add_executable(4DVisualization main.cpp shapes/Tesseract.h gui/Window.cpp modules/Window.h core/Tesseract.cpp modules/AbstractRegularShape.h io/Input.h io/Input.cpp core/Pentachoron.cpp shapes/Pentachoron.h transforms/TransformationUtils.h transforms/TransformationUtils.cpp Application.cpp modules/Application.h core/AbstractRegularShape.cpp shapes/SixteenCell.h core/SixteenCell.cpp modules/TransformationManager.h transforms/TransformationManager.cpp config/Config.h shapes/TwentyFourCell.h core/TwentyFourCell.cpp debug/DebugUtils.h debug/DebugUtils.cpp shapes/OneHundredAndTwentyCell.h core/OneHundredAndTwentyCell.cpp shapes/SixHundredCell.h core/SixHundredCell.cpp io/FileReadUtils.h io/FileReadUtils.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED )

include_directories(${OPENGL_INCLUDE_DIRS}  ${GLFW_INCLUDE_DIRS})
target_link_libraries(4DVisualization GL glfw ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})