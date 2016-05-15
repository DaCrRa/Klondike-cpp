#include <iostream>
#include <string.h>

#include <Klondike.h>
#include <ConsoleView.h>
#include <UserGameActionController.h>
#include <RandomGameActionController.h>
#include <MainMenuView.h>

int main(int argc, char* argv[]) {
	Klondike k;
	ConsoleView view;
	MainMenuView menuView;

	try {

		std::shared_ptr<GameActionController> controller = menuView.getSelection(&k);

		k.initialize();

		for (int i = 0; i < 20; ++i) {
			view.interact(controller.get());
		}
	} catch (std::exception& e) {
		//TODO Do not capture here
		std::cout << e.what() << std::endl;
	}
}
