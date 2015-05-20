#include "cLAV.h"


bool cLAV::config(){

	this->addForce(100000);
	return true;

}
bool cLAV::run(){

	Vx::VxPart *part = Vx::Find::part("LAV_VP", this->getVxAsm());
	part->getOrientationEulerAngles( this->orientation );
	part->getPosition(this->position);
	return true;
}

void cLAV::addForce(double force){
	Vx::VxPart *part = Vx::Find::part("LAV_VP", this->getVxAsm()); 
	part->addForce(Vx::VxVector3(force*cos(this->orientation[0]),force*sin(this->orientation[0]),0));
}

void cLAV::setBodyVelocity(Vx::VxReal x, Vx::VxReal y, Vx::VxReal z){
	Vx::VxPart *part = Vx::Find::part("LAV_VP", this->getVxAsm());
	part->setLinearVelocity(x, y, z);
}