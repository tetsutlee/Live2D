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
	// Live2D���f���̓ǂݍ���
	ModelHandle = Live2D_LoadModel(filePath);
}

void Live2D::Update(const TCHAR* motion)
{
	// ���[�V�����Đ����I�����Ă�����A�C�h�����O���[�V�����������_���ōĐ�
	if (Live2D_Model_IsMotionFinished(ModelHandle) == TRUE)
	{
		Live2D_Model_StartMotion(ModelHandle, motion, GetRand(8));
	}

	// ���f���̏�Ԃ�60����1�b���i�߂�
	Live2D_Model_Update(ModelHandle, 1 / 60.0f);
}

void Live2D::DrawBegin()
{
	// Live2D�`��̊J�n
	Live2D_RenderBegin();
}

void Live2D::DrawModel()
{
	// ���f���̕`��
	Live2D_Model_Draw(ModelHandle);
}

void Live2D::DrawEnd()
{
	// Live2D�`��̏I��
	Live2D_RenderEnd();
}

void Live2D::DeleteModel()
{
	// Live2D ���f���̍폜
	Live2D_DeleteModel(ModelHandle);
}