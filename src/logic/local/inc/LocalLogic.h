/*
 * LocalLogic.h
 *
 *  Created on: 17 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_LOGIC_LOCAL_INC_LOCALLOGIC_H_
#define SRC_LOGIC_LOCAL_INC_LOCALLOGIC_H_

#include <Logic.h>
#include <LocalAppStatesBuilder.h>

class LocalLogic : public Logic {
public:
    LocalLogic(std::shared_ptr<AbstractDeckFactory> factory, KlondikeSaver& saver, KlondikeLoader& loader) :
        Logic(factory, saver, loader, std::shared_ptr<AppStatesBuilder>(new LocalAppStatesBuilder(*this,
                factory,
                gameActionControllerHolder,
                gameSessionStarter,
                bestScoresController,
                saveGameController,
                loadGameController) )) {}
};



#endif /* SRC_LOGIC_LOCAL_INC_LOCALLOGIC_H_ */
