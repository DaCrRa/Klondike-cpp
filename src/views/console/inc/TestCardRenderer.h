/*
 * TestCardRenderer.h
 *
 *  Created on: 15 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_INC_TESTCARDRENDERER_H_
#define SRC_VIEWS_CONSOLE_INC_TESTCARDRENDERER_H_

#include <CardConsoleRenderer.h>

class TestCardRenderer : public CardConsoleRenderer {
public:
    void renderCard(const Card* c);
    void visitRank(int rank) const;
    void visitSuit(int suit) const;
};

#endif /* SRC_VIEWS_CONSOLE_INC_TESTCARDRENDERER_H_ */
