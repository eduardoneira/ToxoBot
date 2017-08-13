#include "../include/Message.hpp"

string Message::getAuthor() {
	return this->author;
}

string Message::getCommand() {
	return this->command;
}

string Message::getArgs() {
	return this->args;
}

vector<string> Message::split(const string &s, char delim, int max_items) {
    vector<string> result;    
    stringstream ss;    
    ss.str(s);
    string item;

    while (result.size() < max_items-1 && getline(ss, item, delim)) {
        result.push_back(item);
    }

    if (getline(ss,item)) {
        result.push_back(item);
    } else {
        result.push_back("");
    }

    return result;
}

Message::Message(const string raw_message) {
	vector<string> split_message = split(raw_message,DELIMITER,FIELDS);
    if (split_message.size() > 2) {
        this->author = split_message.at(0);
        this->command = split_message.at(1);
        this->args = split_message.at(2);
    }

}
