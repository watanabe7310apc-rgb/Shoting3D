#pragma once
class Title
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
private:

	int prevSpaceKey, nowSpaceKey;   //スペースキーの状態を保存する変数

	int titleId_=-1;

};
extern Title title_;

