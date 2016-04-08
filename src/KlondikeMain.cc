#include <iostream>
#include <string.h>

#include <Klondike.h>
#include <GameConsoleView.h>
#include <StockController.h>

int main(int argc, char* argv[]) {
	Klondike k;
	GameConsoleView view(&k);
	StockController controller(k.getStock());

	k.initialize();

	while (true) {
		view.interact(&controller);
	}
}
