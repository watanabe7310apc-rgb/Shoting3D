#include<DxLib.h>
#include "UI.h"
#include "Application.h"
#include "Player.h"
#include "PlayerShot.h"
#include "Enemy.h"
#include "GameScene.h"

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
	//追尾弾の時のみガイドを表示
	if (shot_.GetWeapon() == 2) {
		DrawLine3D(player_.GetPos(), enemy_.GetPos(), GetColor(0, 255, 0));
	}
	//ゲームオーバー画面の描画
	if (!player_.IsAlive())
	{
		DrawGraph(((Application::SCREEN_SIZE_X / 2) - 400), ((Application::SCREEN_SIZE_Y / 2) - (250 / 2)), gameoverModelId, true);
	}

	//ゲームオーバー画面の描画
	if (game_.IsGameClear())
	{
		DrawGraph(((Application::SCREEN_SIZE_X / 2) - 400), ((Application::SCREEN_SIZE_Y / 2) - (300 / 2)), gameclearModelId, true);
	}

	DrawString(0, 20, "シューティングゲーム", GetColor(255, 255, 255));

	DrawString(0, 40, "2516033_渡邉七海翔", GetColor(255, 255, 255));

	DrawFormatString(0, Application::SCREEN_SIZE_Y - 20,GetColor(255, 255, 255) , "ホーミング弾の残弾 : %d",shot_.GetShot());

	if (shot_.GetWeapon() == 1)
	{
		DrawFormatString(0, Application::SCREEN_SIZE_Y - 40, GetColor(255, 255, 255), "通常弾");
	}
	if (shot_.GetWeapon() == 2)
	{
		DrawFormatString(0, Application::SCREEN_SIZE_Y - 40, GetColor(255, 255, 255), "ホーミング弾");
	}

	DrawFormatString(0, 60, GetColor(255, 255, 255),
		"Player Pos: X=%.1f Y=%.1f Z=%.1f",
		player_.GetPos().x, player_.GetPos().y, player_.GetPos().z);

	DrawFormatString(0, 80, GetColor(255, 255, 255),
		"PlayerShot Pos: X=%.1f Y=%.1f Z=%.1f",
		shot_.GetPos().x, shot_.GetPos().y, shot_.GetPos().z);

}

//解放処理
void UI::Release(void)
{
	//ゲームオーバー画面の解放
	DeleteGraph(gameoverModelId, false);

	//ゲームクリア画面の解放
	DeleteGraph(gameclearModelId, false);

}


