/*
 * KlondikePlainTextDeserializer.h
 *
 *  Created on: 9 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SERIALIZERS_DESERIALIZERS_PLAIN_TEXT_INC_KLONDIKEPLAINTEXTDESERIALIZER_H_
#define SRC_SERIALIZERS_DESERIALIZERS_PLAIN_TEXT_INC_KLONDIKEPLAINTEXTDESERIALIZER_H_

#include <KlondikeDeserializer.h>

class KlondikePlainTextDeserializer: public KlondikeDeserializer {
private:
    std::vector<int> deserializePile(
        std::string& readString,
        std::istream& inputStream,
        const std::string& endMark);
public:
    void deserialize(std::shared_ptr<Klondike>& g, std::istream& inputStream);
};

#endif /* SRC_SERIALIZERS_DESERIALIZERS_PLAIN_TEXT_INC_KLONDIKEPLAINTEXTDESERIALIZER_H_ */
