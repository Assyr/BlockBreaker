#include "stdafx.h"
#include "MyGame.h"

int main(int argc, char* argv[])
{
	
	CMyGame game;   // Your game implementation
	CGameApp app;   // The game application

	srand( (unsigned)time( NULL ) );

	app.OpenWindow(800, 600, "Catch IT"); // show window + title
	app.SetClearColor(CColor::Black());   // set background colour
	app.Run( &game);  // game engine is running your game
	return(0);
}
