#include <DxLib.h>
#include "PlayerShot.h"
#include "Enemy.h"

PlayerShot shot_;

void PlayerShot::Init(void)
{
	// プレイヤーの弾モデルのロード
	ModelId = MV1LoadModel("Data/Model/Shot.mv1");
	pos_ = player_.GetPos();
	point_ = { 0.0f,0.0f,0.0f };
	weapon = 1;
	prevSpaceKey = nowSpaceKey = 0;
	homingbullets = MAX_HOMING_SHOT;
}


void PlayerShot::Update(void)
{
	prevSpaceKey = nowSpaceKey;
	nowSpaceKey = CheckHitKey(KEY_INPUT_F);

	if (prevSpaceKey == 0 && nowSpaceKey == 1 && !isAlive_)
	{
		weapon++;
		if (weapon == 3)
		{
			weapon = 1;
		}
	}

	if (CheckHitKey(KEY_INPUT_SPACE) && !isAlive_)
	{
		if (weapon == 1)
		{
			pos_ = player_.GetPos();

			isAlive_ = true;
		}
		else if (weapon == 2 && homingbullets > 0)
		{
			homingbullets--;

			pos_ = player_.GetPos();

			isAlive_ = true;

		}
	}


	if (isAlive_)
	{
		if(weapon==1)
		{
			pos_.z += PLAYER_SHOT_NOMAL_MOVE_POW ;

		}
		else if (weapon == 2 && homingbullets >= 0)
		{
			root.x = enemy_.GetPos().x - pos_.x;
			root.y = enemy_.GetPos().y - pos_.y;
			root.z = enemy_.GetPos().z - pos_.z;

			distance = root.x * root.x + root.y * root.y + root.z * root.z;

			if (distance < 1.0f)distance = 1.0f;

			float k = 90.0f;
			Vec.x = k * root.x / distance;
			Vec.y = k * root.y / distance;
			Vec.z = k * root.z / distance;

			pos_.x += PLAYER_SHOT_MOVE_POW * Vec.x;
			pos_.y += PLAYER_SHOT_MOVE_POW * Vec.y;
			pos_.z += PLAYER_SHOT_MOVE_POW * Vec.z;

		}

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

	if (pos_.z > player_.GetPos().z+PLAYER_SHOT_ALIVE_POS_Z|| pos_.z < player_.GetPos().z - PLAYER_SHOT_ALIVE_POS_Z)
	{
		isAlive_ = false;
	}
}

void PlayerShot::Release(void)
{
	// プレイヤーの弾モデルの解放
	MV1DeleteModel(ModelId);
}

void PlayerShot::ShotMove(void)
{
}

void PlayerShot::SetShotDir(void)
{
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

int PlayerShot::GetWeapon(void)
{
	return weapon;
}

int PlayerShot::GetShot(void)
{
	return homingbullets;
}
