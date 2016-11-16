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
    virtual void renderCard(const Card* c) = 0;
    virtual void visitRank(int rank) const = 0;
    virtual void visitSuit(int suit) const = 0;
    virtual ~CardConsoleRenderer() {}
};

#endif
