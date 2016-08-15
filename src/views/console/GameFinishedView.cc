/*
 * GameFinishedView.cc
 *
 *  Created on: 15 de ago. de 2016
 *      Author: dancre
 */

#include <GameFinishedView.h>

#include <iostream>

void GameFinishedView::show() {
    renderer.render();
    std::cout << std::endl;
    std::cout << "Game completed!!" << std::endl;
    std::cout << std::endl;
    std::cout << "Press enter to continue...";
    std::cin.get();
    std::cin.get();
    std::cout << std::endl;
    game.reset();
}
