#ifndef CAMERA_H_
#define CAMERA_H_

class Component;

#include "std.h"
#include "engine/base/component.h"
#include "engine/base/state.h"
#include "engine/base/componentmanager.h"
#include "engine/gamecontrol.h"
#include "engine/ogre/ogreframework.h"

class Camera: public Component, public OIS::MouseListener {
public:
	Camera();
	virtual ~Camera();

	void update(double);

	bool mouseMoved(const OIS::MouseEvent &e);
	bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);
private:
	Ogre::Camera* ogreCamera;

	btVector3* position;
	btVector3* target;
	double horizontalRotation, verticalRotation;
	btScalar* distanceFromTarget;

	int _relMouseX, _relMouseY;
};

#endif /* CAMERA_H_ */
