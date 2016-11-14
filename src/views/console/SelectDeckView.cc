/*
 * SelectDeckView.cpp
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#include <SelectDeckView.h>
#include <Menu.h>

#include <iostream>


SelectDeckView::SelectDeckView(AbstractDeckFactory& factory) :
    deckFactory(factory),
    deckDescriptions( {
    {SPANISH_DECK, "Spanish deck"},
    {FRENCH_DECK, "French deck"}
}) {}

void SelectDeckView::selectDeck() {
    if (deckFactory.getNumberOfAvailableDecks() > 1) {
        std::vector<std::pair<MenuOption, DeckType> > options;
        for (DeckType type : deckFactory.getDeckTypes()) {
            options.push_back(std::make_pair(MenuOption(std::string(deckDescriptions[type]), 0), type));
        }
        Menu<DeckType> m("Select a deck:", std::move(options));
        m.getUserSelection();
    }
}

