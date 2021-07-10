#pragma once
#include"DxLib.h"
#include"Timer.h"

class Game 
{
public:
	Game();
	~Game();
	void Initialize();
	void Load();
	void Update();//Original with "int Update()";
	void Draw();

public:
	int LoadTexture(TCHAR* fileName) 
	{
		int tex = LoadGraph(fileName);
		if (tex == -1) {
			MessageBox(NULL, "画像の読み込みに失敗しました", ERROR, MB_OK);
			return 0;
		}
	};

	//For test
private:
	int texture;
	float texturePosX;
	float texturePosY;
	bool controllSwitch;
	Timer* timer;
};
