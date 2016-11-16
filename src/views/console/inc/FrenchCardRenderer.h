/*
 * FrenchCardRenderer.h
 *
 *  Created on: 15 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_INC_FRENCHCARDRENDERER_H_
#define SRC_VIEWS_CONSOLE_INC_FRENCHCARDRENDERER_H_

#include <CardConsoleRenderer.h>

#include <vector>
#include <string>

class FrenchCardRenderer: public CardConsoleRenderer {
private:
    const std::vector<std::string> FRENCH_RANKS;
    const std::vector<std::string> FRENCH_SUITS;
public:
    FrenchCardRenderer();
    void renderCard(const Card* c);
    void visitRank(int rank) const;
    void visitSuit(int suit) const;
};

#endif /* SRC_VIEWS_CONSOLE_INC_FRENCHCARDRENDERER_H_ */
