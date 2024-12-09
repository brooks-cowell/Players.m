#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>


class Player {
public:
  
    Player(const std::string& name, int startingMoney = 1500);
    const std::string& getName() const;
    int getMoney() const;
    int getPosition() const;
    bool isBankrupt() const;
    void move(int steps);
    void adjustMoney(int amount);
    void setPosition(int position);
    void declareBankrupt();
    void addProperty(std::shared_ptr<Property> property);
    void removeProperty(std::shared_ptr<Property> property);
    const std::vector<std::shared_ptr<Property>>& getOwnedProperties() const;
    int getNumberOfOwnedProperties() const;
    bool canAfford(int amount) const;
    bool ownsProperty(std::shared_ptr<Property> property) const;

private:
    std::string m_name;                                ///< Player’s name.
    int m_money;                                       ///< Current amount of money.
    int m_position;                                    ///< Current board position.
    bool m_bankrupt;                                   ///< Flag indicating if the player is bankrupt.
    std::vector<std::shared_ptr<Property>> m_properties; ///< Vector of owned properties.
};

#endif // PLAYER_H
