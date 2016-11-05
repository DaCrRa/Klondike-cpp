/*
 * ShowActionView.cpp
 *
 *  Created on: 13 de may. de 2016
 *      Author: dancre
 */

#include <ShowActionView.h>
#include <PressEnterToContinue.h>

#include <iostream>

ShowActionView::ShowActionView(ForwardGameActionPtr act) :
    action(act)
{

}

void ShowActionView::show() {
    PressEnterToContinue("Press enter for next move...").waitForEnter();
    std::cout << std::endl;
    action->accept(this);
}

void ShowActionView::visit(StockAction* action) {
    std::cout << "Stock move!" << std::endl;
}

void ShowActionView::visit(Move* m) {
    std::cout << "Move card!" << std::endl;
}
