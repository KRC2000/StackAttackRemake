// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#include "Level.hpp"

#include "Globals.hpp"

Level::Level(sf::Vector2i sizeTiles):sizeTiles(sizeTiles)
{
	map = new Block*[sizeTiles.x * sizeTiles.y]{NULL};

	spawnBlock({0, 3}, 3);
	spawnBlock({0, 2}, 3);
	spawnBlock({0, 1}, 3);
	spawnBlock({0, 0}, 3);
	// spawnBlock({4, 1}, 5);

	block_t.loadFromFile("res/blocks.png");
	stamp.setTexture(block_t);
}

Level::~Level()
{
	for (Block* b : blocks)
	{
		delete b;
	}
}

void Level::spawnBlock(sf::Vector2i tilePos, int variant)
{
	if (tilePos.x < sizeTiles.x && tilePos.y < sizeTiles.y &&
		tilePos.x >= 0 && tilePos.y >= 0)
	{
		Block* b = new Block(tilePos, variant);
		blocks.push_back(b);
		fallingBlocks.push_back(b);
		map[tilePos.x*sizeTiles.y+tilePos.y] = b;
	}
}

void Level::update(float delta)
{
	blockFallTimer += delta;

	if (blockFallTimer >= blockFallSpeed)
	{
		blockFallTimer = 0;

		std::vector<Block*> bToDelete;
		for (Block* b : fallingBlocks)
		{
			b->pos += {0, 1};

			// When the falling block has moved to the next cell by most of its surface
			if (b->pos.y % CELLSIZE == CELLSIZE / 2 + 1)
			{
				map[b->tilePos.x*sizeTiles.y+b->tilePos.y] = NULL;
				map[b->tilePos.x*sizeTiles.y+b->tilePos.y+1] = b;
				b->tilePos.y += 1;
			}

			// When falling block position is alligned with cell
			if (b->pos.y % CELLSIZE == 0)
			{
				Block* b_under = map[b->tilePos.x*sizeTiles.y+b->tilePos.y+1];
				if ((b_under && !b_under->isFalling) || b->tilePos.y == sizeTiles.y-1)
				{
					b->isFalling = false;
					bToDelete.push_back(b);
				}
			}
		}
		// Remove this block from list of falling
		for (int i = 0; i < fallingBlocks.size(); i++)
		{
			for (Block* b : bToDelete)
			{
				if (fallingBlocks[i] == b)
				{
					printf("removed\n");
					fallingBlocks.erase(fallingBlocks.begin() + i);
				}
			}

		}

	}

}

void Level::draw(sf::RenderTarget& target)
{
	for (Block* b : blocks)
	{
		stamp.setTextureRect({CELLSIZE*b->variant, 0, CELLSIZE, CELLSIZE});
		stamp.setColor((b->isFalling) ? sf::Color::White : sf::Color::Red);
		stamp.setPosition(b->pos.x, b->pos.y);
		target.draw(stamp);
	}
	// for (int x = 0; x < sizeTiles.x; x++)
	// {
	// 	for (int y = 0; y < sizeTiles.y; y++)
	// 	{
	// // for (int x = 0; x < sizeTiles.x; x++)
	// // {
	// // 	for (int y = 0; y < sizeTiles.y; y++)
	// // 	{
	// 		int index = x*sizeTiles.y+y;
	// 		if (map[index])
	// 		{
	// 			int variant = map[index]->variant;
	// 			printf("(%i)(%i;%i): %i\n", index, x, y, variant);
	// 			stamp.setTextureRect({CELLSIZE*variant, 0, CELLSIZE, CELLSIZE});
	// 			stamp.setPosition(CELLSIZE*x, CELLSIZE*y);
	// 			target.draw(stamp);
	// 		}
	// 	}
	// }
	// printf("\n");
}

