#pragma once
#include "CommonTools.h"


//=========================================
// GameEngine class 
//=========================================

#define GAMESYS NSGameEngine::GetInstance()

class NSGameEngine : public Singleton<NSGameEngine>
{
	 friend class Singleton<NSGameEngine>;

public:
 
	void Initialize();
	void Execute();
 
private:
	NSGameEngine() = default;

public:
	// create instance
	static NSGameEngine* CreateInstance()
	{
		return new NSGameEngine();
	}

};
 
