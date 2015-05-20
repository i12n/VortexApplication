
#include "myApp.h"
#include<windows.h>


int main(int argc, char *argv[])
{
	//-------------------------------------------------------------------------
	// Initialize Vega Prime.
	//-------------------------------------------------------------------------
	vp::initialize( argc, argv );

	// initialize VpVortex modules 
    if (vpModule::initializeModule("vpvortex") != vsgu::SUCCESS)
    {
        vuNotify::print(vuNotify::LEVEL_WARN, NULL, "Failed to load VpVortex module! Exiting NOW!");
        vp::shutdown();
    }

	myApp *app = new myApp;

	//-------------------------------------------------------------------------
	// Load the default ACF, if one is not specified as a command line 
	// argument.
	//-------------------------------------------------------------------------

	app->define( "Resources/scene.acf" );

	//-------------------------------------------------------------------------
	// Configure myApp as well as Vega Prime.  This is where class instances 
	// created during the define stage are configured.  Thus, any special 
	// effects created prior to this call will be configure automatically.
	//-------------------------------------------------------------------------

	app->configure();

	//-------------------------------------------------------------------------
	// The runtime loop.
	//-------------------------------------------------------------------------
	app->run();

	//-------------------------------------------------------------------------
	// Unconfigure the pMyApp instance.
	//-------------------------------------------------------------------------
	app->unconfigure();

	//-------------------------------------------------------------------------
	// Unref the pMyApp instance.
	//-------------------------------------------------------------------------
	app->unref();

	//-------------------------------------------------------------------------
	// Shutdown Vega Prime.
	//-------------------------------------------------------------------------
	vp::shutdown();	
	return 0;
}
