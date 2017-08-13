#include "../include/MessageParser.hpp"

MessageParser::MessageParser(string id) {
    this->id = id;
}

string MessageParser::getId() {
    return this->id;
}