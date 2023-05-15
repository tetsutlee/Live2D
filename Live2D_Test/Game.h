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
			MessageBox(NULL, L"âÊëúÇÃì«Ç›çûÇ›Ç…é∏îsÇµÇ‹ÇµÇΩ", ERROR, MB_OK);
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
