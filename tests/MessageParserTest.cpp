#include "include/catch.hpp"
#include "../include/MessageParser.hpp"

TEST_CASE( "Simple Test", "[MessageParser]" ) {
    MessageParser* messageParser = new MessageParser("id");
    REQUIRE(messageParser->getId() == "id");
}