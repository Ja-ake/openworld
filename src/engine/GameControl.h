#ifndef GAMECONTROL_H_
#define GAMECONTROL_H_

//class TestEXT;

#include "std.h"
#include "base/commandchain.h"
#include "states/scenestate.h"
//#include "states/testext.h"
#include "ogre/ogreframework.h"

/**
 * Controls the game loop and fires events. Has a list of states
 * that the game can be in and controls game state.
 */
class GameControl : public CommandChain, public OIS::MouseListener, public OIS::KeyListener {
public:
	GameControl();
	virtual ~GameControl();

	/**
	 * Initializes the window.
	 */
	void start();

	/**
	 * Runs one cycle of the game loop.
	 */
	void update(double);

	/**
	 * Kills the window and ends the game.
	 */
	void stop();

	void registerMouseListener(OIS::MouseListener* listener);
	void registerKeyboardListener(OIS::KeyListener* listener);

	bool mouseMoved(const OIS::MouseEvent &e);
	bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);

	bool keyPressed(const OIS::KeyEvent &arg);
	bool keyReleased(const OIS::KeyEvent &arg);
private:
	vector<OIS::MouseListener*>* mouseListeners;
	vector<OIS::KeyListener*>* keyListeners;

	//TestEXT test;
};

#endif /* GAMECONTROL_H_ */
