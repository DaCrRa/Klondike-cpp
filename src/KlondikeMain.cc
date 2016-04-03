#include <iostream>
#include <string.h>

#include <Klondike.h>

int main(int argc, char* argv[]) {
	Klondike k;
	std::cout << "initializing..." << std::endl;
	k.initialize();
	std::cout << "initialized!" << std::endl;
	std::string completedString = k.isCompleted() ? "game completed" : "game is NOT completed";
	std::cout << completedString << std::endl;
}
