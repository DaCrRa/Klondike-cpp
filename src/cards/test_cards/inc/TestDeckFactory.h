/*
 * TestDeckFactory.h
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CARDS_TEST_CARDS_INC_TESTDECKFACTORY_H_
#define SRC_CARDS_TEST_CARDS_INC_TESTDECKFACTORY_H_

#include <DeckFactory.h>
#include <TestDeck.h>

class TestDeckFactory : public DeckFactory {
public:
    TestDeckFactory() :
        DeckFactory(std::shared_ptr<Deck>(new TestDeck())) {}
};



#endif /* SRC_CARDS_TEST_CARDS_INC_TESTDECKFACTORY_H_ */
