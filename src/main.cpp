#include "Game.hpp"
#include "BaseScene.hpp"
#include "PlayScene.hpp"

using namespace sf;

int main(int argc, char *argv[]){
	BaseScene *scene = new PlayScene(0.2);
	Game &g = Game::create(sf::VideoMode(1920, 1080), scene, "Hexcape 0.001-pre-alpha");
	g.run();
	
	return 0;
}

