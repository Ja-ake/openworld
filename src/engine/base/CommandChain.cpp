#include "commandchain.h"

CommandChain::CommandChain() {
	active = true;

	this->above = new vector<CommandChain*>();
	this->below = new vector<CommandChain*>();
}

CommandChain::CommandChain(CommandChain* boss) {
	active = true;

	this->above = new vector<CommandChain*>();
	this->below = new vector<CommandChain*>();

	this->above->push_back(boss);
}

vector<CommandChain*>* CommandChain::getAbove() {
	return this->above;
}

vector<CommandChain*>* CommandChain::getBelow() {
	return this->below;
}

void CommandChain::attachMember(CommandChain* member) {
	this->below->push_back(member);
	member->above->push_back(this);
}

void CommandChain::attachLeader(CommandChain* leader) {
	this->above->push_back(leader);
	leader->below->push_back(this);
}

CommandChain::~CommandChain() {
	// TODO: DELETE EVERYTHING
}

