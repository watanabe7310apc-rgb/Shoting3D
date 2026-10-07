#include<DxLib.h>
#include "UI.h"
#include "Main.h"
#include "Application.h"
#include "Player.h"

UI ui_;


//初期化処理
void UI::Init(void)
{
	//ゲームオーバー画面のロード
	gameoverModelId = LoadGraph("Data/Image/GameOver.png", false);

	//ゲームクリア画面のロード
	gameclearModelId = LoadGraph("Data/Image/GameClear.png", false);

}

//更新処理
void UI::Update(void)
{

}

//描画処理
void UI::Draw(void)
{

	//ゲームオーバー画面の描画
	if (!player_.IsAlive())
	{
		DrawGraph(((Application::SCREEN_SIZE_X / 2) - 400), ((Application::SCREEN_SIZE_Y / 2) - (250 / 2)), gameoverModelId, true);
	}

	//ゲームオーバー画面の描画
	if (app_.IsGameClear())
	{
		DrawGraph(((Application::SCREEN_SIZE_X / 2) - 400), ((Application::SCREEN_SIZE_Y / 2) - (300 / 2)), gameclearModelId, true);
	}

}

//解放処理
void UI::Release(void)
{
	//ゲームオーバー画面の解放
	DeleteGraph(gameoverModelId, false);

	//ゲームクリア画面の解放
	DeleteGraph(gameclearModelId, false);

}


