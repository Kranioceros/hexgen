#include "BaseScene.hpp"
#include <vector>

BaseScene::BaseScene() {
	
}

void BaseScene::update(float elapsed) {	
	for(auto e: entities){
		e->update(elapsed);
	}
	
	// elimina actores
	for(auto d: to_delete){
		auto it = find(entities.begin(), entities.end(), d);
		if(it != entities.end()){
			delete *it;
			entities.erase(it);
		}
	}
	to_delete.clear();
}

void BaseScene::draw(sf::RenderWindow &w){
	for(auto e: entities){
		e->draw(w);
	}
}

void BaseScene::add(Entity *e){
	entities.push_back(e);
}

void BaseScene::remove(Entity *e){
	to_delete.push_back(e);
}

