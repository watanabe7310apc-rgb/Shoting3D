#pragma once
#include<DxLib.h>

class Stage
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

	//ステージの配置座標(Z)
	static constexpr float STAGE_LOOP_TERM_Z = 8000.0f;

	//ステージの位置
	VECTOR stage1Pos = { 0.0f, -50.0f, 0.0f };
	VECTOR stage2Pos = { 0.0f, -50.0f, 8000.0f };

	//ステージのサイズ
	VECTOR stageSize = { 10.0f, 10.0f, 10.0f };
private:


	// ステージモデルのロード
	int stage1ModelId = -1;
	int stage2ModelId = -1;

	//1つ目のステージの位置を変更する場合、true
	bool isLoopStage1;

	//次のステージの位置
	float StageLoopPos;

};

extern Stage stage_;
