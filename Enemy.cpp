#include<DxLib.h>
#include "Enemy.h"
#include "Camera.h"

Enemy enemy_;

void Enemy::Init(void)
{
	enemyRota = { 0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f };
	//敵の位置の初期化
	pos_ = INIT_ENEMY_POS;

	// 敵モデルのロード
	enemyModelId = MV1LoadModel("Data/Model/Enemy.mv1");

	//ステージのサイズを設定する
	MV1SetScale(enemyModelId, enemySize);

	//敵の回転を設定する
	MV1SetRotationXYZ(enemyModelId, enemyRota);

	//敵の座標をセットする
	MV1SetPosition(enemyModelId, pos_);

	isAlive_ = true;
}

void Enemy::Update(void)
{
	//敵の再出現処理
	if (pos_.z < camera_.GetPos().z)
	{
		//ランダムな数値を取得する(0～200)
		int rand = GetRand(200);
		//-100～100の数値にする
		rand -= 100;
		pos_.x = rand;
		//エネミーの奥行きを再出現感覚の位置にする
		pos_.z = camera_.GetPos().z + ENEMY_RESPOAWN_POS_Z;

		//エネミーを生存状態にする
		isAlive_ = true;

		//敵の座標をセットする
		MV1SetPosition(enemyModelId, pos_);
	}
}

void Enemy::Draw(void)
{
	if (!isAlive_)
	{
		return;
	}

	//敵の描画
	MV1DrawModel(enemyModelId);

	//衝突判定確認用球体描画
	//DrawSphere3D(enemyPos, 40.0f, 10, 0x0000ff, 0x0000ff, false);

}

void Enemy::Release(void)
{
	// プレイヤーモデルの解放
	MV1DeleteModel(enemyModelId);
}

VECTOR Enemy::GetPos(void)
{
	return pos_;
}

bool Enemy::IsAlive(void)
{
	return isAlive_;
}

void Enemy::SetAlive(bool isAlive)
{
	isAlive_ = isAlive;
}
