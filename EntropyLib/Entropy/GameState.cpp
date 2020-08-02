#include "GameState.h"

Entropy::GameState::GameState(const char* stateName, unsigned int numConnections, bool renderFlag, bool gameFlag) : stateName(stateName), renderFlag(renderFlag), gameFlag(gameFlag)
{
	connectedStates = new GameState * [numConnections];
}

void Entropy::GameState::addConnection(unsigned int index, GameState* gamestate)
{
	connectedStates[index] = gamestate;
}
