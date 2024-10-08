# COPY FILE
configure_file(prog.qw prog.qw)
configure_file(lexerAux.cpp lexerAux.cpp)

# FLEX & BISON
find_package(BISON)
find_package(FLEX)
BISON_TARGET(Parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp) # Optional param: DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.hpp
FLEX_TARGET(Scanner lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

#message("CMAKE CURRENT SOURCE DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
#add_custom_command(
#    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp
#    COMMAND flex++ -o ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/lexer.l
#    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/lexer.l)
#add_custom_target(lexer DEPENDS lexer.cpp)

# set include directory for parsing files
include_directories(${CMAKE_CURRENT_BINARY_DIR})
message(${BISON_Parser_OUTPUTS})
message(${FLEX_Scanner_OUTPUTS})
message(${FLEX_LIBRARIES})
message(${FLEX_INCLUDE_DIRS})
add_library(
    Parser STATIC
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS}
)
target_link_libraries(Parser ${FLEX_LIBRARIES})
target_include_directories(Parser PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

add_executable(
    ParserRunner
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS})

target_include_directories(ParserRunner PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(ParserRunner PUBLIC ${FLEX_LIBRARIES})
