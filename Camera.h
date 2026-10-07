#pragma once
#include <DxLib.h>

class Camera
{
public:
	//初期化処理
	void Init(void);
	//更新処理
	void Update(void);
	//描画処理
	void SetBeforeDraw(void);

	//座標の取得
	VECTOR GetPos(void);

	//カメラの追従
	void Follow(float movePowZ);

private:


	//カメラの初期位置
	static constexpr VECTOR INIT_CAMERA_POS = { 0.0f, 150.0f, -500.0f };

	//カメラの位置
	VECTOR cameraPos;

};

extern Camera camera_;

