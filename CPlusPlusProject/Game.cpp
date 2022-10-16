#include "Game.h"
#include "Time.h"
//Right now, the implementation is pretty simplistic and not amazing. Will make better over time.

void Game::run() {
	initialize();

	//Eventually, make these into separate threads--events and rendering will probably need to be on the first thread, unless I can decouple them.
	while (!exitGame) {
		events();
		fixedUpdate();
		update();
		render();
	}

	onExit();
}


void Game::initialize() {
	physics2D = Physics2D();
	
	window = new sf::RenderWindow(sf::VideoMode(1000, 750), "JC's Game");
	rendering = new Rendering(window);

	colliderPtrs = std::vector<CircleCollider*>();
	rbPtrs = std::vector<Rigidbody2D*>();

	//for (int i = 0; i < 10; i++) {

	//	colliderPtrs.push_back(new CircleCollider(Vector2(i - 5, i - 5), 0.5));
	//	rbPtrs.push_back(new Rigidbody2D(colliderPtrs[i]));

	//	physics2D.trackEntity(rbPtrs[i]);
	//	rendering->trackEntity(rbPtrs[i]->getCollider());

	//	rbPtrs[i]->applyMomentum(Vector2(0, -1));

	//}
	int modifier = 1;
	for (int i = 0; i < 50; ++i) {
		modifier *= -1;
		colliderPtrs.push_back(new CircleCollider(Vector2(i, i * modifier), 0.25));
		colliderPtrs.push_back(new CircleCollider(Vector2(-i, i * modifier), 0.25));
		rbPtrs.push_back(new Rigidbody2D(colliderPtrs[i]));

		rbPtrs[i]->setMass(1);

		physics2D.trackEntity(rbPtrs[i]);
		rendering->trackEntity(rbPtrs[i]->getCollider());

	}

	//colliderPtrs.push_back(new CircleCollider(Vector2(-5, 0), 1));
	//colliderPtrs.push_back(new CircleCollider(Vector2(5, 0), 0.5));
	//colliderPtrs.push_back(new CircleCollider(Vector2(0, 5), 2));

	//rbPtrs.push_back(new Rigidbody2D(colliderPtrs[0]));
	//rbPtrs.push_back(new Rigidbody2D(colliderPtrs[1]));


	//physics2D.trackEntity(rbPtrs[0]);
	//rendering->trackEntity(rbPtrs[0]->getCollider());

	//physics2D.trackEntity(rbPtrs[1]);
	//rendering->trackEntity(rbPtrs[1]->getCollider());

	//rbPtrs[0]->applyMomentum(Vector2(1, 0));
	//rbPtrs[1]->applyMomentum(Vector2(-1, 0));

	//rbPtrs[0]->setMass(2);
	//rbPtrs[1]->setMass(1);
	
}

void Game::events() {
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			exitGame = true;
		}
	}
}

void Game::fixedUpdate() {
	physics2D.updatePhysics();

	Time::tickFixedUpdate();
}

void Game::update() {


	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	Vector2 mouseToWorldPos = rendering->convertToWorldCoordinates(mousePos);

	for (Rigidbody2D* rb : rbPtrs) {
		Vector2 diff = mouseToWorldPos - rb->getCollider()->getPosition();
		rb->applyForce(diff.normalized() * 100);
	}

	Time::tickUpdate();
}

void Game::render() {
	rendering->render();
}

void Game::onExit() {

	delete rendering;

	window->close();
	delete window;

	for (Rigidbody2D* rb : rbPtrs) {
		delete rb;
	}
	for (CircleCollider* col : colliderPtrs) {
		delete col;
	}
}