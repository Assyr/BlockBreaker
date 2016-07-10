#include "stdafx.h"
#include "MyGame.h"



int main(int argc, char* argv[])
{
	CMyGame game;
	CGameApp app;
	app.OpenWindow(800, 600, "The AA Game!");
	//app.OpenFullScreen(800, 600, 24);
	app.SetClearColor(CColor::Black());
	app.Run(&game);
	return(0);
}
