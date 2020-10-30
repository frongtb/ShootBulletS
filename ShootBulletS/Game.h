#pragma once

#include<map>
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"

#include<sstream>
#include<string>
class Game
{
private:
	//window
	sf::RenderWindow* window;

	//resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//GUI
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;
	sf::Text CongratulationText;

	//world
	sf::Texture worldBGText;
	sf::Sprite worldBG;

	//systems
	unsigned points;
	unsigned health;

	//player
	Player* player;

	//player GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;


	//enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	//pri func
	void initWindow();
	void intitTextures();
	void initGUI();
	void initWorld();
	void initSystems();

	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();
	
	//functions
	void run();

	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void update();
	void renderGUI();
	void renderWorld();
	void render();
};

