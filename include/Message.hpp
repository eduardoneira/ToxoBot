
#ifndef TOXOBOT_MESSAGE_H
#define TOXOBOT_MESSAGE_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Message {
	private:
		string author;
		string command;
		string args;

		const char DELIMITER = ' ';
		const int FIELDS = 3;
		vector<string> split(const string &s, char delim, int max_items);

    public:
        Message(string raw_message);
        string getAuthor();
        string getCommand();
        string getArgs();
};

#endif //TOXOBOT_MESSAGE
