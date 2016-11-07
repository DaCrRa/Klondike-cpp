
#ifndef KLONDIKESERIALIZER_H_
#define KLONDIKESERIALIZER_H_

#include <Klondike.h>

#include <memory>

class KlondikeSerializer {
protected:
    std::shared_ptr<Klondike>& game;
public:
    KlondikeSerializer(std::shared_ptr<Klondike>& g) :
        game(g) {}
    virtual void serialize(std::ostream& outputStream) = 0;
    virtual ~KlondikeSerializer() {}
};

#endif
