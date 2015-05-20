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

#include "cSceneModule.h"
#include "myKeyIuputForControl.h"
#include "myDirector.h"


using namespace std;

class myApp :public vpApp{

public:

	myApp(void);
	virtual ~myApp(void){ };
	virtual  void run(void);
	virtual void onKeyInput(vrWindow::Key key, int mod);

private:

	cScene *scene;	// the scene
	myDirector *director;	// the director

};

inline myApp::myApp(void) {
	scene = cScene::getInstance();	//set the scene
	director = new myDirector();	//set the director
};

void myApp::run(void){

	cDirector::action(director);	//configure the scene 

	while ( beginFrame()> 0 ){

		scene->run(); // scene run
		
		endFrame();	
	}
}

void myApp::onKeyInput(vrWindow::Key key, int mod){
	switch( key ){

		case vrWindow::KEY_ESCAPE:
			breakFrameLoop();
			break;
		default: 
			keyInput(key,mod);	//key input command
			break;

	}

}