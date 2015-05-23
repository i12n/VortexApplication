#ifndef   __C_LAVCONTROLLER_H__
#define   __C_LAVCONTROLLER_H__

#include <list>
#include "cControllerModule.h"
#include "cCommandModule.h"
#include "cLAV.h"

class cLAVController : public cController {

public:

	cLAVController(const char *name, cLAV *_lav):cController(name, _lav), lav(_lav){};

	/// operate command
	///
	void  operate( sCommand cmd );

private:

	cLAV *lav;

};

#endif  //__C_LAVCONTROLLER_H__