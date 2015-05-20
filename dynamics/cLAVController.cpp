#include "cLAVController.h"


void  cLAVController::operate( sCommand cmd ){
	int id = cmd.cid;
	cData data = cmd.data; 
	
	switch( id ){

		case 100:
			lav->stop();
			break;

		case 101:
			lav->forward(data);
			break;
		case 102:
			lav->back(data);
			
			break;
	}

}
