cmake_minimum_required(VERSION 3.10)
project(mutils VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Probably will tinker with it in the future
# file(GLOB MUTILS_SRC "src/*.cpp")
# file(GLOB MUTILS_HEADERS "src/include/*.h")

add_library(mutils STATIC 
  src/mutils-fhandler.cpp
  src/mutils-logger.cpp
)

target_include_directories(mutils PUBLIC ${CMAKE_SOURCE_DIR}/src/include)

install(TARGETS mutils
    ARCHIVE DESTINATION /usr/local/lib
)

install(DIRECTORY src/include/
    DESTINATION /usr/local/include/Mutils
)