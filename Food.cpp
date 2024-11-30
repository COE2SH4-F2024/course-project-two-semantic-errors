#include "Food.h"

Food::Food()
{

    foodPos.setObjPos(-1, -1, '$');

}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff, int boardSizeX, int boardSizeY)
{
    srand(time(NULL));

    int check = 0;
    int randomx, randomy;

    while(!check)
    {
        randomx = (rand() % (boardSizeX - 2)) + 1;
        randomy = (rand() % (boardSizeY - 2)) + 1;


        if (randomx != blockOff.pos->x || randomy != blockOff.pos->y)
        {
            foodPos.setObjPos(randomx, randomy, '$');
            check = 1;
        }
    }
}


objPos Food::getFoodPos() const
{
    return foodPos;
}


