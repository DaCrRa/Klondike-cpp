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
		void add(const Card* c);
		bool accept(const Card* c);
		bool isCompleted() const;
		int getNumCards() const;
		const Card* top() const;
};

#endif
