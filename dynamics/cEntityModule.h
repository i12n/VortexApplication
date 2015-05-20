#ifndef   __C_ENTITY_MODULE_H__
#define   __C_ENTITY_MODULE_H__

#include <list>
#include "string.h"
#include "cBaseModule.h"


enum kEntityStatus{ kEntityReady=0,  kEntityRun };

class cEntity{

public:

	cEntity( const char*  name):status( kEntityReady ),vxMsm(NULL),vxAsm(NULL){  strcpy(this->name, name); }
	
	/// entity begin
	///
	bool begin();
	/// entity congfig
	///
	virtual bool config();

	/// entity run
	///
	virtual bool run(){ return false;};


	inline void  setStatus(kEntityStatus _status ) ;
	inline kEntityStatus getStatus() ;
	inline VxSim::VxMechanism *getVxMsm();
	inline Vx::VxAssembly *getVxAsm();
	inline void getName( char *_name);

	virtual ~cEntity(){};

protected:

	char name[30];     // the Mechanism's name
	VxSim::VxMechanism *vxMsm;
	Vx::VxAssembly *vxAsm;

private:

	kEntityStatus status;

};

inline void cEntity::getName( char *_name) {
	strcpy(_name,  this->name);
}

inline kEntityStatus cEntity::getStatus() { return status;}
inline void  cEntity::setStatus(kEntityStatus _status ) { status = _status ; }

inline VxSim::VxMechanism *cEntity::getVxMsm(){ return vxMsm; }
inline Vx::VxAssembly *cEntity::getVxAsm(){ return vxAsm; }


#endif  //__C_ENTITY_MODULE_H__