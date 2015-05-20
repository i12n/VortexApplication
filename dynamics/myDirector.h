#ifndef  __MY_DIRECTOR_H__
#define   __MY_DIRECTOR_H__

#include "cBaseModule.h"
#include "cLAV.h"
#include "cLAVController.h"

#include "cSceneModule.h"
#include "cDirectorModule.h"



class myDirector : public cDirector{
public:

	myDirector(){}

	/// override
	///
	void regist();

};

void myDirector::regist(){

	scene->setName("myVxUniverse");

	cLAV * lav = new cLAV("LAV"); 
	cLAVController *lav_ctrl = new cLAVController("lav", lav);
	scene->regist(lav, lav_ctrl);

}

#endif