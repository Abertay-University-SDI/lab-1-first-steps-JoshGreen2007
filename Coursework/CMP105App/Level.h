#pragma once

#include "Framework/BaseLevel.h"

class Level : BaseLevel{
public:

	enum class Direction { UP, DOWN, LEFT, RIGHT };
	Direction m_direction;

	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	sf::CircleShape m_snake;
	float m_speed = 200.f;

	// Input structure, storing the keyboard inputs
	struct Keyboard {

		int x, y;
		Direction left, right, up, down;

	};

	// Default variables for level class.
	
};