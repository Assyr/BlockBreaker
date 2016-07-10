#include "stdafx.h"
#include "MyGame.h"
#include <sstream>
#include <ctime>

CMyGame::CMyGame(void) : ball(400, 0, "ball.bmp", CColor::Black(), GetTime()), 
	                     paddle(400,580, "paddle.png", CColor::Black(), GetTime())

						 
{}

CMyGame::~CMyGame(void)
{
for (unsigned int i = 0; i < blocks.size(); i++) delete blocks[i];

}

/////////////////////////////////////////////////////
// Per-Frame Callback Funtions (must be implemented!)

void CMyGame::OnUpdate()
{
	for (unsigned int n=0; n < blocks.size(); n++)
	{
	  // obtain pointer to bullet instance n
      CSprite* pSprite=blocks[n];

	  // call update of block instance
	  pSprite->Update( GetTime());

	 
     // removing bullet if it is near the top of the screen
	 if (ball.HitTest( pSprite))
	 {
		blocks.erase(blocks.begin()+n);
		delete pSprite; n--; continue;
		score++;
	 }
	}

	if (IsGameOverMode())
		return;

	// updating ball
	ball.Update( GetTime() + 30);

	// updating paddle
	paddle.Update( GetTime());


	// test if ball has hit the paddle
	if (ball.HitTestPixel( &paddle))
	{
		ball.SetDirection(ball.GetXDirection(), -ball.GetYDirection());
	}

	// ball hit the bottom, we did not catch the ball, thus game over
	if (ball.GetY() > 600)
	{
       GameOver();
	}
	if(ball.GetY() < 20)
	{
		
		ball.SetDirection(ball.GetXDirection(), -ball.GetYDirection());
	}

	if(ball.GetX() > 770)
	{ 
		ball.SetDirection(-ball.GetXDirection(), ball.GetYDirection());
	}

	if(ball.GetX() < 30)
	{
	ball.SetDirection(-ball.GetXDirection(), ball.GetYDirection());
	
	}

	if(paddle.GetX() > 720)
	{
		paddle.SetX(720);
	}

	if(paddle.GetX() < 80)
		
	{
		paddle.SetX(80);
	}


	
}

void CMyGame::OnDraw(CGraphics* g)
{

	for (int n=20; n < blocks.size(); n++)
	{
	  // obtain pointer to bullet instance n
      CSprite* pSprite=blocks[n];
	  // draw bullet instance
	  pSprite->Draw(g);	
	}

		// draw ball
		ball.Draw( g);

        // draw paddle
	    paddle.Draw( g);

		// print score
		*g << font(28) << color(CColor::Red()) << score;

		//print level

		*g << font(28) << color(CColor::Red()) << right << "Level: " << level;

		// print game over
		if ( IsGameOverMode())
			*g << font(46) << color(CColor::Red()) << vcenter << center << " GAME OVER ";
	
}

/////////////////////////////////////////////////////
// Game Life Cycle

// one time initialisation
void CMyGame::OnInitialize()
{
}

// called at the start of a new game - display menu here
void CMyGame::OnDisplayMenu()
{	
	for (int x = 0; x < 15; x++)
{
	for (int y = 0; y < 4; y++)
	{
		CSprite *pSprite = new CSpriteBitmap((x * (53 + 2)) + (53 / 2) + -120, (y * (30 + 2)) + (30 / 2) +10, "blocks.jpg", CColor::Black(), GetTime());
		blocks.push_back(pSprite);
	}
}
	
	// set ball initial position (important to do it here - this function will be executed after F2 is pressed)
	ball.SetPosition(420,550);
	ball.SetVelocity( 0, 800);
	ball.SetDirection(30,30);
	// set score to 0
	score = 0;
	//set level to 1
	level = 1;

	//Start the game...
	StartGame();
}

// called when Game Mode entered
void CMyGame::OnStartGame()
{

}

// called when Game is Over
void CMyGame::OnGameOver()
{
}

// one time termination code
void CMyGame::OnTerminate()
{
}

/////////////////////////////////////////////////////
// Keyboard Event Handlers

void CMyGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_F4 && mod == KMOD_LALT)
		StopGame();
	if (sym == SDLK_F2)
		NewGame();
}

void CMyGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	
}


/////////////////////////////////////////////////////
// Mouse Events Handlers

void CMyGame::OnMouseMove(Uint16 x,Uint16 y,Sint16 relx,Sint16 rely,bool bLeft,bool bRight,bool bMiddle)
{
	// synchronise horizontal paddle position with the mouse position 
	paddle.SetX( x);
}

void CMyGame::OnLButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnLButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonUp(Uint16 x,Uint16 y)
{
}
