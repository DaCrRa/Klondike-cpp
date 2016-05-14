/*
 * CharInputDialog.h
 *
 *  Created on: 7 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_UTILS_CHARINPUTDIALOG_H_
#define SRC_UTILS_CHARINPUTDIALOG_H_

#include <assert.h>
#include <map>
#include <exception>
#include <iostream>

class CancelledDialogException : public std::exception {
public:
	const char* what() const throw() {
		return "Cancelled dialog!";
	};
};


template <typename T>
class ItemSelectionDialog {
public:
	ItemSelectionDialog(const std::string& t, const std::map<char, T>& allowed, const char flag) :
		title(t),
		allowedChars(allowed),
		cancelFlag(flag)
	{
		assert(allowedChars.count(cancelFlag) == 0);
	};
	T getSelectedItem() {
		typename std::map<char, T>::const_iterator selected = allowedChars.end();
		while (selected == allowedChars.end()) {
			std::cout << title;
			char userInput;
			std::cin >> userInput;
			if (userInput == cancelFlag) {
				throw CancelledDialogException();
			}
			selected = allowedChars.find(userInput);
		}
		return selected->second;
	}
private:
	const std::string& title;
	char cancelFlag;
	const typename std::map<char, T>& allowedChars;
};

#endif /* SRC_UTILS_CHARINPUTDIALOG_H_ */
