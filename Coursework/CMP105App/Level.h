#pragma once

#include "Framework/BaseLevel.h"

class Level : BaseLevel{
public:

	enum class Direction { NONE, UP, DOWN, LEFT, RIGHT };
	Direction m_direction;

	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();

	void spawnFood();

private:
	// Default functions for rendering to the screen.
	sf::CircleShape m_snake;
	sf::RectangleShape m_food;

	int foodSize = 20;
	int snakeRadius = 15;
	float m_speed = 250.f;

	// Death flag
	bool m_justDied = false;

	// Input structure, storing the keyboard inputs
	struct Keyboard {

		int x, y;
		Direction none, up, down, left, right;

	};
	
};