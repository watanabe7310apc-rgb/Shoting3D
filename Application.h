#pragma once
#include <DxLib.h>

class Application
{
public:


	//当たり判定
	void Collision(void);

	//初期化処理
	void Init(void);
	//更新処理
	void Update(void);
	//描画処理
	void Draw(void);
	//解放処理
	void Release(void);

	static constexpr int SCREEN_SIZE_X = 1280;
	static constexpr int SCREEN_SIZE_Y = 720;


	//ゴール地点の設定
	const float CLEAR_POS_Z = 20000.0f;

	bool IsGameClear(void);


private:


	//ゲームクリア判定
	bool isGameClear;

};

extern Application app_;
