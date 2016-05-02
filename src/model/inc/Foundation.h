/*
 * Foundation.h
 *
 *  Created on: 2 Apr 2016
 *      Author: dancre
 */

#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <Pile.h>

class Foundation {
	private:
		Pile pile;
	public:
		void add(Card* c);
		bool accept(Card* c);
		bool isCompleted() const;
		int getNumCards() const;
		const Card* top() const;
};

#endif
