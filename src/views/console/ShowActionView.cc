/*
 * ShowActionView.cpp
 *
 *  Created on: 13 de may. de 2016
 *      Author: dancre
 */

#include <ShowActionView.h>
#include <UserSelectedMove.h>

#include <iostream>

ShowActionView::ShowActionView(GameActionPtr act) :
    action(act)
{

}

void ShowActionView::visit(ForwardGameAction* fwdGameAction) {
    fwdGameAction->accept(this);
}

void ShowActionView::visit(UndoGameAction* undoGameAction) {

}

void ShowActionView::visit(UserSelectedMove* userSelectedMove) {
    visit(userSelectedMove->getMove().get());
}

void ShowActionView::show() {
    std::cout << "Press enter for next move...";
    std::cin.get();
    std::cout << std::endl;
    action->acceptGameActionVisitor(this);
}

void ShowActionView::visit(StockAction* action) {
    std::cout << "Stock move!" << std::endl;
}

void ShowActionView::visit(Move* m) {
    std::cout << "Move card!" << std::endl;
}
