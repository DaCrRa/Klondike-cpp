/*
 * TestDeckFactory.h
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CARDS_TEST_CARDS_INC_TESTDECKFACTORY_H_
#define SRC_CARDS_TEST_CARDS_INC_TESTDECKFACTORY_H_

#include <AbstractDeckFactory.h>

#include <SpanishDeck.h>
#include <FrenchDeck.h>

class DeckFactory : public AbstractDeckFactory {
public:
    DeckFactory() :
        AbstractDeckFactory( {
        std::shared_ptr<Deck>(new SpanishDeck()),
            std::shared_ptr<Deck>(new FrenchDeck())
    }) {}
};



#endif /* SRC_CARDS_TEST_CARDS_INC_TESTDECKFACTORY_H_ */
