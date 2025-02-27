#pragma once
#include <SFML/Graphics.hpp>

#include "../Engine/engine.h"
#include "../Engine/gameData/state.h"
#include "../Engine/gameData/stateMachine.h"
#include "../GameClasses/Obstacle.h"
#include "../GameClasses/Nest.h"
#include "../GameClasses/Food.h"
#include "../GameClasses/Ant.h"



class simulationState : public state
{
public:
	simulationState(GameDataRef);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

	enum class STATES
	{
		PLANNER = 0,
		START
	}; STATES state = STATES::PLANNER;

private:
	GameDataRef _data;

	bool obstacle_checked = false;
	bool nest_checked = false;
	bool food_checked = false;
	bool food_checked1 = false;
	bool food_checked2 = false;
	bool nestButton_checked = true;
	bool ant_checked = false;

	/*sf::Text _plannerText;
	sf::Text _foodCounterText;*/

	sf::Sprite _background;
	sf::Sprite _simulationbackButton;
	sf::Sprite _simulationNest;
	sf::Sprite _simulationAnts;
	sf::Sprite _simulationObstacle;
	sf::Sprite _simulationFood;
	sf::Sprite _simulationhelpButton;
	sf::Sprite _stopButton;
	sf::Sprite _startButton;
	sf::Sprite _antTexture;

	Ant* ant;
	Obstacle* obstacle;
	Nest* nest;
	Food* food;

};