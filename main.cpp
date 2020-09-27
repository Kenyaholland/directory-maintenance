#include <iostream>
#include "terminal.hpp"

int main(){
	Terminal* terminal = new Terminal();
	
	terminal->commandReadIn();

	return 0;	
}
