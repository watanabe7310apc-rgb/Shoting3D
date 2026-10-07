#pragma once

class UI
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

	//ゲームオーバー画面のロード
	int gameoverModelId = -1;

	//ゲームクリア画面のロード
	int gameclearModelId = -1;

};

extern UI ui_;
