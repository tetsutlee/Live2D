#include"Game.h"
#include"Input.h"
#include"Live2D.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//�E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	SetMainWindowText(L"Live2D Test Program");

	// ��ʉ𑜓x��ݒ�
	SetGraphMode(1280, 720, 0);

	//�E�B���h�E�T�C�Y���蓮�ł͕ύX�ł����A
    //���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	bool motionChange = false;

	int live2DHandle = 0;

	Live2D* live2D = new Live2D(live2DHandle);	

	live2D->Initialize();

	// �c�w���C�u��������������
	if (DxLib_Init() == -1) return -1;

	Game game;
	game.Initialize();
	game.Load();

	live2D->Load(L"../Assets/miara_pro_jp/runtime/miara_pro_t04.model3.json");

	// �`���𗠉�ʂɕύX
	SetDrawScreen(DX_SCREEN_BACK);

	// ���C�����[�v
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Input::Update();

		/*if (game.Update() == -1) break;*/
		game.Update();
		game.Draw();

		if (Input::KeyTrigger(KEY_INPUT_SPACE))
		{
			//printfDx("Hello Live2D \n");
			motionChange = !motionChange;
		}

		if (!motionChange)
		{
			live2D->Update(L"Idle");
		}
		else
		{
			live2D->Update(L"Flick");
		}

		live2D->DrawBegin();

		live2D->DrawModel();

		live2D->DrawEnd();

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) break;
	}

	live2D->DeleteModel();

	delete live2D;

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}