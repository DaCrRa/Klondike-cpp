#include <iostream>
#include <string.h>

#include <Klondike.h>
#include <GameConsoleView.h>
#include <GameActionController.h>

int main(int argc, char* argv[]) {
	Klondike k;
	GameConsoleView view(&k);
	GameActionController controller(&k);

	k.initialize();

	while (true) {
		view.interact(&controller);
	}
}
