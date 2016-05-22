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
	size_t highlightedCharPos;
	MenuOption(const MenuOption& that) = delete;
public:
	MenuOption(MenuOption&& other) :
		title(std::move(other.title)),
		highlightedCharPos(std::move(other.highlightedCharPos)) {}
	MenuOption(std::string&& optionTitle, size_t highlightedCharPos);
	char getHighlightedChar() const;
	const std::string toString() const;
};

#endif
