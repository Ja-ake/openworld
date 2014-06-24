#ifndef COMMANDCHAIN_H_
#define COMMANDCHAIN_H_

#include "std.h"

/**
 * Base class for the chain of command, where:
 * GameControl controls the States, the States
 * control the ComponentManagers, and the
 * ComponentManagers control the Components.
 */
class CommandChain {
public:
	/**
	 * Constructs a CommandChain with no supervisor.
	 */
	CommandChain();

	/**
	 * Constructs a CommandChain with arg0 as it's boss.
	 */
	CommandChain(CommandChain*);

	/**
	 * Deletes this CommandChain and all CommandChains under it.
	 */
	virtual ~CommandChain();

	/**
	 * Gets a vector containing all of the CommandChains directly above it.
	 */
	vector<CommandChain*>* getAbove();

	/**
	 * Gets a vector containing all of the CommandChains directly below it.
	 */
	vector<CommandChain*>* getBelow();

	/**
	 * Attaches a member below this CommandChain.
	 */
	void attachMember(CommandChain* member);

	/**
	 * Attaches a leader above this CommandChain.
	 */
	void attachLeader(CommandChain* leader);

	/**
	 * Update function
	 */
	virtual void update(double) = 0;
protected:
	vector<CommandChain*>* above;
	vector<CommandChain*>* below;
	bool active;
};

#endif /* COMMANDCHAIN_H_ */
