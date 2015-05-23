#include "vpApp.h"
#include "vpEnv.h"
#include "vpObject.h"
#include  "vsTransform.h"
#include "vpOverlay2DText.h"

#include "vpWindow.h"
#include "vpChannel.h"
#include "vpObserver.h"
#include "vpScene.h"
#include "vpTransform.h"
#include "vpIsectorServiceInline.h"
#include "vpRecyclingService.h"

#include "vsgu.h"
#include "vsSwitch.h"
#include "vp.h"
#include "vsDOF.h"

#include <vpVortex/vpVxMechanism.h>
#include <vpVortex/vpVxMechanismInterface.h>
#include <vpVortex/vpVxPropertyBoolean.h>
#include <vpVortex/vpVxPropertyReal.h>
#include <vpVortex/vpVxPropertyVector3.h>
#include <vpVortex/vpVxUniverse.h>


#include "cLAV.h"
#include "cSceneModule.h"
#include "cCommandModule.h"
#include "cDirectorModule.h"

void keyInput(vrWindow::Key key, int mod){

	switch( key ){
		case vrWindow::KEY_q:{
			sCommand cmd(100, 0.0);
			cDirector::sendCommand("lav", cmd);	// send command to contoller
			break;
		}
		case vrWindow::KEY_w:{
				sCommand cmd(101, 5000.0);
				cDirector::sendCommand("lav", cmd);
				break;
		}
		case vrWindow::KEY_s:{
				sCommand cmd(102, 5000.0);
				cDirector::sendCommand("lav", cmd);
				break;
		}
	}
	
}
