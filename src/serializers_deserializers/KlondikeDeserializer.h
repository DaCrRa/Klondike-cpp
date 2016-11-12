/*
 * KlondikeDeserializer.h
 *
 *  Created on: 9 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SERIALIZERS_DESERIALIZERS_KLONDIKEDESERIALIZER_H_
#define SRC_SERIALIZERS_DESERIALIZERS_KLONDIKEDESERIALIZER_H_

#include <AbstractDeckFactory.h>
#include <Klondike.h>
#include <memory>

class KlondikeDeserializer {
protected:
    std::shared_ptr<AbstractDeckFactory> deckFactory;
public:
    void setDeckFactory(std::shared_ptr<AbstractDeckFactory> factory) {
        deckFactory = factory;
    }
    virtual void deserialize(std::shared_ptr<Klondike>& g, std::istream& inputStream) = 0;
    virtual ~KlondikeDeserializer() {}
};



#endif /* SRC_SERIALIZERS_DESERIALIZERS_KLONDIKEDESERIALIZER_H_ */
