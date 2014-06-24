#include "component.h"

Component::Component() {
}

Component::~Component() {
}

void Component::update(double tpf) {

}

CommandChain* Component::manager() {
	return (CommandChain*) this->above->at(0);
}
