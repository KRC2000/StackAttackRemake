#include <cstring>
#include <string>
#include "Argumentator.hpp"
#include "StackAttack.hpp"

int main(int argc, char *argv[])
{
	int sizeX, sizeY;
	float zoom, dificulty;
	zoom = dificulty = 2.f;
	sizeX = 7;
	sizeY = 4;

	Argumentator::getIntValue(argc, argv, "-w", sizeX);
	Argumentator::getIntValue(argc, argv, "-h", sizeY);
	Argumentator::getFloatValue(argc, argv, "-z", zoom);
	Argumentator::getFloatValue(argc, argv, "-d", dificulty);

	StackAttack game({sizeX, sizeY}, zoom, dificulty);

	game.Run();

	return 0;

}
