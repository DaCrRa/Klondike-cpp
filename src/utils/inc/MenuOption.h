/*
 * MenuOption.h
 *
 *  Created on: 14 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_UTILS_MENUOPTION_H_
#define SRC_UTILS_MENUOPTION_H_

#include <string>
#include <memory>

class MenuOption {
private:
	std::string title;
	std::string::iterator highlightedCharIt;
	MenuOption(const MenuOption& that) = delete;
public:
	MenuOption(MenuOption&& other) :
		title(std::move(other.title)),
		highlightedCharIt(std::move(other.highlightedCharIt)) {}
	MenuOption(std::string&& optionTitle, int highlightedCharPosition);
	char getHighlightedChar() const;
	const std::string toString() const;
};

#endif
