# building mqt-core as a part of project
add_subdirectory(
    "${PROJECT_SOURCE_DIR}/extern/mqt-core"
    "extern/mqt-core"
    EXCLUDE_FROM_ALL)

add_library(
    ${PROJECT_NAME}
    main.cpp
    getch.cpp
    Person.cpp)

# set include directories
include_directories(
    ${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}/include)

# link to the MQT::Core libararies
target_link_libraries(${PROJECT_NAME} PUBLIC MQT::CoreDD MQT::CoreZX Parser)

add_subdirectory(parser)