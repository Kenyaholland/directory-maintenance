#include "node.hpp"

Node::Node(){
	this->name = "";
	this->child = nullptr;
	this->nextForD = nullptr;
	this->parent = nullptr;
}

Node::Node(std::string nodeName, bool isDirectory){
	this->name = nodeName;
	this->isDirectory = isDirectory;
	this->child = nullptr;
	this->nextForD = nullptr;
	this->parent = nullptr;
}

void Node::setChild(Node* child, bool isDir)
{
	this->child = child;
	this->isDirectory = isDir;
}

void Node::removeChild(){
	this->child = nullptr;
}

void Node::setName(std::string nodeName){
	this->name = nodeName;
}

void Node::setParent(Node* parent){
	this->parent = parent;
}

void Node::setNextForD(Node* nextNode){
	this->nextForD = nextNode;
}

Node* Node::getParent(){
	return this->parent;
}

Node* Node::getChild(){
	return this->child;
}

Node* Node::getNextForD(){
	return this->nextForD;
}

std::string Node::getName(){
	return this->name;
}

bool Node::getIsDir(){
	return this->isDirectory;
}
