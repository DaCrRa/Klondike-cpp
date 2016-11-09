/*
 * KlondikePlainTextDeserializer.cpp
 *
 *  Created on: 9 Nov 2016
 *      Author: dancre
 */

#include <KlondikePlainTextDeserializer.h>

void KlondikePlainTextDeserializer::deserialize(std::shared_ptr<Klondike>& g, std::istream& inputStream) {
    g = std::shared_ptr<Klondike>(new Klondike());
}

