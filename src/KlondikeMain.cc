#include <iostream>
#include <string>
#include <memory>

#include <Klondike.h>
#include <ConsoleView.h>
#include <StartController.h>
#include <GameActionController.h>

int main(int argc, char* argv[]) {
	std::shared_ptr<Klondike> k;
	ConsoleView view;
	StartController startController(k);
	Controller* nextController = &startController;




	try {
		for (int i = 0; i < 20; ++i) {
			view.interact(nextController);
			if (k->isActive()) {
				nextController = startController.getSelectedGameActionController();
			} else {
				nextController = &startController;
			}
		}
	} catch (std::exception& e) {
		//TODO Do not capture here
		std::cout << e.what() << std::endl;
	}
}
