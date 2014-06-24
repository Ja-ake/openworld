#ifndef SCENE_H_
#define SCENE_H_

class ComponentManager;

#include "std.h"
#include "engine/base/componentmanager.h"
#include "engine/components/camera.h"

class Scene : public ComponentManager {
public:
	Scene();
	virtual ~Scene();

	void update(double);
};

#endif /* SCENE_H_ */
