/*
 * Menu.h
 *
 *  Created on: 14 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_UTILS_INC_MENU_H_
#define SRC_UTILS_INC_MENU_H_

#include <MenuOption.h>
#include <ItemSelectionDialog.h>

#include <map>

template <typename T>
class Menu {
private:
	const std::string menuTitle;
	std::map<char, T> tags;
	std::vector<MenuOption> options;
public:
	Menu(const std::string& title, std::vector<std::pair<MenuOption, T> >&& options) :
		menuTitle(title)
	{
		for (typename std::vector<std::pair<MenuOption, T> >::iterator it = options.begin(); it != options.end(); ++it) {
			tags[it->first.getHighlightedChar()] = it->second;
			this->options.push_back(std::move(it->first));
		}
	};

	void displayOptions() {
		for (std::vector<MenuOption>::const_iterator it = options.begin(); it != options.end(); ++it) {
			std::cout << it->toString() << std::endl;
		}
	}

	T getUserSelection() {
		std::cout << menuTitle << std::endl;
		std::cout << std::endl;
		displayOptions();
		std::cout << std::endl;
		ItemSelectionDialog<T> dialog("Your choice? ", tags, 'c');
		return dialog.getSelectedItem();
	};
};

#endif /* SRC_UTILS_INC_MENU_H_ */
