#include "DxLib.h"
#include "Application.h"
#include "Title.h"

Title title_;

//‰Šú‰»ˆ—
void Title::Init(void)
{
	prevSpaceKey = nowSpaceKey = 0;
	titleId_ = LoadGraph("Data/Image/Title.png", false);
}

//XVˆ—
void Title::Update(void)
{
	prevSpaceKey = nowSpaceKey;
	nowSpaceKey = CheckHitKey(KEY_INPUT_SPACE);
	if (prevSpaceKey == 0 && nowSpaceKey == 1)
	{
		app_.ChangeScene(Application::GAME);
	}


}

//•`‰æˆ—
void Title::Draw(void)
{
	DrawGraph(0, 0, titleId_, true);
}

//‰ğ•úˆ—
void Title::Release(void)
{
	DeleteGraph(titleId_);
}
