#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(10,5,'*');
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    

}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;

}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic
        switch(mainGameMechsRef->getInput())
        {                      
            case 27:  
                mainGameMechsRef->setExitTrue();
                break;

            case 'w':
                if (myDir != DOWN) {  
                    myDir = UP;
                }
                break;

            case 's':
                if (myDir != UP) {  
                    myDir = DOWN;
                }
                break;

            case 'd':
                if (myDir != LEFT) {  
                    myDir = RIGHT;
                }
                break;

            case 'a':
                if (myDir != RIGHT) {  
                    myDir = LEFT;
                }
                break; 
            default:
                break;
        }          
        mainGameMechsRef->clearInput();
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine 
    switch(myDir)
    {
        case UP:
            playerPos.pos->y--;
            break;
        case DOWN:
            playerPos.pos->y++;
            break;
            
        case RIGHT:
            playerPos.pos->x++;
            break;

        case LEFT:
            playerPos.pos->x--;
            break;

        default:
            break;
    }
    int sizeX = mainGameMechsRef->getBoardSizeX();
    int sizeY = mainGameMechsRef->getBoardSizeY();
    if (playerPos.pos->x < 1) {
    playerPos.pos->x = sizeX - 2;
    } else if (playerPos.pos->x >= sizeX - 1) {
        playerPos.pos->x = 1;
    }

    if (playerPos.pos->y < 1) {
        playerPos.pos->y = sizeY - 2;
    } else if (playerPos.pos->y >= sizeY - 1) {
        playerPos.pos->y = 1;
    }
}

// More methods to be added