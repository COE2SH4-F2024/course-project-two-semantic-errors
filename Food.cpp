#include "Food.h"

Food::Food()
{

    foodPos.setObjPos(-1, -1, '$');

}

Food::~Food()
{

}

void Food::generateFood(objPosArrayList* blockOff, int boardSizeX, int boardSizeY)
{
    srand(time(NULL));

    bool isNotOnArray;
    int randomx, randomy;
    int size = blockOff->getSize();
    do{
        randomx = (rand() % (boardSizeX - 2)) + 1;
        randomy = (rand() % (boardSizeY - 2)) + 1;
        isNotOnArray = true;
        for(int i = 0 ; i < size; i++){
            int x = blockOff->getElement(i).pos->x;
            int y = blockOff->getElement(i).pos->y;
            if(x == randomx && y == randomy){
                isNotOnArray = false;
                break;
            }

        }
    }while(!isNotOnArray);
    foodPos.setObjPos(randomx, randomy, '$');
}


objPos Food::getFoodPos() const
{
    return foodPos;
}


