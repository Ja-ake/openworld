#include "scene.h"

Scene::Scene() {
	attachMember(new Camera());
}

Scene::~Scene() {
}

void Scene::update(double tpf) {

}
