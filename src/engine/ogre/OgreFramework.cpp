#include "ogreframework.h"

OgreFramework* OgreFramework::singleton;

void OgreFramework::initialize() {
	OgreFramework::singleton = new OgreFramework();
}

OgreFramework* OgreFramework::getSingleton() {
	return OgreFramework::singleton;
}

OgreFramework::OgreFramework() {
	configFileName = "";
	pluginsFileName = "";
	logFileName = "LOG.TXT";
	root = nullptr;
	rootNode = nullptr;
	window = nullptr;
	timer = nullptr;
	viewport = nullptr;
	sceneManager = nullptr;
	camera = nullptr;
	keyboard = nullptr;
	mouse = nullptr;
}

OgreFramework::OgreFramework(Ogre::String config, Ogre::String plugins,
		Ogre::String log) {
	configFileName = config;
	pluginsFileName = plugins;
	logFileName = log;
	root = nullptr;
	rootNode = nullptr;
	window = nullptr;
	timer = nullptr;
	viewport = nullptr;
	sceneManager = nullptr;
	camera = nullptr;
	keyboard = nullptr;
	mouse = nullptr;
}

OgreFramework::~OgreFramework() {
}

bool OgreFramework::initOgre() {
	root = new Ogre::Root(configFileName, pluginsFileName, logFileName);
	vector<Ogre::String> plugins;
	plugins.push_back("RenderSystem_GL");
	plugins.push_back("Plugin_ParticleFX");
	plugins.push_back("Plugin_CgProgramManager");
	plugins.push_back("Plugin_OctreeSceneManager");

	for (auto plugin : plugins) {
		root->loadPlugin(plugin);
	}

	const Ogre::RenderSystemList& renderSystemList =
			root->getAvailableRenderers();
	if (renderSystemList.size() == 0) {
		Ogre::LogManager::getSingleton().logMessage(
				"No RenderSystems available.");
		return true;
	}

	Ogre::RenderSystem* renderSystem = renderSystemList[0];
	root->setRenderSystem(renderSystem);
	root->initialise(false, "OpenWorld", "");
	Ogre::NameValuePairList windowParams;
	windowParams["FSAA"] = "0";
	windowParams["vsync"] = "true";
	window = root->createRenderWindow("OpenWorld", 1600, 900, false,
			&windowParams);

	sceneManager = root->createSceneManager(Ogre::ST_GENERIC, "Scene");
	rootNode = sceneManager->getRootSceneNode();

	camera = sceneManager->createCamera("Camera");
	Ogre::SceneNode* cameraNode = rootNode->createChildSceneNode("CameraNode");
	cameraNode->attachObject(camera);

	float lViewportWidth = 1.0f;
	float lViewportHeight = 1.0f;
	float lViewportLeft = (1.0f - lViewportWidth) * 0.5f;
	float lViewportTop = (1.0f - lViewportHeight) * 0.5f;
	unsigned short lMainViewportZOrder = 100;
	viewport = window->addViewport(camera, lMainViewportZOrder, lViewportLeft,
			lViewportTop, lViewportWidth, lViewportHeight);
	viewport->setAutoUpdated(true);
	viewport->setBackgroundColour(Ogre::ColourValue(1, 0, 1));
	float ratio = float(viewport->getActualWidth())
			/ float(viewport->getActualHeight());
	camera->setAspectRatio(ratio);
	camera->setNearClipDistance(1.5f);
	camera->setFarClipDistance(3000.0f);
	window->setActive(true);
	window->setAutoUpdated(false);

	Ogre::ResourceGroupManager& resourceGroupManager =
			Ogre::ResourceGroupManager::getSingleton();
	resourceGroupManager.createResourceGroup("resources");
	resourceGroupManager.addResourceLocation(
			"Z:\\Workspace\\C++\\Games\\OpenWorld\\Debug\\media\\models",
			"FileSystem", "resources", false);
	resourceGroupManager.initialiseResourceGroup("resources");
	resourceGroupManager.loadResourceGroup("resources");

	size_t windowHandle = 0;
	window->getCustomAttribute("WINDOW", &windowHandle);

	std::string windowsHandleAsString = "";
	{
		std::ostringstream windowHndStr;
		windowHndStr << windowHandle;
		windowsHandleAsString = windowHndStr.str();
	}

	OIS::ParamList oisParams;
	oisParams.insert(
			std::make_pair(std::string("WINDOW"), windowsHandleAsString));

	OIS::InputManager* inputManager = OIS::InputManager::createInputSystem(
			oisParams);
	keyboard = (OIS::Keyboard*) inputManager->createInputObject(
			OIS::OISKeyboard, false);
	mouse = (OIS::Mouse*) inputManager->createInputObject(OIS::OISMouse, false);

	const OIS::MouseState &infoSouris = mouse->getMouseState();
	infoSouris.width = window->getWidth();
	infoSouris.height = window->getHeight();

	{
		Ogre::Entity* player = sceneManager->createEntity("sphere.mesh");
		Ogre::SceneNode* playerNode = rootNode->createChildSceneNode();
		playerNode->attachObject((Ogre::MovableObject*) player);
		playerNode->translate(0.0f, 0.0f, -2000.0f);
	}

	return false; // successful exit
}

void OgreFramework::runOgre(GameControl* control) {
	initOgre();

	control->start();
	root->clearEventTimes();

	timer = new Ogre::Timer();
	unsigned long int currentTime = timer->getMicroseconds();
	unsigned long int previousTime = currentTime;
	unsigned long int deltaTime = 0;
	while (!window->isClosed() && !keyboard->isKeyDown(OIS::KC_ESCAPE)) {
		keyboard->capture();
		mouse->capture();

		currentTime = timer->getMicroseconds();
		deltaTime = currentTime - previousTime;
		if (deltaTime != 0) {
			previousTime = currentTime;
			double dDeltaTime = ((double) deltaTime) * 1000.0f;
			control->update(dDeltaTime);
		}
		window->update(true);
		root->renderOneFrame();

		Ogre::WindowEventUtilities::messagePump();
	}

	control->stop();
	delete control;

	stopOgre();
}

void OgreFramework::stopOgre() {

}

Ogre::Root* OgreFramework::getRoot() {
	return root;
}

Ogre::RenderWindow* OgreFramework::getWindow() {
	;
	return window;
}

Ogre::Timer* OgreFramework::getTimer() {
	return timer;
}

Ogre::Viewport* OgreFramework::getViewport() {
	return viewport;
}

Ogre::SceneManager* OgreFramework::getSceneManager() {
	return sceneManager;
}

Ogre::SceneNode* OgreFramework::getRootNode() {
	return rootNode;
}

Ogre::Camera* OgreFramework::getCamera() {
	return camera;
}

OIS::Mouse* OgreFramework::getMouse() {
	return mouse;
}

OIS::Keyboard* OgreFramework::getKeyboard() {
	return keyboard;
}

int main() {
	OgreFramework::initialize();
	OgreFramework::getSingleton()->runOgre(new GameControl());
}
