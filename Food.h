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

    public:
        Food();
        ~Food();

        void generateFood(objPos blockOff, int boardSizeX, int boardSizeY);
        objPos getFoodPos() const;
};




#endif