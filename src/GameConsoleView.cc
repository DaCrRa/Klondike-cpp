/*
 * GameConsoleView.cpp
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#include "GameConsoleView.h"

#include <stdio.h>

GameConsoleView::GameConsoleView(Klondike* k) {
	k->configureRenderer(&renderer);
}

void GameConsoleView::interact(Controller* c) {
	renderer.render();
	getchar();
	c->operate();
}
