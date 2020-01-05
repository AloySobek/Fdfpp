cmake_minimum_required(VERSION 3.15.0)

project(fdfpp VERSION 0.2 DESCRIPTION "Fdf project, but with some steroids :)")

include_directories(include Firebreak/include)

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++14 -O3")
SET(GCC_COVERAGE_LINK_FLAGS "")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

file(GLOB SOURCES "source/*.cpp")

add_custom_target(Firebreak ALL COMMAND make WORKING_DIRECTORY Firebreak/build)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} /Users/vrichese/Workspace/Rus42/MyProjects/WanderingStar/Firebreak/build/libfirebreak.dylib)
target_link_libraries(${PROJECT_NAME} /Users/vrichese/Workspace/Rus42/MyProjects/WanderingStar/Porthole/libs/libglfw.3.3.dylib)
