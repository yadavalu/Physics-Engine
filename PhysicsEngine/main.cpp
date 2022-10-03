#include "Debug.h"

/*
#include "DifferentialEquation/EDE.h"

float dy_dx(float x, float y) {
	return x + y;
}

int main(int argc, char* argv[]) {
	EDE de(dy_dx, 0, 1);
	DEBUG(de.y(0.3, 0.1));
}
*/

#include <SFML/Graphics.hpp>

#include "System.h"


int main(int argc, char* argv[]) 
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Test");

	struct Object obj = { Vector3(200, 100), Vector3(20, -10), Vector3(0, 0), 20.0f};
	struct Object obj2 = { Vector3(700, 100), Vector3(-50, -10), Vector3(0, 0), 50.0f };

	struct RigidObject robj = { Vector3(0, 700), Vector3(0, 0), Vector3(0, 0), 100, Vector3(0, 9.81), 1, 1, 1 };
	struct RigidObject robj2 = { Vector3(0, 0), Vector3(0, 0), Vector3(0, 0), 100, Vector3(-9.81, 0), 1, 1, 1 };

	System system(Vector3(0, 0, 0), 800, 800, true);
	system.AddObject(&obj);
	system.AddObject(&obj2);
	system.AddRigidObject(&robj);
	system.AddRigidObject(&robj2);

	sf::RectangleShape rect(sf::Vector2f(20, 20));
	obj.SetSize(Vector2(20, 20));
	rect.setPosition(obj.position.GetXComponent(), obj.position.GetYComponent());

	sf::RectangleShape rect2(sf::Vector2f(50, 50));
	obj2.SetSize(Vector2(50, 50));
	rect2.setPosition(obj2.position.GetXComponent(), obj2.position.GetYComponent());

	sf::RectangleShape base(sf::Vector2f(800, 100));
	robj.SetSize(Vector2(800, 100));
	base.setPosition(robj.position.GetXComponent(), robj.position.GetYComponent());

	sf::RectangleShape base2(sf::Vector2f(100, 800));
	robj2.SetSize(Vector2(100, 800));
	base2.setPosition(robj2.position.GetXComponent(), robj2.position.GetYComponent());

	sf::Clock clock;
	sf::Event event;
	while (window.isOpen()) {
		float dt = clock.restart().asSeconds();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}

		system.Step(dt);
		system.ResolveCollisions();

		rect.setPosition(obj.position.GetXComponent(), obj.position.GetYComponent());
		rect2.setPosition(obj2.position.GetXComponent(), obj2.position.GetYComponent());
		base.setPosition(robj.position.GetXComponent(), robj.position.GetYComponent());
		base2.setPosition(robj2.position.GetXComponent(), robj2.position.GetYComponent());

		window.clear();
		window.draw(rect);
		window.draw(rect2);
		window.draw(base);
		window.draw(base2);
		window.display();
	}


	return 0;
}


