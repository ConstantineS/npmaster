#include "command.hpp"

int Command::AppendInput(std::string AppendixString){
	if(AppendixString.empty())
		return 1;
	input+=AppendixString;
	return 0;
}

std::string Command::getOutput(){
	return output;
}



