#include "cEntityModule.h"

bool cEntity::begin(){
		
	vpVxMechanism *vpMsm =   vpVxMechanism::find( name );
	if( vpMsm == NULL ) return false;

	vxMsm = vpMsm->getMechanism();
	if( vxMsm == NULL )  return false;

	vxAsm = vxMsm->getAssembly(0);
	if ( vxAsm == NULL ) return false;

	bool b = config();
	return b;

}
bool cEntity::config(){ 
	return true;
};