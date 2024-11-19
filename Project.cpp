#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000

objPos** board;
int height = 10;
int width = 20;
bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    board = new objPos*[height];
    for(int i =0; i< height; i++){
        board[i] = new objPos[width];
    }
    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
     

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++){
            if(i == 0 || i == height - 1|| j ==0 || j == width - 1){
                board[i][j].setObjPos(i,j,'#');
            }
            else{
                board[i][j].setObjPos(i,j,' ');
            }
            
        }
    }
    board[1][1].setObjPos(1,1,'A');
    board[2][2].setObjPos(2,2,'B');
    for(int i =0; i < height; i++){
        for(int j = 0; j < width; j++){
            MacUILib_printf("%c", board[i][j].symbol);
        }
        MacUILib_printf("\n");
    }
    
    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen(); 
    for (int i = 0; i < height; i++){
        delete[] board[i];
    }   
    delete[] board;
    MacUILib_uninit();
}

