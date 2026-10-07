#include <DxLib.h>
#include "Player.h"
#include "PlayerShot.h"
#include "Application.h"

Player player_;

void Player::Init(void)
{

	//プレイヤー位置の初期化
	pos_ = INIT_PLAYER_POS;

	// プレイヤーモデルのロード
	ModelId = MV1LoadModel("Data/Model/Player.mv1");

	//プレイヤーの生存判定
	isAlive_ = true;

}

void Player::Update(void)
{
	if (isAlive_ && !app_.IsGameClear()) {
		if (isAlive_ == true) {
			//プレイヤーの移動
			if (CheckHitKey(KEY_INPUT_D) == 1)
			{
				if (pos_.x < PLAYER_MOVE_LIMIT_X)
				{
					pos_.x += PLAYER_MOVE_POW_X;
				}
			}

			if (CheckHitKey(KEY_INPUT_A) == 1)
			{
				if (pos_.x > -PLAYER_MOVE_LIMIT_X)
				{
					pos_.x -= PLAYER_MOVE_POW_X;
				}
			}
		}
		pos_.z += PLAYER_MOVE_POW_Z;
	}
	//プレイヤーの座標をセットする
	MV1SetPosition(ModelId, pos_);

}

void Player::Draw(void)
{
	if (!isAlive_)
	{
		return;
	}

	//プレイヤーの描画
	MV1DrawModel(ModelId);

	//衝突判定確認用球体描画
	//DrawSphere3D(playerPos, 80.0f, 10, 0x0000ff, 0x0000ff, false);

}

void Player::Release(void)
{
	// プレイヤーモデルの解放
	MV1DeleteModel(ModelId);

}

VECTOR Player::GetPos(void)
{
	return pos_;
}

bool Player::IsAlive(void)
{
	return isAlive_;
}

void Player::SetAlive(bool isAlive)
{
	isAlive_ = isAlive;
}
