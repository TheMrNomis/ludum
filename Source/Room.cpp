#include "Room.h"




Room::Room() : m_objects(std::vector<Object>()),
			   m_fireDetectors(std::vector<FireDetector>())
{
}



void Room::extinguishFire()
{
    for(auto it = m_objects.begin(); it != m_objects.end(); ++it)
        it->stopFire();
}



void Room::draw(sf::RenderWindow * window) const{

	for (auto it = m_objects.cbegin(); it != m_objects.cend(); ++it){
		it->draw(window);
	}
	for (auto it = m_fireDetectors.cbegin(); it != m_fireDetectors.cend(); ++it){
		it->draw(window);
	}
}


void Room::update(sf::Clock const & clk){

	//si le fireDetector détecte le character -> extinguishFire()





}