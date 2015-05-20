#include "cSceneModule.h"


bool cScene::init(){

	if(universe == NULL) this->universe = vpVxUniverse::find(name)->getUniverse();
	
	if(universe == NULL) return false;

	bool isInit = true;

	for(std::list< cEntity * >::const_iterator it = this->entities.begin(); it != this->entities.end(); it++){
		if( (*it) != NULL ){
			if((*it)->getStatus() ==  kEntityStatus::kEntityReady) {
				bool b = (*it)->begin();
				if( b == true ) {
					(*it)->setStatus(kEntityStatus::kEntityRun);
				}
				else isInit = false;
			}
		}
	}
	return isInit;
}

bool cScene::run(){

	if( !isReady )  isReady = this->init();
	
	for(std::list< cEntity * >::const_iterator it = this->entities.begin(); it != this->entities.end(); it++){
		if( (*it) != NULL && (*it)->getStatus() == kEntityStatus::kEntityRun ){
			(*it)->run();
		}
	}

	for( std::list<cController *>::const_iterator it = this->controllers.begin(); it != this->controllers.end(); it++){

		if(  (*it) != NULL ) {
			(*it)->enable();
			(*it)->execute();
		}

	}

	return true;

}


bool cScene::regist( cEntity * entity, cController *controller ){

	if( entity == NULL ) return false;

	this->entities.push_back(entity);

	if( controller != NULL )  this->controllers.push_back( controller );

	return true;

}


cController * cScene::getController(const char *_name){

	for( std::list< cController * >::const_iterator it = this->controllers.begin(); it != this->controllers.end(); it++){
		if( (*it) != NULL ) {

			char name[40];
			(*it)->getName( name );
			if ( strcmp( name , _name) == 0 ) return *it;
		}

	}

	return NULL;
}

cEntity * cScene::getEntity(const char *_name){

	for( std::list<cEntity *>::const_iterator it = this->entities.begin(); it != this->entities.end(); it++){
		if( (*it) != NULL ) {

			char name[30];
			(*it)->getName(name);
			if ( strcmp(name, _name) == 0 ) return *it;
		}

	}

	return NULL;
}
