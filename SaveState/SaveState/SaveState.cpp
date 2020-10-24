#include "SaveState.h"
#include "SaveStateManager.h"

using namespace std;

// initializing static variable next id
unsigned int SaveState::_nextId = 0;

SaveState::SaveState() : _id(_nextId++) 
{
	// Register with SaveStateManager
	SaveStateManager::Register(this);
}

SaveState::SaveState(unsigned int id) : _id(id)
{
	// setting next id
	_nextId = _id + 1;
}

SaveState::~SaveState()
{
	// removing this object from serializable objects
	SaveStateManager::Unregister(this);
}

void SaveStateClassRegister(unsigned int classId, NewFunctor newFunctor)
{
	SaveStateManager::RegisterClass(classId, newFunctor);
}
