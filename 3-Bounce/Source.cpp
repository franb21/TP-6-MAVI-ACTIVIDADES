#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture tex_circu;
Sprite circu;
Clock tiempo;

int main() {
    tex_circu.loadFromFile("circle.png");
    circu.setTexture(tex_circu);
    circu.setScale(100 / (float)tex_circu.getSize().x, 100 / (float)tex_circu.getSize().y);
    circu.setPosition(400, 100);

    const float gravedad = 300.0f;
    float velocidadY = 0.0f;
    const float rebotePorcentaje = 0.8f;
    float posicion;

    RenderWindow ventana(VideoMode(800, 800, 32), "Bounce");
    while (ventana.isOpen()) {
        Event evt;

        while (ventana.pollEvent(evt)) {
            switch (evt.type) {

            case Event::Closed:
                ventana.close();
                break;
            }
        }

        float tiempoD = tiempo.restart().asSeconds();

        velocidadY += gravedad * tiempoD;

        posicion = circu.getPosition().y + velocidadY * tiempoD;

        if (posicion > 700) {
            posicion = 700;
            velocidadY = -velocidadY * rebotePorcentaje;
        }

        circu.setPosition(400, posicion);
        ventana.clear();
        ventana.draw(circu);
        ventana.display();
    }
    return 0;
}