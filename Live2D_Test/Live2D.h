#pragma once
#include"DxLib.h"

class Live2D
{
public:
	Live2D(int modelHandle);
	~Live2D();
	void Initialize();
	void Load(const TCHAR *filePath);
	void Update(const TCHAR* motion);
	void DrawBegin();
	void DrawModel();
	void DrawEnd();
	void DeleteModel();

private:
	int ModelHandle;
};