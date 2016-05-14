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
	std::shared_ptr<std::string> title;
	std::string::const_iterator highlightedCharIt;
public:
	MenuOption(const std::string& optionTitle, int highlightedCharPosition);
	char getHighlightedChar() const;
	const std::string toString() const;
};

#endif
