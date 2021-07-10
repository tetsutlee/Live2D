#include"Game.h"
#include"Input.h"

Game::Game() 
{
	this->Initialize();
}

Game::~Game() 
{

}

void Game::Initialize() 
{
	texture = NULL;
	texturePosX = 600;
	texturePosY = 400;
	controllSwitch = false;
	timer = new Timer(5.0f);
}

void Game::Load() 
{
	//For Test
	//texture = LoadTexture((TCHAR*)"../Assets/particle.jpg");
}

void Game::Update() {
	//For Test
	if (!controllSwitch) 
	{
		texturePosX = 600;
		texturePosY = 400;
	}
	else
	{
		texturePosX = 800;
		texturePosY = 600;
	}
	if (Input::Key(KEY_INPUT_SPACE) == 1) {
		controllSwitch = !controllSwitch;
	}

}

void Game::Draw() 
{
	//For test
	//DrawRotaGraph2(texturePosX / 2, texturePosY / 2, 40, 40, 1.0f, 0.0f, texture, FALSE, FALSE);
}