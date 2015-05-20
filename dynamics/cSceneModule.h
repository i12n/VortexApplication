#ifndef   __C_SCENE_MODULE_H__
#define   __C_SCENE_MODULE_H__

#include <list>
#include "cBaseModule.h"
#include "cEntityModule.h"
#include "cControllerModule.h"


/// Scene
///

class cScene : public cSingleton< cScene >{
	friend class cSingleton< cScene >;

public:

	/// initialize scene
	///
	bool init();

	/// run scene
	///
	bool run();

	/// regist entity and controller in scene
	///
	bool regist(cEntity * entity, cController *controller= NULL);


	void setName(const char *name ){ strcpy(this->name, name); }

	/// get controller by name
	///
	cController * getController(const char *name);

	/// get entity  by name
	///
	cEntity * getEntity(const char *name);

	/// return the universe
	///
	Vx::VxUniverse *getUniverse(){ return universe; }

	/// scene is initialized or not 
	///
	bool isReady;

protected:

	cScene():isReady(false),universe(NULL){};
	Vx::VxUniverse *universe;
	char name[30];

private:

	std::list< cEntity * > entities;
	std::list< cController * > controllers;

};

#endif  //__C_SCENE_MODULE_H__
