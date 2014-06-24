#ifndef COMPONENTMANAGER_H_
#define COMPONENTMANAGER_H_

#include "std.h"
#include "commandchain.h"
//#include "state.h"

class ComponentManager : public CommandChain {
public:
	ComponentManager();
	virtual ~ComponentManager();

	/**
	 * Updates the Components
	 */
	virtual void update(double);

	/**
	 * Return the State
	 */
	CommandChain* state();
};

#endif /* COMPONENTMANAGER_H_ */
