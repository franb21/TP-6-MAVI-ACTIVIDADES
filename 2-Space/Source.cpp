#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture tex_circu;
Sprite circu;

int main() {
    tex_circu.loadFromFile("circle.png");
    circu.setTexture(tex_circu);
    circu.setScale(100 / (float)tex_circu.getSize().x, 100 / (float)tex_circu.getSize().y);
    circu.setPosition(400, 400);

    float velocidad = 0.0f;
    const float aceleracion = 0.001f;
    const float maxVelocidad = 1.5f;
    float posicion;

    RenderWindow ventana(VideoMode(800, 800, 32), "Space");
    while (ventana.isOpen()) {
        Event evt;

        while (ventana.pollEvent(evt)) {
            switch (evt.type) {

            case Event::Closed:
                ventana.close();
                break;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            velocidad += aceleracion;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left)) {
            velocidad -= aceleracion;
        }

        if (velocidad > maxVelocidad) {
            velocidad = maxVelocidad;
        }
        if (velocidad < -maxVelocidad) {
            velocidad = -maxVelocidad;
        }

        posicion = circu.getPosition().x + velocidad;

        if (posicion > 900) {
            posicion = -100;
        }
        if (posicion < -100) {
            posicion = 900;
        }
        circu.setPosition(posicion, 400);
        ventana.clear();
        ventana.draw(circu);
        ventana.display();
    }
    return 0;
}
