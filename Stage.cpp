#include <DxLib.h>
#include "Stage.h"
#include "Camera.h"

Stage stage_;

//初期化処理
void Stage::Init(void)
{
	// ステージモデルのロード
	stage1ModelId = MV1LoadModel("Data/Model/Stage.mv1");
	stage2ModelId = MV1LoadModel("Data/Model/Stage.mv1");

	//1つ目のステージの位置を変更する場合、true
	isLoopStage1 = true;

	//次のステージの位置
	StageLoopPos = STAGE_LOOP_TERM_Z;

	//ステージのサイズを設定する
	MV1SetScale(stage1ModelId, stageSize);
	MV1SetScale(stage2ModelId, stageSize);

	//ステージの座標をセットする
	MV1SetPosition(stage1ModelId, stage1Pos);
	MV1SetPosition(stage2ModelId, stage2Pos);

}

//更新処理
void Stage::Update(void)
{

	//ステージループ
	if (camera_.GetPos().z > StageLoopPos)
	{
		//座標を奥のほうに移動させる
		StageLoopPos += STAGE_LOOP_TERM_Z;
		if (isLoopStage1)
		{
			stage1Pos.z = StageLoopPos;
			//1つ目のステージの位置を変更
			MV1SetPosition(stage1ModelId, stage1Pos);
			isLoopStage1 = false;
		}
		else
		{
			stage2Pos.z = StageLoopPos;
			//2つ目のステージの位置を変更
			MV1SetPosition(stage2ModelId, stage2Pos);
			isLoopStage1 = true;

		}
	}

}

//描画処理
void Stage::Draw(void)
{
	//ステージの描画
	MV1DrawModel(stage1ModelId);
	MV1DrawModel(stage2ModelId);

}

//解放処理
void Stage::Release(void)
{
	// ステージモデルの解放
	MV1DeleteModel(stage1ModelId);
	MV1DeleteModel(stage2ModelId);
}
