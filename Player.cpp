#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    objPos initialPosition(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*');
    playerPosList->insertHead(initialPosition);
    foodObj = thisFood;
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;

}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList->getHeadElement();

}
objPosArrayList* Player::getPlayerPosList() const
{
    // Return a reference to the position list
    return playerPosList;
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
    // get current head pos
    objPos head = playerPosList->getHeadElement();
    objPos foodPos = foodObj->getFoodPos();

    switch(myDir)
    {
        case UP:
            head.pos->y--;
            break;
        case DOWN:
            head.pos->y++;
            break;
            
        case RIGHT:
            head.pos->x++;
            break;

        case LEFT:
            head.pos->x--;
            break;

        default:
            break;
    }
    int sizeX = mainGameMechsRef->getBoardSizeX();
    int sizeY = mainGameMechsRef->getBoardSizeY();
    if (head.pos->x < 1) {
    head.pos->x = sizeX - 2;
    } else if (head.pos->x >= sizeX - 1) {
        head.pos->x = 1;
    }

    if (head.pos->y < 1) {
        head.pos->y = sizeY - 2;
    } else if (head.pos->y >= sizeY - 1) {
        head.pos->y = 1;
    }
    if(head.isPosEqual(&foodPos)){
        playerPosList->insertHead(head);
        foodObj->generateFood(playerPosList,sizeX, sizeY);
        mainGameMechsRef->incrementScore();
    }else{
        playerPosList->insertHead(head);
        playerPosList->removeTail(); 
    }
}

// More methods to be added