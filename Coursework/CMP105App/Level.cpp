#include "Level.h"
#include <random>
#include <ctime>

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{

	std::cout << "Level constructor working" << std::endl;

	//Set data for when nothing is pressed (after death)
	m_direction = Direction::NONE;

	// Randomise seed
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	// initialise game objects

	// Set up snake
	m_snake.setRadius(snakeRadius);
	m_snake.setPosition({ 300, 300 });
	m_snake.setFillColor(sf::Color::Green);

	// Set up food
	m_food.setSize({ foodSize, foodSize });
	m_food.setPosition({ 100, 100 });
	m_food.setFillColor(sf::Color::Red);
	spawnFood();

}

// handle user input
void Level::handleInput(float dt)
{	

	if (m_input.isLeftMousePressed()){

		std::cout << "left mouse pressed" << std::endl;

	}

	if (m_input.isKeyDown(sf::Keyboard::Scan::W)) {

		std::cout << "W key is pressed" << std::endl;
		m_direction = Direction::UP;

	}

	if (m_input.isKeyDown(sf::Keyboard::Scan::A)) {

		std::cout << "A key is pressed" << std::endl;
		m_direction = Direction::LEFT;

	}

	if (m_input.isKeyDown(sf::Keyboard::Scan::S)) {

		std::cout << "S key is pressed" << std::endl;
		m_direction = Direction::DOWN;

	}

	if (m_input.isKeyDown(sf::Keyboard::Scan::D)) {

		std::cout << "D key is pressed" << std::endl;
		m_direction = Direction::RIGHT;

	}

}

// Update game objects
void Level::update(float dt)
{

	sf::Vector2u window_size = m_window.getSize();

	//Calculate snake's position
	sf::Vector2f snakePos = m_snake.getPosition();
	float radius = m_snake.getRadius();


	if (snakePos.x > window_size.x - radius || snakePos.x < 0 || 
		snakePos.y > window_size.y - radius || snakePos.y < 0) {

		m_snake.setPosition({ window_size.x * 0.5f, window_size.y * 0.5f });
		m_direction = Direction::NONE;
		spawnFood();

		//Set justDied to true
		m_justDied = true;

	}

	if (!m_justDied) {

		switch (m_direction) {

		case Direction::UP:
			m_snake.move({ 0, -m_speed * dt });
			break;

		case Direction::LEFT:
			m_snake.move({ -m_speed * dt, 0.f });
			break;

		case Direction::DOWN:
			m_snake.move({ 0, m_speed * dt });
			break;

		case Direction::RIGHT:
			m_snake.move({ m_speed * dt, 0.f });
			break;

		case Direction::NONE:
			//Do nothing
			break;

		}

	}

	else {

		// Clear the flag after skipping movement once
		m_justDied = false;

	}

}

// Render level
void Level::render()
{
	beginDraw();	
	m_window.draw(m_food);
	m_window.draw(m_snake);

	endDraw();
}

void Level::spawnFood() {

	float x = rand() % (m_window.getSize().x - foodSize);
	float y = rand() % (m_window.getSize().y - foodSize);

	m_food.setPosition({ x, y });

}

