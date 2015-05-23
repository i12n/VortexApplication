#ifndef   __C_DIRECTOR_MODULE_H__
#define   __C_DIRECTOR_MODULE_H__

#include "cSceneModule.h"
#include "cControllerModule.h"


class cDirector{
public:
	cDirector(){	scene = cScene::getInstance();}

	/// regist entity and controller for sene, override in derived class
	///
	virtual  void regist()=0;

	/// configure scene,as an interface
	///
	static void action(cDirector *director);

	/// send command to scene,as an interface
	///
	static void sendCommand( const char *name, sCommand cmd );

	virtual ~cDirector(){};

protected:

		cScene *scene;

};

void cDirector::action(cDirector *director){
	director->regist();
}
void  cDirector::sendCommand(const char *name, sCommand cmd){
	cController * controller = cScene::getInstance()->getController( name );
	if( controller ) controller->regist( cmd );
};



#endif  //__C_DIRECTOR_MODULE_H__