#include <iostream>
#include <string.h>

#include <Klondike.h>
#include <GameConsoleView.h>
#include <UserGameActionController.h>
#include <RandomGameActionController.h>
#include <ItemSelectionDialog.h>
#include <Menu.h>

int main(int argc, char* argv[]) {
	Klondike k;
	GameConsoleView view(&k);
	GameActionController* controller;

	UserGameActionController userController(&k);
	RandomGameActionController randomController(&k);

	Menu<GameActionController*> m("Options:", std::vector<std::pair<MenuOption, GameActionController*> >({
		{ MenuOption("Start one-player klondike", 0), &userController },
		{ MenuOption("Demo", 0), &randomController }
	}));
	controller = m.getUserSelection();

	try {

		k.initialize();

		for (int i = 0; i < 20; ++i) {
			view.interact(controller);
		}
	} catch (CancelledDialogException& e) {
		std::cout << e.what() << std::endl;
	}
}
