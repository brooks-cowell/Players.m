/*
Brooks D Cowell
Computer Science Fall 2024
Due: December 9th 2024
Monopoly, Monopoly Players
Monopoly players 
*/


#include "players.h"
#include <algorithm> // for std::remove and std::find

// Constructor
Player::Player(const std::string& name, int startingMoney)
    : m_name(name),
    m_money(startingMoney),
    m_position(0),
    m_bankrupt(false)
{
}

const std::string& Player::getName() const {
    return m_name;
}

int Player::getMoney() const {
    return m_money;
}

int Player::getPosition() const {
    return m_position;
}

bool Player::isBankrupt() const {
    return m_bankrupt;
}

void Player::move(int steps) {
    // Increase the position by the given number of steps.
    // If the board is circular, you might mod by board size here.
    m_position += steps;

    // Example if you know board size (e.g., Monopoly's 40):
    // const int BOARD_SIZE = 40;
    // m_position = (m_position % BOARD_SIZE + BOARD_SIZE) % BOARD_SIZE;
}

void Player::adjustMoney(int amount) {
    // Add or subtract from the player's money.
    m_money += amount;

    // If m_money < 0, player might be close to bankruptcy,
    // but official declaration should be done via declareBankrupt().
}

void Player::setPosition(int position) {
    // Set the player's position directly.
    m_position = position;
}

void Player::declareBankrupt() {
    // Mark as bankrupt, set money to 0, and clear properties.
    m_bankrupt = true;
    m_money = 0;
    m_properties.clear();
}

void Player::addProperty(std::shared_ptr<Property> property) {
    // Add a property if it's not null and not already owned.
    if (property && !ownsProperty(property)) {
        m_properties.push_back(property);
    }
}

void Player::removeProperty(std::shared_ptr<Property> property) {
    // Remove the property if it exists in the player's owned list.
    m_properties.erase(
        std::remove(m_properties.begin(), m_properties.end(), property),
        m_properties.end()
    );
}

const std::vector<std::shared_ptr<Property>>& Player::getOwnedProperties() const {
    return m_properties;
}

int Player::getNumberOfOwnedProperties() const {
    return static_cast<int>(m_properties.size());
}

bool Player::canAfford(int amount) const {
    return (m_money >= amount);
}

bool Player::ownsProperty(std::shared_ptr<Property> property) const {
    return std::find(m_properties.begin(), m_properties.end(), property) != m_properties.end();
}
