#include "componentmanager.h"

ComponentManager::ComponentManager() {
}

ComponentManager::~ComponentManager() {
}

void ComponentManager::update(double tpf) {
	auto iter = above->begin();
	auto iterEnd = above->end();
	for (; iter != iterEnd; iter++) {
		CommandChain* c = (CommandChain*) *iter;
		c->update(tpf);
	}
}

CommandChain* ComponentManager::state() {
	return (CommandChain*) above->at(0);
}
