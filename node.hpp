#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <string>

class Node{
	private:
		bool isDirectory;
		std::string name;
		Node* child;
		Node* nextForD;
		Node* parent;
	public:
		Node(std::string nodeName, bool isDirectory);
		Node();
		void addNextForD(Node* nextChild);
		void setChild(Node* child, bool isDir);
		void removeChild();
		void setName(std::string nodeName);
		void setParent(Node* parent);
		void setNextForD(Node* nextNode);
		Node* getChild();
		Node* getNextForD();
		Node* getParent();
		std::string getName();
		bool getIsDir();
		
};
#endif
