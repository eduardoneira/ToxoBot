cmake_minimum_required(VERSION 3.7)
project(ToxoBot)

set(CMAKE_CXX_STANDARD 11)

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)

set(MESSAGE_PARSER
        src/MessageParser.cpp
        include/MessageParser.hpp)

set(SOURCE_FILES main.cpp ${MESSAGE_PARSER})
add_executable(ToxoBot ${SOURCE_FILES})

#TESTS

set(TEST_SOURCES
        tests/MessageParserTest.cpp
        ${MESSAGE_PARSER})

add_executable(tests
                tests/include/main.cpp
                tests/include/catch.hpp
                ${TEST_SOURCES})

enable_testing()
add_test(NAME ToxoBotTests COMMAND tests)

