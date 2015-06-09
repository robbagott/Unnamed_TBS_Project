#ifndef MAINMENU_H
#define MAINMENU_H

#include <vector>
#include "IGameState.h"
#include "MenuButton.h"

class MainMenu : public IGameState
{
public:
	MainMenu(Game& game);
	~MainMenu();
	void init();
	void cleanup();

	void pause();
	void resume();

	void handleEvents();
	void update();
	void draw();

private:
	//program shouldn't be calling undefined code from under my nose!
	MainMenu();
	MainMenu(const MainMenu& other);
	void operator=(const MainMenu&);

	void onNewGamePushed();

	Game& m_game;
	sf::Sprite m_background;
	sf::Texture m_texture;
	sf::Texture m_blackTexture;
	sf::Sprite m_blackSprite;
	sf::SoundBuffer m_newGameSoundBuffer;
	sf::Sound m_newGameSound;
	sf::Music m_music;
	sf::Clock m_fadeInClock;
	sf::Clock m_fadeOutClock;

	int m_selectedButton;
	std::vector<MenuButton> m_buttons;

	int m_fadeInTimeInSeconds;
	bool m_newGamePushed;
	int m_fadeOutTimeInSeconds;
	bool m_transitionNewGame;
	bool m_responsive;
};

#endif