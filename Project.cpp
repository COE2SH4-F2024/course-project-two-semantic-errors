#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* mech;
objPos** board;
//int height =  10;
//int width = 20;
Player* x = nullptr;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(mech->getExitFlagStatus() == false)  
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
   

    mech = new GameMechs();
    int height = mech->getBoardSizeY();
    int width = mech->getBoardSizeX();
    
    x = new Player(mech);
    board = new objPos*[height];
    for(int i =0; i< height; i++){
        board[i] = new objPos[width];
    }
   
   
}

void GetInput(void)
{
   if(MacUILib_hasChar()){
    mech->setInput(MacUILib_getChar());
   }
}

void RunLogic(void)
{
    x->updatePlayerDir();
    x->movePlayer();
   
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
     
    int height = mech->getBoardSizeY();
    int width = mech->getBoardSizeX();
    objPos playerPos = x->getPlayerPos();
    int pX = playerPos.pos->x;
    int pY = playerPos.pos->y;
    if(!mech->getLoseFlagStatus()){
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
            board[pY][pX].setObjPos(pY, pX, playerPos.symbol);
            board[1][1].setObjPos(1,1,'A');
            board[2][2].setObjPos(2,2,'B');
            for(int i =0; i < height; i++){
                for(int j = 0; j < width; j++){
                    MacUILib_printf("%c", board[i][j].symbol);
                }
                MacUILib_printf("\n");
            }
    }else{
        MacUILib_printf("**GAME OVER**\n**SCORE: %d**",mech->getScore());
    }
        
    
    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen(); 
    int height = mech->getBoardSizeY();
    for (int i = 0; i < height; i++) {
        delete[] board[i];  
    }
    delete[] board;  
    delete mech;  
    delete x;    

    MacUILib_uninit();
}

