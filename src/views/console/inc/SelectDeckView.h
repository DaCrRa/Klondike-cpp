/*
 * SelectDeckView.h
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_INC_SELECTDECKVIEW_H_
#define SRC_VIEWS_CONSOLE_INC_SELECTDECKVIEW_H_

#include <AbstractDeckFactory.h>

#include <map>

class SelectDeckView {
private:
	AbstractDeckFactory& deckFactory;
	std::map<DeckType, std::string> deckDescriptions;
public:
	SelectDeckView(AbstractDeckFactory& factory);
	void selectDeck();
};

#endif /* SRC_VIEWS_CONSOLE_INC_SELECTDECKVIEW_H_ */
