#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture tex_circu;
Sprite circu;

int main() {
    tex_circu.loadFromFile("circle.png");
    circu.setTexture(tex_circu);
    circu.setScale(100 / (float)tex_circu.getSize().x, 100 / (float)tex_circu.getSize().y);
    circu.setPosition(-100, 400);

    float Vinicial = 0.1f;
    float aceleracion = 0.1f;
    float maxVelocidad = 5.0f;
    float velocidad = Vinicial;
    float posicion = -100.0f;

    RenderWindow ventana(VideoMode(800, 800, 32), "Fast & Furious");
    while (ventana.isOpen()) {
        Event evt;

        while (ventana.pollEvent(evt)) {
            switch (evt.type) {

            case Event::Closed:
                ventana.close();
                break;
            }
        }

        posicion += velocidad;

        if (posicion > 800) {
            posicion = -100;
            if (velocidad + aceleracion <= maxVelocidad) {
                velocidad += aceleracion;
            }
            else {
                velocidad = maxVelocidad;
            }
        }
        circu.setPosition(posicion, 400);
        ventana.clear();
        ventana.draw(circu);
        ventana.display();
    }
    return 0;
}