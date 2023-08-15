// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#include "StackAttack.hpp"

StackAttack::StackAttack(sf::Vector2i sizeTiles, float scale, float startingDifficulty):level(sizeTiles)
{
	// sf::Vector2f windowSize = {level.Stamp.getGlobalBounds().width, level.Stamp.getGlobalBounds().height};
	view.reset(sf::FloatRect(0, 0, 8*sizeTiles.x, 8*sizeTiles.y));
	window.create(sf::VideoMode(view.getSize().x * scale, view.getSize().y * scale), "Stack Attack Remake");
}

void StackAttack::Run()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				// if (event.key.code == sf::Keyboard::Key::Left)
				// 	snake.desiredDirection = Snake::Direction::WEST;
				// if (event.key.code == sf::Keyboard::Key::Right)
				// 	snake.desiredDirection = Snake::Direction::EAST;
				// if (event.key.code == sf::Keyboard::Key::Up)
				// 	snake.desiredDirection = Snake::Direction::NORTH;
				// if (event.key.code == sf::Keyboard::Key::Down)
				// 	snake.desiredDirection = Snake::Direction::SOUTH;
			}
		}


		// snake.Update(Timer.restart().asSeconds());
		level.update(Timer.restart().asSeconds());

		window.clear(sf::Color::Cyan);
		window.setView(view);
		level.draw(window);

		// snake.draw(window);
		window.display();
	}

}
