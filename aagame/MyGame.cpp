#include "stdafx.h"
#include "MyGame.h"


CMyGame::CMyGame(void) : theGun(400, 590, "aagun.bmp", CColor::Black(), GetTime())
{ 
		
}


CMyGame::~CMyGame(void)
{
	for (unsigned int i=0; i < theBullets.size(); i++) delete theBullets[i];
}

/////////////////////////////////////////////////////
// Per-Frame Callback Funtions (must be implemented!)

void CMyGame::OnUpdate()
{
	// update gun with current time
	theGun.Update(GetTime());

	// go through bullets in list
	for (unsigned int n=0; n < theBullets.size(); n++)
	{
	  // obtain pointer to bullet instance n
      CSprite* pSprite=theBullets[n];

	  // call update of bullet instance
	  pSprite->Update( GetTime());

	 
     // removing bullet if it is near the top of the screen
	 if(pSprite->GetY() < 10)
	 {
		theBullets.erase(theBullets.begin()+n);
		delete pSprite; n--; continue;
	 }
	 
	}

	// --------- Keyboard controls --------

	// checking the keyboard status 
	if (IsKeyDown( SDLK_LEFT)) theGun.SetX( theGun.GetX()-5);

	// checking the keyboard status 
	if (IsKeyDown( SDLK_RIGHT)) theGun.SetX( theGun.GetX()+5);
	
	
}



void CMyGame::OnDraw(CGraphics* g)
{
	unsigned int n;

	// draw gun on graphics surface g
	theGun.Draw(g);

	// go through all bullets in list
	for (n=0; n < theBullets.size(); n++)
	{
	  // obtain pointer to bullet instance n
      CSprite* pSprite=theBullets[n];
	  // draw bullet instance
	  pSprite->Draw(g);	
	}

	if ( IsGameOverMode())
		{
		 *g << font(46) << color(CColor::Red()) << vcenter << center << " GAME OVER ";	
		}
	    // print number of bullets
		*g << font(28) << color(CColor::Red()) << score;

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
	score = 0;

	StartGame();	// this allows to start the game immediately
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
	if(sym == SDLK_LCTRL) // left control button pressed
	{
		CSprite* pSprite = new CSprite(theGun.GetX(),theGun.GetTop(), "bullet.bmp",CColor::Black(),GetTime());
		pSprite->SetMotion(0,200);			// set motion
		theBullets.push_back( pSprite );    // add to vector list
	}
	
    if (sym == SDLK_F4 && (mod & (KMOD_LALT | KMOD_RALT)))
		StopGame();
	if (sym == SDLK_SPACE)
		PauseGame();
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
