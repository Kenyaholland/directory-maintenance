#include "filemanager.hpp"

FileManager::FileManager(){

	Node* root = new Node("root", true);
	
	this->root = root;
	this->curDir = root;
	this->curDir->setParent(nullptr);
	this->cur = root;
	this->prev = nullptr;
}

void FileManager::mkdir(std::string name){
	
	Node* newDir = new Node(name, true);

	if(curDir->getChild() == nullptr){
		this->curDir->setChild(newDir);
		newDir->setParent(this->curDir);
		this->cur = newDir;
		this->prev = nullptr;
		std::cout << newDir->getName() << " directory created." << std::endl;
	}
	else if(curDir->getChild()->getName() != newDir->getName()){
		
		newDir->setParent(this->curDir);
		this->cur->setNextForD(newDir);
		this->prev = this->cur;
		this->cur = newDir;
		
		/*while(this->cur != nullptr && this->cur->getName() < newDir->getName()){
			this->prev = this->cur;
			this->cur = this->cur->getNextForD();
		}
		
		newDir->setNextForD(this->cur);
		this->prev->setNextForD(newDir);*/
		
		std::cout << newDir->getName() << " directory created." <<std::endl;
	}
	else{
		std::cout << newDir->getName() << " already exists" << std::endl;
	}
}

void FileManager::addf(std::string name){
        
	Node* newFile = new Node(name, false);

        if(curDir->getChild() == nullptr){
                this->curDir->setChild(newFile);
                newFile->setParent(this->curDir);
                
		this->cur = newFile;
		this->prev = nullptr;
                
		std::cout << newFile->getName() << " file created." << std::endl;
        }
        else if(curDir->getChild()->getName() != newFile->getName()){
                
		newFile->setParent(this->curDir);
                this->cur->setNextForD(newFile);
		this->prev = this->cur;
		this->cur = newFile;

		/*while(this->cur != nullptr && this->cur->getName() < newFile->getName()){
                        this->prev = this->cur;
                        this->cur = this->cur->getNextForD();
                }
                
		newFile->setNextForD(this->cur);
                this->prev->setNextForD(newFile);*/

                std::cout << newFile->getName() << " file created." <<std::endl;
        }
        else{
                std::cout << newFile->getName() << " already exists" << std::endl;
        }

}

void FileManager::pwd(){

	std::string workingDir = "";
	Node* tempNode = this->curDir;

	while(tempNode != nullptr){
		workingDir = "/" + tempNode->getName() + workingDir;
		tempNode = tempNode->getParent();
	}
	std::cout << "kenya" << workingDir << std::endl;
}

void FileManager::ls(){
	Node* tempNode = this->curDir->getChild();

	while(tempNode != nullptr){
		if(tempNode->getIsDir() == true){
			std::cout << "D " << tempNode->getName() << std::endl;
		}
		else{
			std::cout << "F " << tempNode->getName() << std::endl;
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
			return pwd();
		}
		else
		{
			std::cout <<  "can't change to directory " << this->root->getName() << std::endl;
		}
	}
	else{
		while(tempNode != nullptr){
			if(tempNode->getName() == dirName){
				this->curDir = tempNode;
				resetPointers();
				return pwd();
			}
			else{
				tempNode = tempNode->getNextForD();
			}
		}
	}
}

void FileManager::rm(std::string name){
	/*Node* tempNode = findNode(name);

	this->cur = tempNode->getNextForD();
	this->prev->setNextForD(this->cur);*/

	this->cur = this->cur->getChild();
	this->prev = nullptr;

	while(this->cur != nullptr){
		if(this->cur->getName() == name){
			this->cur = this->cur->getNextForD();
			this->prev->setNextForD(this->cur);
		}
		else{
			this->prev = this->cur;
			this->cur = this->cur->getNextForD();
		}
	}
	resetPointers();
}

void FileManager::mv(std::string fromName, std::string toName){
	Node* tempNode = this->curDir->getChild();
	
	while(tempNode != nullptr){
		if(tempNode->getName() == toName){
			std::cout << toName << " already exists in " << this->curDir->getName() << std::endl;
			return;
		}
		tempNode = tempNode->getNextForD();
	}
	
	findNode(fromName)->setName(toName);
}


Node* FileManager::findNode(std::string name){
	Node* tempNode;
	
	this->cur = this->curDir->getChild();
	this->prev = nullptr;

	while(this->cur->getName() != name && this->cur != nullptr){
		this->prev = this->cur;	
		this->cur = this->cur->getNextForD();
	}
	tempNode = this->cur;
	resetPointers();
	
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
