#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	m_snake.setRadius(15);
	m_snake.setPosition({ 300, 300 });
	m_snake.setFillColor(sf::Color::Green);

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

	sf::Vector2f pos = m_snake.getPosition();
	float radius = m_snake.getRadius();
	sf::Vector2u window_size = m_window.getSize();

	if (pos.x > window_size.x - radius || pos.x < 0) {

		m_snake.setPosition({ window_size.x * 0.5f, window_size.y * 0.5f });

	}

	if (pos.y > window_size.y - radius || pos.y < 0) {

		m_snake.setPosition({ window_size.x * 0.5f, window_size.y * 0.5f });

	}

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

	}

}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_snake);
	endDraw();
}

