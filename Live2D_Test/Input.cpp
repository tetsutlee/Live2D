#include"Input.h"

int Input::mousePosX = 0;
int Input::mousePosY = 0;
int Input::mouseLeftButt = 0;
int Input::mouseRightButt = 0;
int Input::mouseMidButt = 0;
char Input::currentKey[256] = { 0 };
char Input::previousKey[256] = { 0 };

void Input::Update() 
{
	GetMousePoint(&mousePosX, &mousePosY);
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) mouseLeftButt++;
	else mouseLeftButt = 0;
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) mouseRightButt++;
	else mouseRightButt = 0;
	if ((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0) mouseMidButt++;
	else mouseMidButt = 0;

	memcpy(previousKey, currentKey, sizeof(previousKey));

	GetHitKeyStateAll(currentKey);
}

void Input::Mouse(int* x, int* y) {
	*x = mousePosX;
	*y = mousePosY;
}

int Input::MouseLeftButton() { return mouseLeftButt; }
int Input::MouseRightButton() { return mouseRightButt; }
int Input::MouseMiddleButton() { return mouseMidButt; }

int Input::Key(int key) {
	return currentKey[key];
}

bool Input::KeyTrigger(int key)
{
	return !previousKey[key] && currentKey[key];
}

void Input::Draw() {

}
