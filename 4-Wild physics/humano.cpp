#include "humano.h"

Humano::Humano() {
    textHumanos[0].loadFromFile("humano1.png");
    textHumanos[1].loadFromFile("humano2.png");
    textHumanos[2].loadFromFile("humano3.png");
    textOps.loadFromFile("oops.png");

    Ops.setTexture(textOps);
    Ops.setPosition(130, 80);

    humanos.setOrigin((float)textHumanos[0].getSize().x / 2, (float)textHumanos[0].getSize().y / 2);
}

void Humano::dibujar(RenderWindow& Ventana) {
    Ventana.draw(humanos);
      if (efectoOps()) {
          Ventana.draw(Ops);
      }
}

void Humano::spawn() {
    int lado = rand() % 4;
    int tipoHumano = rand() % 3;

    humanos.setTexture(textHumanos[tipoHumano]);

    switch (lado) {
    case 0:
        humanos.setPosition(0.0f, 280.8f);
        derecha = true;
        break;
    case 1:
        humanos.setPosition(1200.0f, 280.8f);
        derecha = false;
        break;
    case 2:
        humanos.setPosition(0.0f, 680.6f);
        derecha = true;
        break;
    case 3:
        humanos.setPosition(1200.0f, 680.6f);
        derecha = false;
        break;
    }
    tiempoVivo.restart();
    mostrarOps = false;
}
bool Humano::estaVivo(int mouseX, int mouseY) const {
    return (mouseX >= humanos.getPosition().x - 50 && mouseX <= humanos.getPosition().x + 50 && mouseY >= humanos.getPosition().y - 90 && mouseY <= humanos.getPosition().y + 90);
}

void Humano::mover() {
    float velocidad = 0.4f;
    Vector2f posicionActual = humanos.getPosition();

    if (derecha) {
        posicionActual.x += velocidad;
    }
    else {
        posicionActual.x -= velocidad;
    }
    humanos.setPosition(posicionActual);
}

void Humano::activarEfecto() {
    mostrarOps = true;
    tiempoOps.restart();
}

bool Humano::efectoOps() {
    if (mostrarOps) {
        if (tiempoOps.getElapsedTime().asSeconds() >= 2) {
            mostrarOps = false;
        }
    }
    return mostrarOps;
}

bool Humano::estaFuera() const {
    return (humanos.getPosition().x < 0 || humanos.getPosition().x > 1200);
}