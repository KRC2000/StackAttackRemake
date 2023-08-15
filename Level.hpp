// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Globals.hpp"

/**
 * @todo write docs
 */
class Level
{
	struct Block
	{
		Block(sf::Vector2i tileSpawnPos, int variant = 0):
		variant(variant), tilePos(tileSpawnPos)
		{
			pos = tilePos * CELLSIZE;
		}
		int variant = 0;
		bool isFalling = true;
		sf::Vector2i pos;
		sf::Vector2i tilePos;
	};

	std::vector<Block*> blocks;
	std::vector<Block*> fallingBlocks;
	Block** map;

public:
	/**
	 * Default constructor
	 */
	Level(sf::Vector2i sizeTiles);
	~Level();
	void spawnBlock(sf::Vector2i tilePos, int variant = 0);
	void update(float delta);
	void draw(sf::RenderTarget & target);

	sf::Vector2i sizeTiles;
	sf::Texture block_t;
	sf::Sprite stamp;
	float blockFallSpeed = 0.5;
private:
	float blockFallTimer = 0;
};

#endif // LEVEL_H
