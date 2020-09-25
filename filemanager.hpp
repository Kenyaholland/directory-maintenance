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
		void resetPointers();
	public:
		FileManager();
		void ls();
		void mkdir(std::string name);
		void pwd();
		void addf(std::string name);
		void rm(std::string name);
		void mv(std::string fromName, std::string toName);
		void cd(std::string dirname);
		void whereis(std::string);
};
#endif
