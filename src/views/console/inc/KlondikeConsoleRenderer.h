/*
 * KlondikeConsoleRenderer.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_INC_KLONDIKECONSOLERENDERER_H_
#define SRC_INC_KLONDIKECONSOLERENDERER_H_

#include <Klondike.h>
#include <CardConsoleRenderer.h>

#include <memory>

class KlondikeConsoleRenderer: public KlondikeVisitor {
private:
    CardConsoleRenderer cardRenderer;
    std::shared_ptr<Klondike>& game;
    char foundationTag = FOUNDATION_BASE_TAG;
    char tableauPileTag = TABLEAU_PILE_BASE_TAG;
public:
    KlondikeConsoleRenderer(std::shared_ptr<Klondike>& g) : game(g) {};
    void render();
    void visitScore(int score);
    void visitStock(Stock* s);
    void visitFoundation(Foundation* f);
    void visitTableauPile(TableauPile* f);
    void allFoundationsVisited();
    void allTableauPilesVisited();
    static const char FOUNDATION_BASE_TAG = 'A';
    static const char TABLEAU_PILE_BASE_TAG = '1';
};

#endif /* SRC_INC_KLONDIKECONSOLERENDERER_H_ */
