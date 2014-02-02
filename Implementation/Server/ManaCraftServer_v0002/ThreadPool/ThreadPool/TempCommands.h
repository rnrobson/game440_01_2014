#ifndef TEMPCOMMANDS_H
#define TEMPCOMMANDS_H

#include <iostream>
#include <string>

struct TempCommands
{
	private:
		// Command stuff/values
		std::string Description;
	
	public:
		TempCommands() {};
		~TempCommands() {};

		void SetDescription(std::string desc);
		void PrintDescription();
};

inline void TempCommands::SetDescription(std::string desc)
{
	this->Description = desc;
}

inline void TempCommands::PrintDescription()
{
	std::cout << this->Description;
}

#endif