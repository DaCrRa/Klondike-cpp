/*
 * MoveCardView.cpp
 *
 *  Created on: 7 de may. de 2016
 *      Author: dancre
 */

#include <MoveCardView.h>

#include <ItemSelectionDialog.h>

MoveCardView::MoveCardView(GameActionController* c) :
    controller(c)
{
    std::shared_ptr<Klondike>& game = controller->getGame();
    gameElementTag.insert(std::pair<GameElement*, char>(game->getStock(), 's'));
    char foundationTag = 'A';
    for (std::vector<Foundation>::iterator it = game->getFoundations().begin() ; it != game->getFoundations().end() ; ++it) {
        gameElementTag.insert(std::pair<GameElement*, char>(it.base(), foundationTag++));
    }
    char tableauPileTag = '1';
    for (std::vector<TableauPile>::iterator it = game->getTableau().begin() ; it != game->getTableau().end() ; ++it) {
        gameElementTag.insert(std::pair<GameElement*, char>(it.base(), tableauPileTag++));
    }
}

void MoveCardView::completeMove(Move* move) {
    std::map<char, MoveOrigin*> taggedPossibleOrigins = tagPossibleOrigins();
    ItemSelectionDialog<MoveOrigin*> dialogFrom("Move from: ", taggedPossibleOrigins, 'c');
    MoveOrigin* origin = dialogFrom.getSelectedItem();
    std::map<char, MoveDest*> taggedPossibleDests = tagPossibleDests(origin);
    ItemSelectionDialog<MoveDest*> dialogTo("Move to: ", taggedPossibleDests, 'c');
    MoveDest* dest = dialogTo.getSelectedItem();
    move->setOrigin(origin);
    move->setDest(dest);
}

std::map<char, MoveOrigin*> MoveCardView::tagPossibleOrigins() {
    std::map<char, MoveOrigin*> possibleOrigins;
    std::vector<MoveOrigin*> availableOrigins = controller->getGame()->getPossibleMoveOrigins();
    for (std::vector<MoveOrigin*>::iterator it = availableOrigins.begin(); it != availableOrigins.end(); ++it) {
        possibleOrigins[gameElementTag[*it]] = *it;
    }
    return possibleOrigins;
}

std::map<char, MoveDest*> MoveCardView::tagPossibleDests(MoveOrigin* origin) {
    std::map<char, MoveDest*> possibleDests;
    std::vector<MoveDest*> availableDests = controller->getGame()->getPossibleMoveDests(origin);
    for (std::vector<MoveDest*>::iterator it = availableDests.begin(); it != availableDests.end(); ++it) {
        possibleDests[gameElementTag[*it]] = *it;
    }
    return possibleDests;
}
