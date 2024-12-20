#include "objPosArrayList.h"
#include <iostream>


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
    if (listSize >= arrayCapacity) {
        // Resize logic here
        arrayCapacity *= 2; // or use another resizing strategy
        objPos* newArr = new objPos[arrayCapacity]; // reallocate to a bigger array
        for (int i = 0; i < listSize; i++) {
            newArr[i] = aList[i]; // copy existing items to new array
        }
        delete[] aList;
        aList = newArr;
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
    if(index < 0 || index >= listSize) throw std::out_of_range("Index out of range for list");

    return aList[index];
}