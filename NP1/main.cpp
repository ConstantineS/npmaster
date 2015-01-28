#include <iostream>
#include "command.hpp"

int main(){
	std::string s("removetag0 test.html |3 removetag test.html | number |1 number");
	Command c;
	CommandQ<int> myQ(s);
	return 0;
}
