#include"Game.h"
#include"Input.h"
#include"Live2D.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	SetMainWindowText(L"Live2D Test Program");

	// 画面解像度を設定
	SetGraphMode(1280, 720, 0);

	//ウィンドウサイズを手動では変更できず、
    //かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	bool motionChange = false;

	int live2DHandle = 0;

	Live2D* live2D = new Live2D(live2DHandle);	

	live2D->Initialize();

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	Game game;
	game.Initialize();
	game.Load();

	live2D->Load(L"../Assets/miara_pro_jp/runtime/miara_pro_t04.model3.json");

	// 描画先を裏画面に変更
	SetDrawScreen(DX_SCREEN_BACK);

	// メインループ
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

	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了
	return 0;
}