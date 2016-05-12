#include <iostream>
#include <string.h>

#include <Klondike.h>
#include <GameConsoleView.h>
#include <UserGameActionController.h>

int main(int argc, char* argv[]) {
	Klondike k;
	GameConsoleView view(&k);
	UserGameActionController controller(&k);

	k.initialize();

	while (true) {
		view.interact(&controller);
	}
}
