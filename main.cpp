#include <iostream>
#include "filemanager.hpp"
int main(){
	FileManager* fileSystem = new FileManager();

	fileSystem->addf("abc");
	fileSystem->mkdir("def");
	fileSystem->ls();
	fileSystem->cd("def");
	fileSystem->mkdir("123");
	fileSystem->addf("456");
	fileSystem->ls();

	return 0;	
}
