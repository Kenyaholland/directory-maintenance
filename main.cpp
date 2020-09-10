#include <iostream>
#include "node.hpp"

int main(){
	Node* newNode = new Node("Kenya", true);
	
	std::cout << newNode->getName() << " " << newNode->getIsDir() << std::endl;

	return 0;	
}
