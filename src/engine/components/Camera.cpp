#include "camera.h"

Camera::Camera() {
	ogreCamera = OgreFramework::getSingleton()->getCamera();
	position = new btVector3(0.0f, 0.0f, 0.0f);
	horizontalRotation = verticalRotation = 0;
	target = new btVector3(1.0f, 0.0f, 0.0f);
	distanceFromTarget = new btScalar(100.0f);

	_relMouseX = _relMouseY = 0;

	((GameControl*)((State*)((ComponentManager*)this->manager())->state())->app())->registerMouseListener(this);
}

Camera::~Camera() {
}

void Camera::update(double tpf) {
	horizontalRotation += (double) _relMouseX * tpf;
	verticalRotation += (double) _relMouseY * tpf;
	_relMouseX = 0;
	_relMouseY = 0;

	double y = ((double) *distanceFromTarget) * cos(verticalRotation);
	double x = ((double) *distanceFromTarget) * sin(verticalRotation) * cos(horizontalRotation);
	double z = ((double) *distanceFromTarget) * sin(verticalRotation) * sin(horizontalRotation);
	*position = *target - btVector3(x, y, z);

	ogreCamera->setPosition(position->x(), position->y(), position->z());
	ogreCamera->lookAt(target->x(), target->y(), target->z());
}

bool Camera::mouseMoved(const OIS::MouseEvent &e) {
	_relMouseX += e.state.X.rel;
	_relMouseY += e.state.Y.rel;
	return true;
}

bool Camera::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id) {

	return true;
}

bool Camera::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id) {

	return true;
}
