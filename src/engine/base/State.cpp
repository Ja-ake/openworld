#include "state.h"

State::State() {
}

State::~State() {
}

void State::update(double tpf) {
	auto iter = above->begin();
	auto iterEnd = above->end();
	for (; iter!=iterEnd; iter++) {
		CommandChain* cm = (CommandChain*) *iter;
		cm->update(tpf);
	}
}

GameControl* State::app() {
	if (this->getAbove()->size() > 0) {
		return (GameControl*) this->getAbove()->at(0);
	} else {
		return nullptr;
	}
}
