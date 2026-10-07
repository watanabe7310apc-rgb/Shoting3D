#pragma once

class Blast
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

	//爆発画像のロード
	int blastImgs[24];

	//爆発画像の最大数
	int BLAST_ALL_NUM = 24;

	//爆発画像の横の最大数
	int BLAST_X_NUM = 6;

	//爆発画像の縦の最大数
	int BLAST_Y_NUM = 4;

	//爆発画像の横サイズ
	int BLAST_X_SIZE = 96;

	//爆発画像の縦サイズ
	int BLAST_Y_SIZE = 96;

	//座標の取得
	VECTOR GetPos(void);

	//座標の設定
	void SetPos(VECTOR pos);

	//生存判定の取得
	bool IsBlast(void);

	//生存判定の設定
	void SetBlast(bool isBlast);

private:

	//爆発座標
	VECTOR pos_;

	//爆発アニメーション用のカウンタ
	int blastImgAnimCount;


	//爆発画像の判定
	bool isBlast_;

	//爆発判定
	bool nowBlast;

};

extern Blast blast_;
