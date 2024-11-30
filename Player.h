#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.
    
    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFood);
        ~Player();

        objPos getPlayerPos() const; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        void movePlayer();
        objPosArrayList* getPlayerPosList() const;
        bool checkFoodConsumption(objPos curr, objPos food);
        void increasePlayerLength(objPosArrayList* x, objPos curr);
        bool checkSelfCollision(objPosArrayList* list, objPos curr);
        // More methods to be added here

    private:
        objPosArrayList* playerPosList; // Upgrade this in iteration 3.       
        enum Dir myDir;
        Food* foodObj;
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif