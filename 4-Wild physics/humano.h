#pragma once
#include "libs.h"

class Humano {
private:
    Texture textHumanos[3];
    Texture textOps;
    Sprite humanos; 
    Sprite Ops;
    float x;
    float y;
    Clock tiempoVivo;
    Clock tiempoOps;
    bool mostrarOps = false;
    bool derecha;
public:
    Humano();
    void dibujar(RenderWindow& Ventana);
    void spawn();
    bool estaVivo(int mouseX, int mouseY) const;
    void mover();
    void activarEfecto();
    bool efectoOps();
    bool estaFuera() const;
};