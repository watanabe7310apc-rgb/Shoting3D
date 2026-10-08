#include "GameScene.h"
#include "Application.h"
#include "Player.h"
#include "PlayerShot.h"
#include "Enemy.h"
#include "Camera.h"
#include "Stage.h"
#include "Blast.h"
#include "UI.h"

GameScene game_;

void GameScene::Init(void)
{

	player_.Init();

	enemy_.Init();

	shot_.Init();

	camera_.Init();

	stage_.Init();

	blast_.Init();

	ui_.Init();

	//ゲームクリア判定
	isGameClear = false;
}

void GameScene::Update(void)
{

	Collision();

	player_.Update();

	enemy_.Update();

	shot_.Update();

	camera_.Update();

	stage_.Update();

	//if (player_.GetPos().z > CLEAR_POS_Z)
	//{
	//	isGameClear = true;
	//}
}

void GameScene::Draw(void)
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




}

void GameScene::Release(void)
{
	player_.Release();

	enemy_.Release();

	shot_.Release();

	stage_.Release();

	blast_.Release();

	ui_.Release();

}

bool GameScene::IsGameClear(void)
{
	return isGameClear;
}

void GameScene::Collision(void)
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
			//敵の生存判定を更新
			enemy_.SetAlive(false);

			//プレイヤーの弾の生存判定を更新
			shot_.SetAlive(false);

			//爆発アニメーション開始判定を更新
			blast_.SetBlast(true);

			//爆発アニメーションの座標を更新
			blast_.SetPos(enemyPos);

		}
	}

}
