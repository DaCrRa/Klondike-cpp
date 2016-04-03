#include <Pile.h>

#include <assert.h>

void Pile::add(const Card* c) {
   cards.push_back(c);
}

void Pile::add(const std::vector<const Card*>& cards) {
   this->cards.insert(this->cards.end(), cards.begin(), cards.end());
}

bool Pile::hasCards() {
	return !cards.empty();
}

const Card* Pile::top() {
	assert(hasCards());
	return cards.back();
}

const Card* Pile::removeTop() {
	const Card* top = this->top();
	cards.pop_back();
	return top;
}
