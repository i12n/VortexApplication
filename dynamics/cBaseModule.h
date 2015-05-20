#ifndef   __C_BASE_MODULE_H__
#define   __C_BASE_MODULE_H__

#include "vsgu.h"

#include <vpVortex/vpVxMechanism.h>
#include <vpVortex/vpVxMechanismInterface.h>
#include <vpVortex/vpVxPropertyBoolean.h>
#include <vpVortex/vpVxPropertyReal.h>
#include <vpVortex/vpVxPropertyVector3.h>
#include <vpVortex/vpVxUniverse.h>

#include <VxSim/VxDynamicsModuleICD.h>
#include <CableSystems/CableSystemsICD.h>
#include <CableSystems/DynamicsICD.h>
#include <VxSim/VxMechanism.h>


#include <VxData/Container.h>
#include <VxData/FieldArray.h>
#include <VxData/FieldBase.h>

#include <VxData/Vector.h>

#include <Vx/VxPlane.h>
#include <Vx/VxCollisionGeometry.h>
#include <Vx/VxPart.h>
#include <Vx/VxFrame.h>

#include <Vx/VxNode.h>
#include "Vx/VxRPRO.h"
#include "Vx/VxGrasp.h"
#include "Vx/Find.h"
#include "Vx/VxPrismatic.h"
#include "Vx/VxHinge.h"

#include "Vx/VxFluidInteraction.h"

/// singleton template
///
template< class T>
class cSingleton{

public :

	static T* getInstance(){
		if (instance == NULL) instance = new T();
		return instance;
	};

protected:

	cSingleton(){};

private:

	static T *instance;

};

template< class T>
T *cSingleton<T>::instance = NULL;



/// data wrapper
///
class cData{

public:
	
	cData(Vx::VxReal _data){ data.data1 =_data; };
	cData(Vx::VxReal3 _data){ data.data2[0] =_data[0]; data.data2[1] =_data[1];data.data2[2] =_data[2];};
	cData(bool _data){ data.data3 =_data; };

	operator Vx::VxReal(){ return  data.data1; }
	operator  Vx::VxReal3Ptr(){ return  data.data2;}
	operator bool(){ return  data.data3; }
private:
	union {
		Vx::VxReal  data1;
		Vx::VxReal3  data2;
		bool	data3;
	} data;
};
#endif  //__C_BASE_MODULE_H__
