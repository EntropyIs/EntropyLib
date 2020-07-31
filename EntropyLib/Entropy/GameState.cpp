#include "GameState.h"

void Entropy::GameState::addConnection(GameState* gamestate)
{
	for (int i = 0; i < connectedStates.size(); i++)
		if (connectedStates[i] == gamestate)
			return;
	connectedStates.push_back(gamestate);
}
