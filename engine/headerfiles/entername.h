#pragma once
class entername
{
	public:
		GameState State;
		bool Keys[1024];
		unsigned int Width, Height;
		entername(unsigned int width, unsigned int height);
		void Init();
		void ProcessInput();
		void Loop();
		void Render();
};

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

