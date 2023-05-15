#include"Live2D.h"

Live2D::Live2D(int modelHandle)
	:ModelHandle(modelHandle)
{
	
}

Live2D::~Live2D()
{

}

void Live2D::Initialize()
{

#ifdef _WIN64
	Live2D_SetCubism4CoreDLLPath(L"../CubismSdkForNative-4-r.1/Core/dll/windows/x86_64/Live2DCubismCore.dll");
#else
	Live2D_SetCubism4CoreDLLPath(L"../CubismSdkForNative-4-r.1/Core/dll/windows/x86/Live2DCubismCore.dll");
#endif

}

void Live2D::Load(const TCHAR* filePath)
{
	// Live2Dモデルの読み込み
	ModelHandle = Live2D_LoadModel(filePath);
}

void Live2D::Update(const TCHAR* motion)
{
	// モーション再生が終了していたらアイドリングモーションをランダムで再生
	if (Live2D_Model_IsMotionFinished(ModelHandle) == TRUE)
	{
		Live2D_Model_StartMotion(ModelHandle, motion, GetRand(8));
	}

	// モデルの状態を60分の1秒分進める
	Live2D_Model_Update(ModelHandle, 1 / 60.0f);
}

void Live2D::DrawBegin()
{
	// Live2D描画の開始
	Live2D_RenderBegin();
}

void Live2D::DrawModel()
{
	// モデルの描画
	Live2D_Model_Draw(ModelHandle);
}

void Live2D::DrawEnd()
{
	// Live2D描画の終了
	Live2D_RenderEnd();
}

void Live2D::DeleteModel()
{
	// Live2D モデルの削除
	Live2D_DeleteModel(ModelHandle);
}