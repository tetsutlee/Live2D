#pragma once
#include"DxLib.h"

class Input
{
public:
	static char currentKey[256];
	static char previousKey[256];
	static int mousePosX, mousePosY, mouseLeftButt, mouseRightButt, mouseMidButt;
public:
	static void Mouse(int*, int*);
	static int MouseLeftButton();
	static int MouseRightButton();
	static int MouseMiddleButton();
	static int Key(int key);
	static bool KeyTrigger(int key);
	static void Update();
	static void Draw();

};

