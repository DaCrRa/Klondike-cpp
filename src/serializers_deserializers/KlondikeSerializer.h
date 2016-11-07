
#ifndef KLONDIKESERIALIZER_H_
#define KLONDIKESERIALIZER_H_

#include <Klondike.h>

#include <memory>

class KlondikeSerializer {
public:
    virtual void serialize(std::shared_ptr<Klondike>& g, std::ostream& outputStream) = 0;
    virtual ~KlondikeSerializer() {}
};

#endif
