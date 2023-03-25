#include <iostream>
#include <sstream>

#include "initState.h"
//#include "menuState.h"
#include "../definitions.h"

initState::initState(GameDataRef data) : _data(data)
{
}

void initState::Init()
{
	//ImGui::SFML::Init(this->_data->window);
	//ImGui::CreateContext();
	this->_data->assets.LoadTexture("init_Background", INIT_STATE_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("pc_shape", PC_FILEPATH);
	this->_data->assets.LoadTexture("Switch_shape", SWITCH_FILEPATH);
	this->_data->assets.LoadTexture("Router_shape", ROUTER_FILEPATH);

	//this->_data->assets.LoadFont("pixelBit_Font", PIXEL_FONT_FILEPATH);

	_background.setTexture(this->_data->assets.GetTexture("init_Background"));
	_pc.setTexture(this->_data->assets.GetTexture("pc_shape"));
	_switch.setTexture(this->_data->assets.GetTexture("Switch_shape"));
	_router.setTexture(this->_data->assets.GetTexture("Router_shape"));

	_pc.setPosition(sf::Vector2f(SCREEN_WIDTH / 4, (SCREEN_HEIGHT / 4)));
	_switch.setPosition(sf::Vector2f(SCREEN_WIDTH *2/ 4, (SCREEN_HEIGHT *2/ 4)));
	_router.setPosition(sf::Vector2f(SCREEN_WIDTH *3/ 4, (SCREEN_HEIGHT *3/ 4)));

	/*_initText.setString("pREss <spAcE> To conTinuE...");
	_initText.setCharacterSize(32);
	_initText.setOrigin(sf::Vector2f(_initText.getGlobalBounds().width / 2, _initText.getGlobalBounds().height / 2));
	_initText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - _initText.getCharacterSize()));
	_initText.setFillColor(sf::Color::Color(129, 178, 154));*/
}

void initState::HandleInput()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(event);
		if (event.type == sf::Event::Closed)
		{
			this->_data->window.close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				this->_data->window.close();
			/*if (event.key.code == sf::Keyboard::Space)
				_data->machine.AddState(StateRef(new menuState(this->_data)));*/
		}
	}
	
}





void initState::Update(float dt)
{
	ImGui::SFML::Update(this->_data->window, _timer.restart());
	
	ImGui::Begin("Window title");
	ImGui::Text("Window text!");
	ImGui::Button("heelo");
	ImGui::End();
	ImGui::EndFrame();
	
	//if (_timer.getElapsedTime().asSeconds() > 0.15)
	//{
	//	if ((_timer.getElapsedTime().asSeconds() > 1))
	//	{
	//		//_initText.setFillColor(sf::Color::Color(0, 0, 0, 0));
	//		_timer.restart();
	//	}
	//	else
	//	{
	//		//_initText.setFillColor(sf::Color::Color(129, 178, 154));
	//	}
	//}
}

void initState::Draw(float dt)
{
	this->_data->window.clear();
	
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_pc);
	this->_data->window.draw(this->_switch);
	this->_data->window.draw(this->_router);
	
	//this->_data->window.draw(this->_initText);
	ImGui::SFML::Render(this->_data->window);

	this->_data->window.display();

}
