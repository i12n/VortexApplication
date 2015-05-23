#ifndef   __C_LAV_H__
#define   __C_LAV_H__

#include "cBaseModule.h"
#include "cEntityModule.h"
#include "cmath"



class cLAV : public cEntity {
public:
	cLAV(const char *name):cEntity(name){
	}
	bool config();
	bool run();

	/// set lav's velocity = 0
	///
	void stop();

	/// lav walk forward
	///
	void forward(Vx::VxReal v);

	/// lav walk back
	///
	void back(Vx::VxReal v);

protected:

	/// lav add force in head direction
	///
	void addForce(double force);

	/// lav set velocity
	///
	void setBodyVelocity(Vx::VxReal x, Vx::VxReal y, Vx::VxReal z);

private:

	double orientation[3];
	double position[3];

};

inline void  cLAV::stop(){
	   
	this->setBodyVelocity(0, 0, 0);
}
inline void cLAV::forward(double force){
	this->addForce(force);
	
	
	
}
inline void cLAV::back(double force){
	this->addForce(-force);
	
}


#endif //__C_LAV_H__