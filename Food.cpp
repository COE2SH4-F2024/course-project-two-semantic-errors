#include "Food.h"

Food::Food()
{
    foodBucket = new objPosArrayList();
    foodPos.setObjPos(-1, -1, '?');

}

Food::~Food()
{
    delete foodBucket;

}

void Food::generateFood(objPosArrayList* blockOff, int boardSizeX, int boardSizeY)
{
    srand(time(NULL));
    foodBucket->~objPosArrayList();
    foodBucket = new objPosArrayList();

    int totalFood = 3;
    char foodSymbols[3] {'?', '!', '$'};

    for (int i = 0; i<totalFood; i++) //Generate 3 food items
    {
        bool isNotOnArray;
        int randomx, randomy;
        int size = blockOff->getSize();
        do{
            randomx = (rand() % (boardSizeX - 2)) + 1;
            randomy = (rand() % (boardSizeY - 2)) + 1;
            isNotOnArray = true;
            for(int j = 0 ; j < size; j++)
            {
                int x = blockOff->getElement(j).pos->x;
                int y = blockOff->getElement(j).pos->y;
                if(x == randomx && y == randomy){
                    isNotOnArray = false;
                    break;
                }

            }
        }while(!isNotOnArray);

        char symbol = foodSymbols[rand() % 3];
        foodPos.setObjPos(randomx, randomy, symbol);
        foodBucket->insertTail(foodPos);
    }
}


objPos Food::getFoodPos() const
{
    return foodPos;
}

objPosArrayList* Food::getFoodBucket() const
{
    return foodBucket;
}


