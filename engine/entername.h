#pragma once
class entername
{
	public:
		GameState State;
		bool Keys[1024];
		unsigned int Width, height;
		~entername();
		void Init();
		void ProcessInput();
		void Update();
		void Render();
};

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

