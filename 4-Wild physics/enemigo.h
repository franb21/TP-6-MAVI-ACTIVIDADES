#pragma once
#include "libs.h"

class Enemigo {
private:
    Texture textAliens[3];
    Texture textZap;
    Sprite aliens;
    Sprite zap;
    float x;
    float y;
    Clock tiempoVivo;
    Clock tiempoZap;
    bool mostrarZap = false;
    bool derecha;
public:
    Enemigo();
    void dibujar(RenderWindow& Ventana);
    void spawn();
    bool estaVivo(int mouseX, int mouseY) const;
    bool efectoZap();
    void mover();
    void mostrarZapp();
    bool estaFuera() const;
};