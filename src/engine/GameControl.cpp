#include "GameControl.h"

GameControl::GameControl() {
	mouseListeners = new vector<OIS::MouseListener*>();
	keyListeners = new vector<OIS::KeyListener*>();

	//attachMember(new SceneState());
}

GameControl::~GameControl() {
}

void GameControl::start() {
	OgreFramework::getSingleton()->getMouse()->setEventCallback(this);
	OgreFramework::getSingleton()->getKeyboard()->setEventCallback(this);
}

void GameControl::update(double tpf) {

}

void GameControl::stop() {

}

void GameControl::registerMouseListener(OIS::MouseListener* listener) {
	mouseListeners->push_back(listener);
}

void GameControl::registerKeyboardListener(OIS::KeyListener* listener) {
	keyListeners->push_back(listener);
}

bool GameControl::mouseMoved(const OIS::MouseEvent &e) {
	auto iter = mouseListeners->begin();
	auto iterEnd = mouseListeners->end();
	for (; iter != iterEnd; iter++) {
		OIS::MouseListener* listener = (*iter);
		listener->mouseMoved(e);
	}

	return true;
}

bool GameControl::mousePressed(const OIS::MouseEvent &e,
		OIS::MouseButtonID id) {
	auto iter = mouseListeners->begin();
	auto iterEnd = mouseListeners->end();
	for (; iter != iterEnd; iter++) {
		OIS::MouseListener* listener = (*iter);
		listener->mousePressed(e, id);
	}

	return true;
}

bool GameControl::mouseReleased(const OIS::MouseEvent &e,
		OIS::MouseButtonID id) {
	auto iter = mouseListeners->begin();
	auto iterEnd = mouseListeners->end();
	for (; iter != iterEnd; iter++) {
		OIS::MouseListener* listener = (*iter);
		listener->mouseReleased(e, id);
	}

	return true;
}

bool GameControl::keyPressed(const OIS::KeyEvent &arg) {
	auto iter = keyListeners->begin();
	auto iterEnd = keyListeners->end();
	for (; iter != iterEnd; iter++) {
		OIS::KeyListener* listener = (*iter);
		listener->keyPressed(arg);
	}

	return true;
}

bool GameControl::keyReleased(const OIS::KeyEvent &arg) {
	auto iter = keyListeners->begin();
	auto iterEnd = keyListeners->end();
	for (; iter != iterEnd; iter++) {
		OIS::KeyListener* listener = (*iter);
		listener->keyReleased(arg);
	}

	return true;
}
