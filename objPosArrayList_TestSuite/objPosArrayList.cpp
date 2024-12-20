#include "objPosArrayList.h"
#include <iostream>
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize >= ARRAY_MAX_CAP){
        throw std::overflow_error("List Capacity Exceeded");
    }
    for(int i = listSize; i >0; i--){
        aList[i] = aList[i-1];
    }

    aList[0] = thisPos;

    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize >= arrayCapacity){
        throw std::overflow_error("List Capacity Exceeded");
    }

    aList[listSize++] = thisPos;
    
}

void objPosArrayList::removeHead()
{
    if(listSize == 0) return;
    
    for (int i = 0; i < listSize - 1; i++) {
        aList[i] = aList[i + 1];
    }

    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize > 0){
        listSize--;
    }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    //if throwing the excpetion causes errors this also works
    if(index < 0) index = 0;  
    if(index >= listSize) return aList[listSize];

    return aList[index];
}