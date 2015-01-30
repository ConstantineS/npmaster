#include "command.hpp"


Command::Command(){
	pipe = 0;
}

void Command::SetPipe(int _pipe){
	pipe=_pipe;
}
int Command::AppendInput(std::string AppendixString){
	if(AppendixString.empty())
		return 1;
	input+=AppendixString;
	return 0;
}

std::string Command::getOutput(){
	return output;
}

void Command::PushArgument(std::string Argument){
	args.push_back(Argument);
}


CommandQ::CommandQ(std::string Argument){
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	boost::char_separator<char> sep(" ", "", boost::keep_empty_tokens);
	tokenizer tokens(Argument, sep);
	Command* tmp = new Command();
	for(tokenizer::iterator tok_iter = tokens.begin() ;
		tok_iter!=tokens.end() ;
		++tok_iter){
			std::string s = *tok_iter;
			if(s[0]!='|'){
				tmp->PushArgument(s);
			}
			else{
				if(s.size()>1)
					tmp->SetPipe(boost::lexical_cast<int>(s[1]));
				this->push(*tmp);
				delete tmp;
				tmp = new Command();
			}
			std::cout<< "<" << s << "> ";
	}
	std::cout<<std::endl;
}

void CommandQ::push(Command c){
	CList.push_back(c);
}

Command CommandQ::pop(){
	Command tmp = CList.front();
	CList.pop_back();
	return tmp;
}

bool CommandQ::empty(){
	return CList.empty();
}

int CommandQ::size(){
	return CList.size();
}




