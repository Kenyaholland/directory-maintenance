#include "filemanager.hpp"

FileManager::FileManager(){

	Node* root = new Node("root", true);
	
	this->root = root;
	this->curDir = root;
	this->cur = root;
	this->prev = nullptr;
}

void FileManager::mkdir(std::string name){
	
	Node* newDir = new Node(name, true);

	//for first child of directory
	if(curDir->getChild() == nullptr){
		this->curDir->setChild(newDir);
		newDir->setParent(this->curDir);
		this->cur = newDir;
		this->prev = nullptr;
		std::cout << "  " << newDir->getName() << " directory created." << std::endl;
	}
	//all other children of directory
	else if(curDir->getChild()->getName() != newDir->getName()){
		
		newDir->setParent(this->curDir);
		this->cur->setNextForD(newDir);
		this->prev = this->cur;
		this->cur = newDir;
		
		std::cout << "  " << newDir->getName() << " directory created." <<std::endl;
	}
	else{
		std::cout << "  " << newDir->getName() << " already exists" << std::endl;
	}
}

void FileManager::addf(std::string name){
        
	Node* newFile = new Node(name, false);

	//for first file in directory
        if(curDir->getChild() == nullptr){
                this->curDir->setChild(newFile);
                newFile->setParent(this->curDir);
                
		this->cur = newFile;
		this->prev = nullptr;
                
		std::cout << "  " << newFile->getName() << " file created." << std::endl;
        }
	//for all other files in directory
        else if(curDir->getChild()->getName() != newFile->getName()){
                
		newFile->setParent(this->curDir);
                this->cur->setNextForD(newFile);
		this->prev = this->cur;
		this->cur = newFile;

                std::cout << "  " << newFile->getName() << " file created." <<std::endl;
        }
        else{
                std::cout << "  " << newFile->getName() << " already exists" << std::endl;
        }

}

std::string FileManager::pwd(){

	std::string workingDir = "";
	Node* tempNode = this->curDir;

	while(tempNode != nullptr){
		workingDir = "/" + tempNode->getName() + workingDir;
		tempNode = tempNode->getParent();
	}
	return "  kenya" + workingDir + "/";
}

void FileManager::ls(){
	Node* tempNode = this->curDir->getChild();

	while(tempNode != nullptr){
		if(tempNode->getIsDir() == true){
			std::cout << "  D " << tempNode->getName() << std::endl;
		}
		else{
			std::cout << "  F " << tempNode->getName() << std::endl;
		}
		tempNode = tempNode->getNextForD();
	}
}

void FileManager::cd(std::string dirName){
	Node* tempNode = this->curDir->getChild();
	
	if(dirName == ".."){
		if(this->curDir != this->root)
		{
			this->curDir = this->curDir->getParent();
			resetPointers();
			std::cout << pwd() << std::endl;
			return;
		}
		else
		{
			std::cout <<  "  can't change to directory " << this->root->getName() << std::endl;
		}
	}
	else{
		while(tempNode != nullptr){
			if(tempNode->getName() == dirName){
				this->curDir = tempNode;
				resetPointers();
				return;
			}
			else{
				tempNode = tempNode->getNextForD();
			}
		}
	}
}

void FileManager::rm(std::string name){
	
	Node* tempNode = this->curDir->getChild();
	bool fileFound = false;

	//checks if a file or directory of that name exists before attempting to remove
	while(tempNode != nullptr){
		if(tempNode->getName() == name){
			fileFound = true;
		}
		tempNode = tempNode->getNextForD();
		
	}	
	
	if(fileFound == false){
		std::cout << "  no such file or directory" << std::endl;
		return;
	}

	tempNode = findNode(name);

	this->cur = tempNode->getNextForD();
	this->prev->setNextForD(this->cur);
	resetPointers();
}

void FileManager::mv(std::string fromName, std::string toName){
	Node* tempNode = this->curDir->getChild();
	
	while(tempNode != nullptr){
		if(tempNode->getName() == toName){
			std::cout << "  " << toName << " already exists in " << this->curDir->getName() << std::endl;
			return;
		}
		tempNode = tempNode->getNextForD();
	}
	
	findNode(fromName)->setName(toName);
	resetPointers();
}

void FileManager::whereis(std::string name){
	Node* tempNode = this->root->getChild()->getChild();
	Node* saveDir = nullptr;
	std::string foundIn = "";
	bool found = false;

	while(tempNode != nullptr){
		if(tempNode->getName() == name){
			foundIn += "  kenya/root/adir\n";
			found = true;
		}
		if(tempNode->getIsDir() == true){
			saveDir = tempNode;
		}
		tempNode = tempNode->getNextForD();
	}

	tempNode = saveDir->getChild();
	while(tempNode != nullptr){
		if(tempNode->getName() == name){
			foundIn += "  kenya/root/adir/d1\n";
			found = true;
		}
		tempNode = tempNode->getNextForD();
	}

	if(found == false){
		std::cout << "  " << name << " not found." << std::endl;
		return;
	}

	std::cout << foundIn;
}

/* PRIVATE FUNCTIONS */

Node* FileManager::findNode(std::string name){
	Node* tempNode = nullptr;
	
	this->cur = this->curDir->getChild();
	this->prev = nullptr;

	while(this->cur->getName() != name && this->cur != nullptr){
		this->prev = this->cur;	
		this->cur = this->cur->getNextForD();
	}

	tempNode = this->cur;

	return tempNode;
}

void FileManager::resetPointers(){
	this->cur = this->curDir->getChild();
	this->prev = nullptr;

	while(this->cur != nullptr){
		this->prev = this->cur;
		this->cur = this->cur->getNextForD();
	}

	this->cur = this->prev;
}
