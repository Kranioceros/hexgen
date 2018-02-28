#include "headers/Dibujo.h"

int nroTile(const bool *arr) {
	int res = 0;
	for(int i=0; i < 6; i++) {
		res += arr[i] << (6-i-1);
	}
	return res;
}
void dibujarGrilla(sf::RenderWindow& w, const Grilla &g, const sf::Texture &tileset, const sf::Texture &escotillas, float x, float y) {
	float lado = 150, altura_lado = 130;
	float ancho = 2*altura_lado, alto = 2*lado;

	/* Se crea un vector de sprites, cada uno con su respectivo tile del tileset */
	std::vector<sf::Sprite> sprites(64);
	for(int i=0; i < 64; i++) {
		int fila = i / 8, col = i % 8;
		sprites[i].setTexture(tileset);
		sprites[i].setTextureRect(
			sf::IntRect(ancho*col, alto*fila, ancho, alto+1)
		);
	}

	/* Sprite sencillo con la escotillas cerrada */
	sf::Sprite spr_escotillas; spr_escotillas.setTexture(escotillas);
	spr_escotillas.setTextureRect(sf::IntRect(0, 0, 86, 86));
	spr_escotillas.setOrigin(43, 43);

	for(int xh=0; xh < g.ancho(); xh++) {
		for (int yh=0; yh < g.alto(); yh++) {
			const Celda &c = g.celda(Coordenadas(xh, yh));

			if (c.visible == false)
				continue;

			int xr = x + xh*ancho + yh*altura_lado;
			int yr = y + yh*(3.0/2)*lado;
			int nro_tile = nroTile(c.aberturas);

			spr_escotillas.setPosition(xr + altura_lado, yr + lado);
			sprites[nro_tile].setPosition(xr, yr);
			w.draw(sprites[nro_tile]);
			w.draw(spr_escotillas);
		}
	}
}