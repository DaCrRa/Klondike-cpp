/*
 * DeckFactory.h
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CARDS_INC_ABSTRACTDECKFACTORY_H_
#define SRC_CARDS_INC_ABSTRACTDECKFACTORY_H_

#include <Deck.h>
#include <DeckTypes.h>

#include <vector>
#include <map>
#include <memory>

class AbstractDeckFactory {
private:
    std::map<DeckType, std::shared_ptr<Deck> > decks;
    std::vector<DeckType> deckTypes;
    Deck& selectedDeck;
protected:
    AbstractDeckFactory(std::vector<std::shared_ptr<Deck> > decks);
public:
    void setSelectedDeck(DeckType type);
    std::vector<DeckType> getDeckTypes();
    int getNumberOfAvailableDecks();
    Deck& getDeck();
};

#endif /* SRC_CARDS_INC_ABSTRACTDECKFACTORY_H_ */
