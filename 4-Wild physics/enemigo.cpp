#include "enemigo.h"

Enemigo::Enemigo() {
    textAliens[0].loadFromFile("enemigo1.png");
    textAliens[1].loadFromFile("enemigo2.png");
    textAliens[2].loadFromFile("enemigo3.png");
    textZap.loadFromFile("zap.png");

    zap.setTexture(textZap);
    zap.setPosition(345, 240);

    aliens.setOrigin((float)textAliens[0].getSize().x / 2, (float)textAliens[0].getSize().y / 2);
}

void Enemigo::dibujar(RenderWindow& Ventana) {
    Ventana.draw(aliens);
    if (efectoZap()) {
        Ventana.draw(zap);
    }
}

void Enemigo::spawn() {
    int lado = rand() % 4;
    int tipoAlien = rand() % 3;

    aliens.setTexture(textAliens[tipoAlien]);

    switch (lado) {
    case 0:
        aliens.setPosition(0.0f, 280.8f);
        derecha = true;
        break;
    case 1:
        aliens.setPosition(1200.0f, 280.8f);
        derecha = false;
        break;
    case 2:
        aliens.setPosition(0.0f, 680.6f);
        derecha = true;
        break;
    case 3:
        aliens.setPosition(1200.0f, 680.6f);
        derecha = false;
        break;
    }

    tiempoVivo.restart();
    mostrarZap = false;
}
bool Enemigo::estaVivo(int mouseX, int mouseY) const {
    return (mouseX >= aliens.getPosition().x - 45 && mouseX <= aliens.getPosition().x + 45 && mouseY >= aliens.getPosition().y - 100 && mouseY <= aliens.getPosition().y + 100);
}

void Enemigo::mover() {
    float velocidad = 0.4f;
    Vector2f posicionActual = aliens.getPosition();

    if (derecha) {
        posicionActual.x += velocidad;
    }
    else {
        posicionActual.x -= velocidad;
    }
    aliens.setPosition(posicionActual);
}

void Enemigo::mostrarZapp() {
    mostrarZap = true;
    tiempoZap.restart();
}

bool Enemigo::efectoZap() {
    if (mostrarZap) {
        if (tiempoZap.getElapsedTime().asSeconds() >= 2) {
            mostrarZap = false;
            return false;
        }
        return true;
    }
    return false;
}

bool Enemigo::estaFuera() const {
    return (aliens.getPosition().x < 0 || aliens.getPosition().x > 1200);
}