/* Copyright (C) 2018 Ramiro Garay - Ignacio Fucksmann
 * You may use, distribute and modify this code under the
 * terms of the GNU GPL 3 license.
 *
 * You should have received a copy of the GPL license with
 * this file. If not, please visit the GitHub page of this project:
 * https://github.com/Kranioceros/Hexcape
 */

#include "TransitionScene.hpp"
#include <iostream>
#include "Game.hpp"
#include "PlayScene.hpp"
#include <sstream>

TransitionScene::TransitionScene(unsigned _nro_nivel, unsigned int _puntos_jugador) {
	nro_nivel = _nro_nivel;
	nro_nivel++;
	puntos_jugador = _puntos_jugador;

	view.reset(sf::FloatRect(0, 0, 1920, 1080));
	view.setCenter(1920 / 2, 1080 / 2);
	view.zoom(1);
	espera_clock.restart();
	std::stringstream ss;
	ss << "Nivel " << nro_nivel << std::endl;
	std::string str = ss.str();
	font.loadFromFile("fonts/munro.ttf");
	title_text.setFont(font);
	title_text.setString(str);
	title_text.setCharacterSize(50);
	title_text.setOrigin(title_text.getLocalBounds().width / 2.0,
						 title_text.getLocalBounds().height / 2.0);
	title_text.setPosition(1920 / 2, 1080 / 2);
}

void TransitionScene::update(float elapsed, sf::Event e) {
	sf::Time tiempo_espera = espera_clock.getElapsedTime();
	if(tiempo_espera.asSeconds() > 1) {
		espera_clock.restart();
		Game::getInstance().switchScene(
		new PlayScene(nro_nivel, puntos_jugador));
	}
}

void TransitionScene::draw(sf::RenderWindow &w) {
	w.setView(view);
	w.draw(title_text);
}


