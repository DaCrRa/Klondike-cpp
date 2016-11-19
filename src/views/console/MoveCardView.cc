/*
 * MoveCardView.cpp
 *
 *  Created on: 7 de may. de 2016
 *      Author: dancre
 */

#include <MoveCardView.h>

#include <ItemSelectionDialog.h>
#include <LimitedIntDialog.h>
#include <MoveFromStock.h>
#include <MoveFromTableauPile.h>
#include <MoveFromFoundation.h>
#include <KlondikeConsoleRenderer.h>

MoveCardView::MoveCardView(UserGameActionController* c) :
    controller(c)
{
    char foundationTag = KlondikeConsoleRenderer::FOUNDATION_BASE_TAG;
    char tableauPileTag = KlondikeConsoleRenderer::TABLEAU_PILE_BASE_TAG;

    KlondikeLambdaVisitor gameElementTagger;

    gameElementTagger.setVisitStockFunction([&](Stock* s)->void{
        gameElementTag.insert(std::pair<GameElement*, char>(s, 's'));
    }).setVisitFoundationFunction([&](Foundation* f)->void{
        gameElementTag.insert(std::pair<GameElement*, char>(f, foundationTag++));
    }).setVisitTableauPileFunction([&](TableauPile* tp)->void{
        gameElementTag.insert(std::pair<GameElement*, char>(tp, tableauPileTag++));
    });

    controller->getGame()->accept(&gameElementTagger);
}

void MoveCardView::completeMove(UserSelectedMove* userSelectedMove) {
    std::map<char, MoveOrigin*> taggedPossibleOrigins = tagPossibleOrigins();
    ItemSelectionDialog<MoveOrigin*> dialogFrom("Move from: ", taggedPossibleOrigins, 'c');
    MoveOrigin* origin = dialogFrom.getSelectedItem();
    origin->accept(this);
    std::map<char, MoveDest*> taggedPossibleDests = tagPossibleDests(origin, move->getNumberOfCards());
    ItemSelectionDialog<MoveDest*> dialogTo("Move to: ", taggedPossibleDests, 'c');
    MoveDest* dest = dialogTo.getSelectedItem();
    move->setDest(dest);
    userSelectedMove->setMove(move);
}

void MoveCardView::visit(Stock* s) {
    move = MovePtr(new MoveFromStock(s));
}

void MoveCardView::visit(Foundation* f) {
    move = MovePtr(new MoveFromFoundation(f));
}

void MoveCardView::visit(TableauPile* tp) {
    std::shared_ptr<MoveFromTableauPile> moveFromTableauPile(new MoveFromTableauPile(tp));
    if (tp->getNumCardsAvailableToMove() > 1) {
        LimitedInputDialog numCardsDialog("Number of cards:", 0, tp->getNumCardsAvailableToMove());
        int numberOfCards = numCardsDialog.getUserInput();
        moveFromTableauPile->setNumberOfCards(numberOfCards);
    }
    move = moveFromTableauPile;
}

std::map<char, MoveOrigin*> MoveCardView::tagPossibleOrigins() {
    std::map<char, MoveOrigin*> possibleOrigins;
    std::vector<MoveOrigin*> availableOrigins = controller->getPossibleMoveOrigins();
    for (std::vector<MoveOrigin*>::iterator it = availableOrigins.begin(); it != availableOrigins.end(); ++it) {
        possibleOrigins[gameElementTag[*it]] = *it;
    }
    return possibleOrigins;
}

std::map<char, MoveDest*> MoveCardView::tagPossibleDests(MoveOrigin* origin, int numberOfCards) {
    std::map<char, MoveDest*> possibleDests;
    std::vector<MoveDest*> availableDests = controller->getPossibleMoveDests(origin, numberOfCards);
    for (std::vector<MoveDest*>::iterator it = availableDests.begin(); it != availableDests.end(); ++it) {
        possibleDests[gameElementTag[*it]] = *it;
    }
    return possibleDests;
}
