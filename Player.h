#pragma once
#include <DxLib.h>

class Player
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

	//プレイヤーの初期位置
	static constexpr VECTOR INIT_PLAYER_POS = { 0.0f, 60.0f, 0.0f };

	//プレイヤーの移動量(横)
	const float PLAYER_MOVE_POW_X = 10.0f;

	//プレイヤーの移動量(前進)
	const float PLAYER_MOVE_POW_Z = 20.0f;

	//プレイヤーの移動制限
	const float PLAYER_MOVE_LIMIT_X = 400.0f;

	//プレイヤーの衝突判定用半径
	static constexpr float RADIUS = 80.0f;

	//座標の取得
	VECTOR GetPos(void);

	//生存判定の取得
	bool IsAlive(void);

	//生存判定の切り替え
	void SetAlive(bool isAlive);

private:


	// プレイヤーモデルのロード
	int ModelId = -1;

	//プレイヤーの生存判定
	bool isAlive_;

	//プレイヤーの座標
	VECTOR pos_;

};

extern Player player_;

