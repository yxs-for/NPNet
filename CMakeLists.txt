cmake_minimum_required(VERSION 3.0.0)
project(NPNet VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()
# include_directories(${PROJECT_SOURCE_DIR}/NPNet)
# add_subdirectory(NPNet)
include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(NPNet)


# #set CMAKE_BUILD_TYPE
# set( CMAKE_BUILD_TYPE Debug )
# # set output binary path  
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
##############################################
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
