#include "terminal.hpp"

Terminal::Terminal(){
	this->command = "";
	this->mod1 = "";
	this->mod2 = "";

	this->fileSystem = new FileManager();

	commandReadIn();
}

void Terminal::commandReadIn(){
	std::string tempCommand;
	std::ifstream commandFile("commands.txt");
	std::stringstream ss;

	if(commandFile.is_open()){
		while(std::getline(commandFile, tempCommand)){

			ss.clear();
			this->command = "";
			this->mod1 = "";
			this->mod2 = "";

			ss << tempCommand;
			ss >> this->command;
			ss >> this->mod1;
			ss >> this->mod2;
		
			std::cout << "$ " << this->command << " " << this->mod1 << " " << this->mod2 << std::endl;

			runCommand();
		}
	}
}

void Terminal::runCommand(){
	if(command == "mkdir"){
		this->fileSystem->mkdir(mod1);
	}
	if(command == "addf"){
		this->fileSystem->addf(mod1);
	}
	if(command == "pwd"){
		this->fileSystem->pwd();
	}
	if(command == "ls"){
		this->fileSystem->ls();
	}
	if(command == "rm"){
		this->fileSystem->rm(mod1);
	}
	if(command == "mv"){
		this->fileSystem->mv(mod1, mod2);
	}
	if(command == "cd"){
		this->fileSystem->cd(mod1);
	}
	if(command == "whereis"){
		this->fileSystem->whereis(mod1);
	}		
	if(command == "bye"){	
		std::cout << "bye!" << std::endl;
		return;
	}
}
