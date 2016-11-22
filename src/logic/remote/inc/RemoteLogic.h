/*
 * RemoteLogic.h
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_LOGIC_REMOTE_INC_REMOTELOGIC_H_
#define SRC_LOGIC_REMOTE_INC_REMOTELOGIC_H_

#include <Logic.h>
#include <RemoteAppStatesBuilder.h>

class RemoteLogic : public Logic {
public:
    RemoteLogic(std::shared_ptr<AbstractDeckFactory> factory, KlondikeSaver& saver, KlondikeLoader& loader) :
        Logic(factory, saver, loader, std::shared_ptr<AppStatesBuilder>(new RemoteAppStatesBuilder(*this,
                factory,
                gameActionControllerHolder,
                gameSessionStarter,
                bestScoresController,
                saveGameController,
                loadGameController) )) {}
};

#endif /* SRC_LOGIC_REMOTE_INC_REMOTELOGIC_H_ */
