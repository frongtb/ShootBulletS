#include "Game.h"


//pri func



void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1080, 720), "ShootBulletS", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
	
		
}

void Game::intitTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
	
}

void Game::initGUI()
{
	//load font
	if (!this->font.loadFromFile("Fonts/Cascadia.ttf"))
		std::cout << "game failed to load font" << "\n";

	//init point text
	this->pointText.setPosition(900.f, 25.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(24);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("test");

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("GAME OVER!!!");
	this->gameOverText.setPosition(this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f, this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	this->CongratulationText.setFont(this->font);
	this->CongratulationText.setCharacterSize(60);
	this->CongratulationText.setFillColor(sf::Color::Yellow);
	this->CongratulationText.setString("!!!Congratulation!!!");
	this->CongratulationText.setPosition(this->window->getSize().x / 2.f - this->CongratulationText.getGlobalBounds().width / 2.f, this->window->getSize().y / 2.f - this->CongratulationText.getGlobalBounds().height / 2.f);
	//init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(5.f, 30.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

}

void Game::initWorld()
{
	if (!this->worldBGText.loadFromFile("Textures/BG2.jpg"))
	{
		std::cout << "error load BG" << "/n";
	}

	this->worldBG.setTexture(this->worldBGText);
	this->worldBG.setScale(sf::Vector2f(2.5f, 2.8f));
}

void Game::initBGmenu()
{
	if (!this->menuTexture.loadFromFile("Textures/BG1.jpg"))
	{
		std::cout << "error menu bg" << "\n";
	}

	this->menuSprite.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)
	)
	);
}

void Game::initSystems()
{
	this->points = 0;
	this->health = 10;
}



void Game::initPlayer()
{
	this->player = new Player();

}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}


//con/des
Game::Game()
{
	
	this->initWindow();
	this->initBGmenu();
	this->intitTextures();
	this->initGUI();
	this->initWorld();
	this->initSystems();
	
	this->initPlayer();
	this->initEnemies();
	
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//delete texture
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	//delete bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}

	//delete enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}
}


//functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvents();

		if(this->player->getHp() > 0 && this->points < 1000)
			this->update();

		this->render();

	}

}

void Game::again()
{
	for (auto& enemy : this->enemies)
	{
		delete enemy;
	}
	this->enemies.clear();

	this->player->setHp(100);
	this->points = 0;
	this->player->setPosition(sf::Vector2f(538.f, 417.f));
	for (auto& bullet : this->bullets)
	{
		delete bullet;
	}
	this->bullets.clear();
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::R)
		{
			this->GameStart = true;
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::T)
		{
			this->GameStart = false;
			this->again();
		}
	}
}

void Game::updateInput()
{
	//move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->player->move(-0.1f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->player->move(0.0f, -0.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->player->move(0.1f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->player->move(0.0f, 0.1f);
	}
	//std::cout << "Mouse position : " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";
	if (::sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAtk())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x +this->player->getBounds().width/2.f,
			this->player->getPos().y,
			0.f,-1.f ,5.f));
	}

}

void Game::updateGUI()
{
	std::stringstream ss;

	ss<<"Points : " << this->points;

	this->pointText.setString(ss.str());

	//update player GUI
	
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax() *100;
	this->playerHpBar.setSize(sf::Vector2f(3.f * hpPercent, this->playerHpBar.getSize().y));

}

void Game::updateWorld()
{

}

void Game::updateCollision()
{
	//left
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	//right
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x- this->player->getBounds().width,this->player->getBounds().top );
	}
	//top
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}
	//bottom
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y- this->player->getBounds().height);
	}


}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		
		bullet->update();
		
		//bullet culling(top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);

			//std::cout << this->bullets.size() << "\n";
		}
		++counter;
	}
	
}

void Game::updateEnemies()
{
	//spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f, -100.f));
		this->spawnTimer = 0.f;
	}

	//update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{

		enemy->update();

		//bullet culling(top of screen)
		if (enemy->getBounds().top > this->window->getSize().y)
		{
			//delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		//enemy player collision
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		++counter;
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints();

				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}

		}
	}
}

void Game::update()
{
	this->updateInput();

	this->updateGUI();

	this->player->update();

	this->updateCollision();

	this->updateBullets();

	this->updateEnemies();

	this->updateCombat();

	this->updateWorld();
}

void Game::renderBGMenu()
{
	this->window->draw(this->menuSprite);
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	
}

void Game::renderWorld()
{
	this->window->draw(this->worldBG);
}

void Game::render()
{
	this->window->clear();

	if (!this->GameStart)
	{
		this->renderBGMenu();
	}
	else
	{
		//Draw world
		this->renderWorld();
		//draw all stuff
		this->player->render(*this->window);

		for (auto& bullet : this->bullets)
		{
			bullet->render(this->window);
		}

		for (auto* enemy : this->enemies)
		{
			enemy->render(this->window);
		}

		this->renderGUI();
	}

	//Game Over screen
	if (this->player->getHp() <= 0)
		this->window->draw(gameOverText);

	//congratulation screen
	if (this->points >= 1000)
		this->window->draw(CongratulationText);


	this->window->display();
}
