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
    
    bool checkFood = checkFoodConsumption(head);
    
    if(checkFood)
    {
        increasePlayerLength(playerPosList, head);
        foodObj->generateFood(playerPosList,sizeX, sizeY);
    }else{
        playerPosList->insertHead(head);
        playerPosList->removeTail(); 
    }

    bool checkEnd = checkSelfCollision(playerPosList, head);

    if(checkEnd){
        mainGameMechsRef->setLoseFlag();
        
    }
}

// More methods to be added
bool Player::checkFoodConsumption(objPos curr){
    int size = foodObj->getFoodBucket()->getSize();

    for (int i = 0; i < size; i++)
    {       
        objPos food = foodObj->getFoodBucket()->getElement(i);
        if (curr.isPosEqual(&food)) 
        {
            char foodSymbol = food.getSymbol();
            switch (foodSymbol)
            {
            case '?':
                mainGameMechsRef->incrementScore(1);
                break;
            
            case '!':
                mainGameMechsRef->incrementScore(2);
                break;
            case '$':
                mainGameMechsRef->incrementScore(5);
                break;
            default:
                break;

            }
            return true;
        }
    }
    return false;
}

void Player::increasePlayerLength(objPosArrayList* x, objPos curr){
    x->insertHead(curr);
}

bool Player::checkSelfCollision(objPosArrayList* list, objPos curr){
    int size = list->getSize();

    for(int i = 1; i < size; i++){
        if (list->getElement(i).isPosEqual(&curr)) return true;
        else continue;
    }
    return false;
}