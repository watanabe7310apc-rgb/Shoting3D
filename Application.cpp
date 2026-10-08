#include <DxLib.h>
#include "Application.h"
#include "GameScene.h"
#include "Title.h"

Application app_;

void Application::Init(void)
{
	//乱数のシード値を設定する
	DATEDATA date;

	//現在時刻を取得する
	GetDateTime(&date);

	//乱数の初期値を設定する
	//設定する数値によって、ランダムの出方が変わる
	SRand(date.Year + date.Mon + date.Day + date.Hour + date.Min + date.Sec);

	scene_ = SCENE::TITLE;

}

void Application::Update(void)
{
	switch (scene_) {
	case SCENE::TITLE:
	{
		title_.Update();
	}
	break;

	case SCENE::GAME:
	{
		game_.Update();
	}
	break;
	}

}

void Application::Draw(void)
{
	switch (scene_) {
	case SCENE::TITLE:
	{
		title_.Draw();
	}
	break;

	case SCENE::GAME:
	{
		game_.Draw();
	}
	break;
	}

}
void Application::Release(void)
{
	switch (scene_) {
	case SCENE::TITLE:
	{
		title_.Release();
	}
	break;

	case SCENE::GAME:
	{
		game_.Release();
	}
break;
	}

}

void Application::ChangeScene(SCENE scene)
{
	scene_ = scene;
	switch (scene_) {

	case SCENE::TITLE:
	{
		title_.Init();
	}
	break;
	case SCENE::GAME:
	{
		game_.Init();

	}
	break;
	}


}
