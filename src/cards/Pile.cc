#include <Pile.h>

#include <assert.h>

void Pile::add(const Card* c) {
    cards.push_back(c);
}

void Pile::add(const std::vector<const Card*>& cards) {
    this->cards.insert(this->cards.end(), cards.begin(), cards.end());
}

bool Pile::hasCards() const {
    return !cards.empty();
}

const Card* Pile::showTopCard() const {
    assert(hasCards());
    return cards.back();
}

const Pile Pile::showLastCards(int n) const {
    assert(n <= getNumberOfCards());
    Pile p;
    for (PileIterator it = end() - n; it != end(); ++it) {
        p.add(*it);
    }
    return p;
}

Pile Pile::removeLastCards(int n) {
    assert(n <= getNumberOfCards());
    Pile p;
    for (PileIterator it = end() - n; it != end(); it = cards.erase(it)) {
        p.add(*it);
    }
    return p;
}

int Pile::getNumberOfCards() const {
    return cards.size();
}

const Card* Pile::removeTopCard() {
    const Card* top = this->showTopCard();
    cards.pop_back();
    return top;
}

bool Pile::isOrdered(std::function<bool(const Card*, const Card*)> orderingCriteria) const {
    if (!hasCards()) {
        return false;
    }
    bool ordered = true;
    const Card* card = *begin();
    for (PileIterator it = begin() + 1; it != end() && ordered; ++it) {
        const Card* nextCard = *it;
        ordered &= orderingCriteria(card, nextCard);
        card = nextCard;
    }
    return ordered;
}

PileIterator Pile::begin() const {
    return cards.begin();
}

PileIterator Pile::end() const {
    return cards.end();
}
