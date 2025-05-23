//#pragma once
//#include "Object.h"
//#include "vector"
//#include "memory"
//class MobileObject : public Object
//{
//public:
//	MobileObject(sf::Vector2f, sf::Sprite);
//	virtual void move(std::vector<std::vector<std::unique_ptr<Object>>>&, float) = 0;
//protected:
//	sf::Vector2f m_direction ={1.f, -1.f};
//	sf::Sprite m_sprite;
//};
//class Player : public MobileObject
//{
//  public:
//	  Player(sf::Vector2f, sf::Sprite);
//	  virtual void move(std::vector<std::vector<std::unique_ptr<Object>>>&, float) override ;
//	  virtual void draw(sf::RenderWindow&);
//	  virtual bool SavePlace() override { return true; }
//	  bool needToDoRecursion() const { return m_needToDoRecursion; }
//	  virtual bool conquerable() override { return false; }
//	  sf::Vector2f getLocation() const { return m_location; }
//
//private:
//	sf::Vector2f m_lastLocation = { 0, 0};
//	int m_life = 3;
//	bool m_needToDoRecursion = false;
//};
//
//class Enemy: public MobileObject
//{
//public:
//	virtual bool SavePlace() override { return true; }
//
//	Enemy(sf::Vector2f, sf::Sprite);
//	virtual void move(std::vector<std::vector<std::unique_ptr<Object>>>&, float) override ;
//	virtual void draw(sf::RenderWindow&);
//	void conquer(std::vector<std::vector<std::unique_ptr<Object>>>&,int ,int);
//	virtual bool conquerable() override { return false; }
//	sf::Vector2f getLocation() const { return m_location; }
//
//
//private:
//	sf::Vector2f m_lastLocation = { 0, 0 };
//};

#pragma once
#include "MobileObject.h"
#include "SfmlManager.h"
class Enemy;
class Player : public MobileObject
{
public:
	Player(sf::Vector2f location, SfmlManager& SfmlMan);
	virtual ~Player() = default;
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(std::vector<std::vector<std::unique_ptr<Tile>>>&, float) override ;
	virtual void move(float) override;

	   // --- Double Dispatch ---
	virtual void handleCollision(MobileObject&) override {};
	virtual void handleCollision(Enemy&) override {};
	virtual void handleCollision(Player&) override {};

private:
	SfmlManager& m_sfmlManager;
	sf::Vector2f ArrangeLocation(sf::Vector2f);
	void chooseDirection();
	int m_speed = 50;
	bool m_inTrailMode = false;
	bool m_needToDoRecursion = false;
	int m_life = 5;
};