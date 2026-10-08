#pragma once
#include "Player.h"
#include <DxLib.h>


class PlayerShot :	public Player
{
public:
	//初期化処理
	void Init(void);
	//更新処理
	void Update(void);
	//描画処理
	void Draw(void);
	//解放処理
	void Release(void);

	//弾の移動処理
	void ShotMove(void);

	void SetShotDir(void);

	//プレイヤーの弾の移動量(前進)
	const float PLAYER_SHOT_NOMAL_MOVE_POW = 60.0f;

	const float PLAYER_SHOT_MOVE_POW = 800.0f;

	//プレイヤーの弾の生存距離
	const float PLAYER_SHOT_ALIVE_POS_X = 6000.0f;
	const float PLAYER_SHOT_ALIVE_POS_Y = 6000.0f;
	const float PLAYER_SHOT_ALIVE_POS_Z = 6000.0f;

	//追尾弾の最大数
	const int MAX_HOMING_SHOT = 10;

	//プレイヤーの弾の当たり判定
	static constexpr float RADIUS = 30.0f;

	//プレイヤーの弾の座標
	VECTOR pos_;

	//座標の取得
	VECTOR GetPos(void);

	//生存判定
	bool IsAlive(void);

	//生存判定の設定
	void SetAlive(bool isAlive);

	//現在の武装の取得
	int GetWeapon(void);

	//現在の武装の取得
	int GetShot(void);

	VECTOR Vec;
private:

	//プレイヤーから敵までの距離ベクトル
	VECTOR root;

	//プレイヤーから敵までの距離の2乗
	float distance;

	//プレイヤーの弾のロード
	int ModelId = -1;

	//プレイヤーの弾の生存判定
	bool isAlive_ = false;

	VECTOR point_;

	//武装の切り替え
	int weapon;

	int homingbullets;

	int prevSpaceKey, nowSpaceKey;   //スペースキーの状態を保存する変数

};
extern PlayerShot shot_;

