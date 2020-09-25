#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include "filemanager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Terminal{
	private:
		FileManager* fileSystem;
		std::string command;
		std::string mod1;
		std::string mod2;
		void runCommand();
	public:
		Terminal();
		void commandReadIn();
		
};
#endif
