#pragma once
#include <DxLib.h>

class Enemy
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

	//敵の初期位置
	static constexpr VECTOR INIT_ENEMY_POS = { 80.0f, 100.0f, 4000.0f };

	//敵の再出現位置
	const float ENEMY_RESPOAWN_POS_Z = 4000.0f;

	//敵の衝突判定用半径
	static constexpr float RADIUS = 40.0f;

	//座標の取得
	VECTOR GetPos(void);

	//生存判定の取得
	bool IsAlive(void);

	//生存判定の設定
	void SetAlive(bool isAlive);

private:


	//敵のサイズ
	VECTOR enemySize = { 0.1f, 0.1f, 0.1f };

	//敵の回転
	VECTOR enemyRota = { 0.0f, 0.0f, 0.0f };

	//爆発座標
	VECTOR blastPos = { 0.0f, 0.0f, 0.0f };


	VECTOR pos_;

	// 敵モデルのロード
	int enemyModelId = -1;

	//敵の生存判定
	bool isAlive_;

};
extern Enemy enemy_;

