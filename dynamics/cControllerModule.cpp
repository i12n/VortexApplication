#include "cControllerModule.h"

cController::cController(const char * _name, cEntity * _entity):entity(_entity),isOK(false){
	if(_name != NULL  ) strcpy(this->name, _name);
	else this->name[0] = '\0';
}
void cController::execute(){

	std::list< sCommand >::iterator it = commands.begin();

	while( it != commands.end() ){
		if( this->isOK ) operate( *it);
		commands.pop_front();
		it = commands.begin();
	}

}

void cController::operate( sCommand cmd ){}