/*
 * SpanishCardRenderer.h
 *
 *  Created on: 15 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_INC_SPANISHCARDRENDERER_H_
#define SRC_VIEWS_CONSOLE_INC_SPANISHCARDRENDERER_H_

#include <CardConsoleRenderer.h>

#include <vector>
#include <string>

class SpanishCardRenderer: public CardConsoleRenderer {
private:
    const std::vector<std::string> SPANISH_RANKS;
    const std::vector<std::string> SPANISH_SUITS;
public:
    SpanishCardRenderer();
    void renderCard(const Card* c);
    void visitRank(int rank) const;
    void visitSuit(int suit) const;
};

#endif /* SRC_VIEWS_CONSOLE_INC_SPANISHCARDRENDERER_H_ */
