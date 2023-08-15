// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#ifndef STACKATTACK_H
#define STACKATTACK_H

#include <SFML/Graphics.hpp>

#include "Level.hpp"
/**
 * @todo write docs
 */
class StackAttack
{
public:
    /**
     * Default constructor
     */
    StackAttack(sf::Vector2i sizeTiles, float scale, float startingDifficulty);
		StackAttack();
		void Run();

		sf::View view;
		sf::RenderWindow window;
		Level level;

		sf::Clock Timer;
};

#endif // STACKATTACK_H
