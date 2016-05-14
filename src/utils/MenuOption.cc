/*
 * MenuOption.cc
 *
 *  Created on: 14 de may. de 2016
 *      Author: dancre
 */

#include <MenuOption.h>
#include <sstream>

MenuOption::MenuOption(const std::string& optionTitle, int highlightedCharPosition) :
	title(new std::string(optionTitle)),
	highlightedCharIt(title->begin())
{
	for (int i = 0; i < highlightedCharPosition; ++i) {
		++highlightedCharIt;
	}
}

char MenuOption::getHighlightedChar() const {
	return *highlightedCharIt;
}

const std::string MenuOption::toString() const {
	std::stringstream ss;
	for (std::string::const_iterator it = title->begin(); it != title->end(); ++it) {
		if (it == highlightedCharIt) {
			ss << '[' << *it << ']';
		} else {
			ss << *it;
		}
	}
	return ss.str();
}
