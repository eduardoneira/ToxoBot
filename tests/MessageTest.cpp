#include "include/catch.hpp"
#include "../include/Message.hpp"

void assertMessage(Message message, string author, string command, string args) {
    REQUIRE(message.getAuthor() == author);
    REQUIRE(message.getCommand() == command);
    REQUIRE(message.getArgs() == args);
}

TEST_CASE("Create message test", "[MessageParser]") {
    Message message("@gabot futbol marangoni 14 hs");
    
    assertMessage(message,"@gabot","futbol","marangoni 14 hs");
}

TEST_CASE("Create message without args", "[MessageParser]") {
    Message message("@gabot futbol");

    assertMessage(message,"@gabot","futbol","");
}

