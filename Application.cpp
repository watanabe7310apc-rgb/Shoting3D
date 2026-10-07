#include <DxLib.h>
#include "Application.h"
#include "Player.h"
#include "PlayerShot.h"
#include "Enemy.h"
#include "Camera.h"
#include "Stage.h"
#include "Blast.h"
#include "UI.h"

Application app_;

void Application::Init(void)
{
	player_.Init();

	enemy_.Init();

	shot_.Init();

	camera_.Init();

	stage_.Init();

	blast_.Init();

	ui_.Init();

	//乱数のシード値を設定する
	DATEDATA date;

	//現在時刻を取得する
	GetDateTime(&date);

	//乱数の初期値を設定する
	//設定する数値によって、ランダムの出方が変わる
	SRand(date.Year + date.Mon + date.Day + date.Hour + date.Min + date.Sec);


	//ゲームクリア判定
	isGameClear = false;
}

void Application::Update(void)
{
	Collision();

	player_.Update();

	enemy_.Update();

	shot_.Update();

	camera_.Update();

	stage_.Update();

	if (player_.GetPos().z > CLEAR_POS_Z)
	{
		isGameClear = true;
	}
}

void Application::Draw(void)
{
	//カメラの設定
	camera_.SetBeforeDraw();

	//プレイヤーの表示
	player_.Draw();

	//敵の表示
	enemy_.Draw();

	//プレイヤーの弾の表示
	shot_.Draw();

	//ステージの表示
	stage_.Draw();

	//爆発アニメーション
	blast_.Draw();

	//UIの表示
	ui_.Draw();


	DrawString(0, 20, "シューティングゲーム", 0xfffffff);
	DrawString(0, 40, "2516033_渡邉七海翔", 0xfffffff);
	DrawFormatString(0, 60, GetColor(255, 255, 255),
		"Player Pos: X=%.1f Y=%.1f Z=%.1f",
		player_.GetPos().x, player_.GetPos().y, player_.GetPos().z);

}

void Application::Release(void)
{
	player_.Release();

	enemy_.Release();

	shot_.Release();

	stage_.Release();

	blast_.Release();

	ui_.Release();

}

bool Application::IsGameClear(void)
{
	return isGameClear;
}

void Application::Collision(void)
{
	//プレイヤーの座標をあらかじめ取得する
	VECTOR playerPos = player_.GetPos();

	//プレイヤーの弾の座標をあらかじめ取得する
	VECTOR playerShotPos = shot_.GetPos();

	//敵の座標をあらかじめ取得する
	VECTOR enemyPos = enemy_.GetPos();

	if (player_.IsAlive() && enemy_.IsAlive())
	{

		//2つの座標間の距離をピタゴラスの定理で算出
		VECTOR distance;

		//プレイヤーと敵の当たり判定
		float range = Player::RADIUS + Enemy::RADIUS;

		distance.x = enemyPos.x - playerPos.x;
		distance.y = enemyPos.y - playerPos.y;
		distance.z = enemyPos.z - playerPos.z;

		float dis = distance.x * distance.x + distance.y * distance.y + distance.z * distance.z;

		if (dis < range * range)
		{
			//プレイヤーの生存判定を更新
			player_.SetAlive(false);

			//爆発アニメーション開始判定を更新
			blast_.SetBlast(true);

			//爆発アニメーションの座標を更新
			blast_.SetPos(playerPos);
		}
	}

	if (shot_.IsAlive() && enemy_.IsAlive())
	{
		//2つの座標間の距離をピタゴラスの定理で算出
		VECTOR distance;

		//プレイヤーの弾と敵の当たり判定
		float range = PlayerShot::RADIUS + Enemy::RADIUS;


		distance.x = playerShotPos.x - enemyPos.x;
		distance.y = playerShotPos.y - enemyPos.y;
		distance.z = playerShotPos.z - enemyPos.z;

		float dis = distance.x * distance.x
			+ distance.y * distance.y + distance.z * distance.z;

		if (dis < range * range)
		{
			//プレイヤーの生存判定を更新
			enemy_.SetAlive(false);

			//爆発アニメーション開始判定を更新
			blast_.SetBlast(true);

			//爆発アニメーションの座標を更新
			blast_.SetPos(enemyPos);

		}
	}

}

