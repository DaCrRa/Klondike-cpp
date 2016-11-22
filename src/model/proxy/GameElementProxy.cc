/*
 * GameElementProxy.cc
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#include <GameElementProxy.h>

#include <sstream>
#include <iostream>

GameElementProxy::GameElementProxy(const std::string& h, int id, char elementId) {
    std::stringstream urlStream;
    urlStream << "http://" << h << "/klondike/" << id << "/" << elementId;
    gameElementUrl = urlStream.str();
}

void GameElementProxy::httpRequest(const std::string& method, const std::vector<std::string>& params) const {
    std::stringstream requestHeader;
    requestHeader << method << " ";
    requestHeader << gameElementUrl;
    for (const std::string& param : params) {
        requestHeader << "/" << param;
    }
    std::cout << requestHeader.str() << std::endl;
}

Pile GameElementProxy::removeCards(int n) {
    std::stringstream paramStream;
    paramStream << n;
    httpRequest("DELETE", std::vector<std::string>({ paramStream.str() }));
}
