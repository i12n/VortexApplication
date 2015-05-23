#ifndef __C_CONTROLLER_MODULE_H__
#define  __C_CONTROLLER_MODULE_H__

#include <list>
#include "string.h"
#include "cBaseModule.h"
#include "cCommandModule.h"
#include "cEntityModule.h"

class cController{
public:

	cController(const char * _name,cEntity *entity);

	/// rename the controller
	///
	inline void setName(const char *_name);

	/// get  the name of controller
	///
	inline void getName(char *_name) ;

	/// regist command
	///
	inline void regist(sCommand cmd);

	/// execute command
	///
	virtual void execute();

	/// operate command
	///
	virtual void  operate(sCommand cmd);
	

	inline void  enable();

	virtual ~cController(){};

protected:
	std::list< sCommand > commands;

private:
	char name[30];
	bool isOK;
	cEntity *entity;
};

inline void cController::setName(const char *_name){
	strcpy(this->name, _name);
}

inline void cController::getName(char *_name) {
	strcpy(_name,  this->name);
}

inline void cController::regist(sCommand cmd){
	if(this->isOK) commands.push_back(cmd);
}

inline void  cController::enable(){
	if(entity->getStatus() ==  kEntityStatus::kEntityRun) this->isOK = true;
}

#endif    //__C_CONTROLLER_MODULE_H__