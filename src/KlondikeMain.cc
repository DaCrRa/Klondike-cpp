#include <iostream>
#include <string.h>

#include <Klondike.h>
#include <GameConsoleView.h>
#include <UserGameActionController.h>
#include <RandomGameActionController.h>
#include <ItemSelectionDialog.h>
#include <Menu.h>
#include <MainMenuView.h>

int main(int argc, char* argv[]) {
	Klondike k;
	GameConsoleView view(&k);
	MainMenuView menuView;

	try {

		std::shared_ptr<GameActionController> controller = menuView.getSelection(&k);

		k.initialize();

		for (int i = 0; i < 20; ++i) {
			view.interact(controller.get());
		}
	} catch (CancelledDialogException& e) {
		std::cout << e.what() << std::endl;
	}
}
