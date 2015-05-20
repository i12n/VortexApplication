#ifndef __C_COMMAND_MODULE_H__
#define  __C_COMMAND_MODULE_H__

#include "cBaseModule.h"

struct sCommand {
	sCommand(int _cid, cData _data):cid(_cid),data(_data){};
	int cid;
	cData data;
};

#endif  //__C_COMMAND_MODULE_H__