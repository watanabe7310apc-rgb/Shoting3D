#include <DxLib.h>
#include "Application.h"


// WinMain関数
//--------------------------------
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
	{

		// ウィンドウサイズ
		SetGraphMode(Application::SCREEN_SIZE_X, Application::SCREEN_SIZE_Y, 32);
		ChangeWindowMode(true);
		// DxLibの初期化
		SetUseDirect3DVersion(DX_DIRECT3D_11);
		if (DxLib_Init() == -1)
		{
			return -1;
		}


		//初期化処理
		app_.Init();

		// ゲームループ
		while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
		{

			//更新処理
			app_.Update();

		// 描画スクリーンの設定
		SetDrawScreen(DX_SCREEN_BACK);


		// 描画スクリーンを初期化
		ClearDrawScreen();

		//描画処理
		app_.Draw();

		// 描画スクリーンの切替
		ScreenFlip();
	}

	//解放処理
		app_.Release();

	// DxLibの後始末
	if (DxLib_End() == -1)
	{
		return -1;
	}


	return 0;
}



