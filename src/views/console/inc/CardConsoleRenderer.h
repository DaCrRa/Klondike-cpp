/*
 * CardConsoleRenderer.h
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_CARDCONSOLERENDERER_H_
#define SRC_CARDCONSOLERENDERER_H_

#include <Card.h>

class CardConsoleRenderer : public CardVisitor {
public:
    void renderCard(const Card* c);
    void visitRank(int rank) const;
    void visitSuit(int suit) const;
};

#endif
