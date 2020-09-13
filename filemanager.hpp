#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include "node.hpp"
#include <iostream>
#include <string>

class FileManager{
	private:
		Node* prev;
		Node* cur;
		Node* curDir;
		Node* root;
		void addNode(Node* newNode);
		Node* findNode(std::string name);
	public:
		FileManager();
		void ls();
		void mkdir(std::string name);
		void pwd();
		void addf(std::string name);
		void rm(std::string name);
		void mv(std::string fromName, std::string toName);
		void cd(std::string dirname);
		void cp(std::string name, std::string newName);
		void whereis(std::string);
};
#endif
