#include <iostream>
#include <string.h>

#include <Klondike.h>
#include <KlondikeConsoleRenderer.h>

int main(int argc, char* argv[]) {
	KlondikeConsoleRenderer renderer;
	Klondike k;
	k.configureRenderer(&renderer);
	renderer.render();
	std::cout << "initializing..." << std::endl;
	k.initialize();
	std::cout << "initialized!" << std::endl;
	std::string completedString = k.isCompleted() ? "game completed" : "game is NOT completed";
	std::cout << completedString << std::endl;
	renderer.render();
}
