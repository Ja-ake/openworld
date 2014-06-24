#ifndef GRAPHICSCOMPONENT_H_
#define GRAPHICSCOMPONENT_H_

class Component;

#include "std.h"
#include "engine/base/component.h"
#include "engine/ogre/ogreframework.h"

class GraphicsComponent : public Component {
public:
	GraphicsComponent();
	GraphicsComponent(Ogre::SceneNode*);
	virtual ~GraphicsComponent();

	void update(double);
	void render();

	Ogre::SceneNode* getNode();
protected:
	Ogre::SceneNode* node;
};

#endif /* GRAPHICSCOMPONENT_H_ */
