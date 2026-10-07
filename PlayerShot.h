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

	//プレイヤーの弾の移動量(前進)
	const float PLAYER_SHOT_MOVE_POW_Z = 80.0f;

	//プレイヤーの弾の生存距離
	const float PLAYER_SHOT_ALIVE_POS_Z = 6000.0f;

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
private:

	//プレイヤーの弾のロード
	int ModelId = -1;

	//プレイヤーの弾の生存判定
	bool isAlive_ = false;

};
extern PlayerShot shot_;

