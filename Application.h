#pragma once
#include <DxLib.h>

class Application
{
public:

	enum SCENE
	{
		TITLE,
		GAME,
		GAMEOVER
	};

	//‰Šú‰»ˆ—
	void Init(void);
	//XVˆ—
	void Update(void);
	//•`‰æˆ—
	void Draw(void);
	//‰ğ•úˆ—
	void Release(void);

	void ChangeScene(SCENE scene);

	static constexpr int SCREEN_SIZE_X = 1280;
	static constexpr int SCREEN_SIZE_Y = 720;

private:
	SCENE scene_;
};

extern Application app_;
