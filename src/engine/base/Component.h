#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "std.h"
#include "commandchain.h"
//#include "componentmanager.h"

class Component : public CommandChain {
public:
	Component();
	virtual ~Component();

	/**
	 * Updates the component
	 */
	void update(double);

	/**
	 * Returns a handle to the ComponentManager
	 */
	CommandChain* manager();
};

#endif /* COMPONENT_H_ */
