#include "CharacterSelectMenu.h"

CharacterSelectMenu::CharacterSelectMenu() :
	m_cursor("hand_cursor"),
	m_selected(0) {

	//hand cursor parameters
	m_cursor.setPosition(360 - m_cursor.sprite().getLocalBounds().width, 64);
	m_cursor.setAnimation("default", true);

	//allocate menu options
	m_options.push_back(SpriteSheet("attack_option"));
	m_options.push_back(SpriteSheet("wait_option"));

	//Set option spritesheet parameters
	for (unsigned int i = 0; i < m_options.size(); ++i) {
		m_options[i].setPosition(360, i*m_options[i].sprite().getLocalBounds().height + 64);
		m_options[i].setAnimation("default", true);
	}
}

CharacterSelectMenu::~CharacterSelectMenu() {

}
void CharacterSelectMenu::handleEvent(sf::Event event) {
	if (event.type == sf::Event::EventType::KeyPressed) {
		if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
			select(m_selected + 1);
		}
		else if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
			select(m_selected - 1);
		}
		else if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space) {
		}
	}
}

void CharacterSelectMenu::update() {
	m_cursor.update();

	for (unsigned int i = 0; i < m_options.size(); ++i) {
		m_options[i].update();
	}
}

void CharacterSelectMenu::draw(sf::RenderWindow& window) {
	for (unsigned int i = 0; i < m_options.size(); ++i) {
		window.draw(m_options[i].sprite());
	}

	window.draw(m_cursor.sprite());
}

void CharacterSelectMenu::select(int choice) {
	if (choice >= 0 && choice < m_options.size()) {
		m_selected = choice;
		m_cursor.setPosition(m_cursor.getPosition().x, choice*16 + 64);
	}
}