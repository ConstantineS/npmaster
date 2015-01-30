#ifndef H_COMM
#define H_COMM
#include <iostream>
#include <list>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

class Command {
private:
	std::string output;
	std::string input;
	std::vector<std::string> args;
	int pipe;
public:
	Command();
	int			AppendInput(std::string AppendixString);
	std::string getOutput(void);
	void		PushArgument(std::string Argument);
	void		SetPipe(int _pipe);
	friend std::ostream& operator<<(std::ostream &outs, const Command c){
		outs<<"output:<"<<c.output<<">\t"<<"input:<"<<c.input<<">\t"<<std::endl;
		outs<<"Args: ";
		for(std::vector<std::string>::const_iterator it=c.args.begin() ; it!=c.args.end() ; ++it)
			outs<<"["<<*it<<"] ";
		outs<<std::endl<<"Pipe: <"<<c.pipe<<">"<<std::endl;
		return outs;
	}
};

class CommandQ{
private:
	std::list<Command> CList;
public:
	CommandQ(std::string argument);
	Command pop();
	void 	push(Command c);
	bool 	empty();
	int		size();
	friend std::ostream &operator<<(std::ostream &output, const CommandQ &CQ){
		for(std::list<Command>::const_iterator it=CQ.CList.begin() ; it!=CQ.CList.end() ; ++it){
			output<<*it<<std::endl;
		}
		return output;
	}
};


#endif
