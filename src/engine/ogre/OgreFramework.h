#ifndef OGREFRAMEWORK_H_
#define OGREFRAMEWORK_H_

#include "std.h"
#include "engine/gamecontrol.h"

class GameControl;

class OgreFramework {
private:
	static OgreFramework* singleton;

	Ogre::String configFileName;
	Ogre::String pluginsFileName;
	Ogre::String logFileName;

	Ogre::Root* root;
	Ogre::RenderWindow* window;
	Ogre::Timer* timer;
	Ogre::Viewport* viewport;
	Ogre::SceneManager* sceneManager;
	Ogre::SceneNode* rootNode;
	Ogre::Camera* camera;
	OIS::Keyboard* keyboard;
	OIS::Mouse* mouse;

public:
	static OgreFramework* getSingleton();
	static void initialize();

	OgreFramework();
	OgreFramework(Ogre::String, Ogre::String, Ogre::String);
	virtual ~OgreFramework();

	bool initOgre();
	void runOgre(GameControl*);
	void stopOgre();

	Ogre::Root* getRoot();
	Ogre::RenderWindow* getWindow();
	Ogre::Timer* getTimer();
	Ogre::Viewport* getViewport();
	Ogre::SceneManager* getSceneManager();
	Ogre::SceneNode* getRootNode();
	Ogre::Camera* getCamera();
	OIS::Mouse* getMouse();
	OIS::Keyboard* getKeyboard();
};

#endif /* OGREFRAMEWORK_H_ */
