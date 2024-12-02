#ifndef FOOD_H
#define FOOD_H
#include <stdlib.h>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

class Food
{
    private:
        objPos foodPos;
        objPosArrayList* foodBucket;

    public:
        Food();
        ~Food();

        void generateFood(objPosArrayList* blockOff, int boardSizeX, int boardSizeY);
        objPos getFoodPos() const;
        objPosArrayList* getFoodBucket() const;
        //char getFoodType(int index) const;
};




#endif