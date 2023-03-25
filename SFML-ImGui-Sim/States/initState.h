#pragma once

#include <SFML/Graphics.hpp>
#include "../Engine/engine.h"
#include "../Engine/gameData/state.h"
#include "imgui.h"
#include "imgui-SFML.h"

class initState : public state
{
public:
	initState(GameDataRef);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
	
private:
	GameDataRef _data;
	
	sf::Sprite _background;
	sf::Sprite _pc;
	sf::Sprite _switch;
	sf::Sprite _router;

	sf::Clock _timer;

};