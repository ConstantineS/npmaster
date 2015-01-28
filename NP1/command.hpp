#ifndef H_COMM
#define H_COMM
#include <iostream>
#include <queue>
#include <boost/tokenizer.hpp>

class Command {
private:
	std::string output;
	std::string input;
	std::string command;
	int pipe;
public:
	int AppendInput(std::string AppendixString);
	std::string getOutput(void);
};
template <typename type>
class CommandQ : public std::queue<type>{
public:
	int currentIndex;
	CommandQ(std::string argument);
};

template <typename type>
CommandQ<type>::CommandQ(std::string argument){
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	boost::char_separator<char> sep("|", "|%d", boost::keep_empty_tokens);
	tokenizer tokens(argument, sep);
	for(tokenizer::iterator tok_iter = tokens.begin() ;
		tok_iter!=tokens.end() ;
		++tok_iter)
			std::cout<< "<" << *tok_iter << "> ";
	std::cout<<std::endl;
}

#endif
