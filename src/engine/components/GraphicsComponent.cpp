#include "graphicscomponent.h"

GraphicsComponent::GraphicsComponent() {
	node = OgreFramework::getSingleton()->getRootNode()->createChildSceneNode();
}

GraphicsComponent::GraphicsComponent(Ogre::SceneNode* baseNode) {
	node = baseNode->createChildSceneNode();
}

GraphicsComponent::~GraphicsComponent() {
}

void GraphicsComponent::render() {

}

void GraphicsComponent::update(double tpf) {
	render();
}

Ogre::SceneNode* GraphicsComponent::getNode() {
	return node;
}
