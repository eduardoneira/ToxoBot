
#ifndef TOXOBOT_MESSAGEPARSER_H
#define TOXOBOT_MESSAGEPARSER_H

#include <string>
using namespace std;

class MessageParser {
	string id;

    public:
        MessageParser(string id);
        string getId();
};

#endif //TOXOBOT_MESSAGEPARSER_H
