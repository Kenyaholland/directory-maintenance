#include <iostream>
#include "filemanager.hpp"
int main(){
	FileManager* fileSystem = new FileManager();

	fileSystem->addf("abc");
	fileSystem->mkdir("def");
	fileSystem->ls();
	fileSystem->cd("def");
	fileSystem->cd("..");
	fileSystem->cd("..");

	return 0;	
}
