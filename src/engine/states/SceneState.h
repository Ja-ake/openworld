#ifndef SCENESTATE_H_
#define SCENESTATE_H_

class State;

#include "std.h"
#include "engine/base/state.h"
//#include "engine/cms/scene.h"

class SceneState : public State {
public:
	SceneState();
	virtual ~SceneState();

	void update(double);
};

#endif /* SCENESTATE_H_ */
