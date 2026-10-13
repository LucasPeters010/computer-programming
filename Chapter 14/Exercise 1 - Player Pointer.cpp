// Exercise 1 - Player Pointer (EASY)
// Goal: Practice new, class pointers, ->, and delete.
//
// Tasks:
// 1. Complete addPoints() so it increases the player's score.
// 2. Complete print() so it prints the player's name and score.
// 3. In main(), use the POINTER to call addPoints(5) and print().
// 4. Free the dynamically allocated object.
//
// Expected output:
// Alex has 15 points
//
// Hint: player->someMethod() calls a method through a pointer.

#include <iostream>
#include <string>

class Player {
public:
    Player(std::string playerName, int startingScore)
        : name(playerName), score(startingScore) {}

    void addPoints(int points) {
        score += points;
    }

    void print() const {
        // TODO 2: Print: Alex has 15 points
        std::cout << "Alex has " << score << " points" << std::endl;
    }

private:
    std::string name;
    int score;
};

int main() {
    Player* player = new Player("Alex", 10);

    player->addPoints(5);
    player->print();

    delete player;

    // TODO 3: Call addPoints(5) and print() through player.

    // TODO 4: Release the memory allocated by new.

    return 0;
}
