/*
 * MenuOption.cc
 *
 *  Created on: 14 de may. de 2016
 *      Author: dancre
 */

#include <MenuOption.h>

#include <sstream>
#include <assert.h>

MenuOption::MenuOption(std::string&& optionTitle, size_t highlightedCharPos) :
	title(optionTitle),
	highlightedCharPos(highlightedCharPos)
{
	assert(this->highlightedCharPos < title.size());
}

char MenuOption::getHighlightedChar() const {
	return title[highlightedCharPos];
}

const std::string MenuOption::toString() const {
	std::stringstream ss;
	for (size_t pos = 0; pos < title.size(); ++pos) {
		if (pos == highlightedCharPos) {
			ss << '[' << title[pos] << ']';
		} else {
			ss << title[pos];
		}
	}
	return ss.str();
}
