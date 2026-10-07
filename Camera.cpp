#include<DxLib.h>
#include "Camera.h"
#include "Player.h"

Camera camera_;

//初期化処理
void Camera::Init(void)
{
	//カメラの位置の初期化
	cameraPos = INIT_CAMERA_POS;

}
//更新処理
void Camera::Update(void)
{
	cameraPos.x = player_.GetPos().x;
	cameraPos.y = player_.GetPos().y + 100.0f;
	cameraPos.z = player_.GetPos().z - 500.0f;
}

void Camera::SetBeforeDraw(void)
{
	//SetCameraScreenの後、描画処理の前にカメラを設定すること
	SetCameraPositionAndAngle(
		cameraPos, 0.0f, 0.0f, 0.0f
	);

}

void Camera::Follow(float movePowZ)
{
	cameraPos.z += movePowZ;
}

VECTOR Camera::GetPos(void)
{
	return cameraPos;
}
