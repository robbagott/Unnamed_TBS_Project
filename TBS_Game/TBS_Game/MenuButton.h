#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuButton
{
public:
	MenuButton(std::string selectedFilename, std::string unselectedFilename, int left, int top, int height, int width);
	MenuButton(const MenuButton&);
	void operator=(const MenuButton&);
	const sf::Vector2f& position() const;
	sf::FloatRect bounds() const;
	void select();
	void silentSelect();
	void deselect();
	bool isSelected() const;

	void draw(sf::RenderWindow& window);

private:
	//undefined
	MenuButton();

	sf::Texture m_selectedTexture;
	sf::Texture m_unselectedTexture;
	sf::Sprite m_sprite;
	sf::Sound m_sound;
	sf::SoundBuffer m_selectSound;
	bool m_isSelected;
};

#endif