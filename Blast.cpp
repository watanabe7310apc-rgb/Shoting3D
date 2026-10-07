#include <DxLib.h>
#include "Blast.h"
#include "Player.h"

Blast blast_;

//初期化処理
void Blast::Init(void)
{
	//爆発画像のロード
	LoadDivGraph("Data/Image/Blast.png", BLAST_ALL_NUM, BLAST_X_NUM, BLAST_Y_NUM,
		BLAST_X_SIZE, BLAST_Y_SIZE, blastImgs);

	//爆発アニメーション用のカウンタ
	blastImgAnimCount = 0;

	//爆発画像の判定
	isBlast_ = false;

	//爆発判定
	nowBlast = false;

	pos_ = { 0.0f, 0.0f, 0.0f };
}

//更新処理
void Blast::Update(void)
{

}

//描画処理
void Blast::Draw(void)
{
	if (!isBlast_)
	{
		return;
	}

	//カウンタを進める
	blastImgAnimCount++;
	if (blastImgAnimCount < BLAST_ALL_NUM)
	{
		DrawBillboard3D(
			pos_, 0.5f, 0.5f, 300.0f, 0.0f,
			blastImgs[blastImgAnimCount], true);
	}
	if (blastImgAnimCount >= BLAST_ALL_NUM && player_.IsAlive())
	{
		isBlast_ = false;
		blastImgAnimCount = 0;
	}

}

//解放処理
void Blast::Release(void)
{
	//爆発アニメーション画像をすべて解放
	for (int i = 0; i < BLAST_ALL_NUM; i++)
	{
		DeleteGraph(blastImgs[i]);
	}
}

VECTOR Blast::GetPos(void)
{
	return pos_;
}

void Blast::SetPos(VECTOR pos)
{
	pos_=pos;
}

bool Blast::IsBlast(void)
{
	return isBlast_;
}

void Blast::SetBlast(bool isBlast)
{
	isBlast_ = isBlast;
}


