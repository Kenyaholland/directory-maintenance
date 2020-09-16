#include <iostream>
#include "filemanager.hpp"
int main(){
	FileManager* fileSystem = new FileManager();

	fileSystem->ls();
	fileSystem->pwd();
	fileSystem->mkdir("adir");
	fileSystem->ls();
	fileSystem->cd("adir");
	fileSystem->addf("f1");
	fileSystem->addf("f3");
	fileSystem->addf("f4");
	fileSystem->addf("f2");
	fileSystem->ls();
	fileSystem->mkdir("d1");
	fileSystem->cd("d1");
	fileSystem->addf("f3");
	fileSystem->addf("f2");
	fileSystem->ls();
	//fileSystem->mv("f3", "f2");
	//fileSystem->mv("f3", "f4");
	//fileSystem->ls();
	fileSystem->cd("..");
	fileSystem->rm("f3");
	fileSystem->ls();

	return 0;	
}
