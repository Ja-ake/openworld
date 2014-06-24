#ifndef STATE_H_
#define STATE_H_

class GameControl;

#include "std.h"
#include "engine/gamecontrol.h"

class State : public CommandChain {
public:
	State();
	virtual ~State();

	/**
	 * Updates the ComponentManagers
	 */
	void update(double);

	/**
	 * Returns a handle to the GameControl currently running
	 */
	GameControl* app();
};

#endif /* STATE_H_ */
