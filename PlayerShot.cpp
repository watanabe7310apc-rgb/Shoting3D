#include <DxLib.h>
#include "PlayerShot.h"

PlayerShot shot_;

void PlayerShot::Init(void)
{
	// プレイヤーの弾モデルのロード
	ModelId = MV1LoadModel("Data/Model/Shot.mv1");
	pos_ = Player::GetPos();
}


void PlayerShot::Update(void)
{
	if (CheckHitKey(KEY_INPUT_SPACE) && !isAlive_)
	{
		pos_ = player_.GetPos();
		isAlive_ = true;
	}

	if (isAlive_)
	{
		pos_.z += PLAYER_SHOT_MOVE_POW_Z;
	}


	//プレイヤーの座標をセットする
	MV1SetPosition(ModelId, pos_);

}

void PlayerShot::Draw(void)
{
	if (!isAlive_)
	{
		return;
	}

	//プレイヤーの弾の描画
	MV1DrawModel(ModelId);

	if (pos_.z > player_.GetPos().z + PLAYER_SHOT_ALIVE_POS_Z)
	{
		isAlive_ = false;
	}
}

void PlayerShot::Release(void)
{
	// プレイヤーの弾モデルの解放
	MV1DeleteModel(ModelId);
}

VECTOR PlayerShot::GetPos(void)
{
	return pos_;
}

bool PlayerShot::IsAlive(void)
{
	return isAlive_;
}

void PlayerShot::SetAlive(bool isAlive)
{
	isAlive_ = isAlive;
}
