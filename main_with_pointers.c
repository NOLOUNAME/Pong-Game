#include <stdio.h>
 
int Game();
int PrintField(int Position1player,int Position2player,int BallpositionX,int BallpositionY,int P1score,int P2score);
int Position1playerMoveUp(int *Position1player); 
int Position2playerMoveUp(int *Position2player);
int Position1playerMoveDown(int *Position1player);
int Position2playerMoveDown(int *Position2player);
int BallmovementX(int *BallpositionX,int *BallmoveX);
int BallmovementY(int *BallpositionY,int *BallmoveY);
int BallmovementCollision(int *BallpositionY,int *BallmoveY);
int RocketsCollision(int *Position1player,int *BallpositionY,int *Position2player,int *BallpositionX, int *BallmoveX);
void ClearScreen();
int P1Score(int *P1score,int *BallpositionX);
int P2Score(int *P2score,int *BallpositionX);
int NewGame(int *BallpositionX);

int main()
{
    Game();
    return 0;
}

//main game

int Game(){
    int Position1player = 13;
    int Position2player = 13;
    int BallmoveX = 1;
    int BallmoveY = 1;
    int BallpositionX = 39;
    int BallpositionY = 13;
    int P1score = 0;
    int P2score = 0;
    int check;
    printf("-------------------------------------------");
    printf("\n|                 BONG GAME               |");
    printf("\n|                By stuartis              |");
    printf("\n-------------------------------------------");
    while(P2score<21 && P1score<21){
        char action;
        action = getchar();
        check = NewGame(&BallpositionX);
        if (check) {
            if (check == 2) {
                P2Score(&P2score,&BallpositionX);
                ClearScreen();
                printf("-------------------------------------------");
                printf("\n|                 Player 2 win            |");
                printf("\n-------------------------------------------");
            } else {
                P1Score(&P1score,&BallpositionX);
                ClearScreen();
                printf("-------------------------------------------");
                printf("\n|                 Player 1 win            |");
                printf("\n-------------------------------------------");
            }
            BallpositionX = 39;
            BallpositionY = 13;
            Position1player = 13;
            Position2player = 13;
        }
        
        if(action == 'A' || action == 'a' && Position1player >1){
            ClearScreen();
            BallmovementY(&BallpositionY,&BallmoveY);
            BallmovementX(&BallpositionX,&BallmoveX);
            BallmovementCollision(&BallpositionY,&BallmoveY);
            RocketsCollision(&Position1player,&BallpositionY,&Position2player,&BallpositionX,&BallmoveX);
            Position1playerMoveUp(&Position1player);
            PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);   
        }else if(action == 'Z' || action == 'z' && Position1player <24){
            ClearScreen();
            BallmovementY(&BallpositionY,&BallmoveY);
            BallmovementX(&BallpositionX,&BallmoveX);
            BallmovementCollision(&BallpositionY,&BallmoveY);
            RocketsCollision(&Position1player,&BallpositionY,&Position2player,&BallpositionX,&BallmoveX);
            Position1playerMoveDown(&Position1player);
            PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);           
        }else if(action == 'K' || action == 'k' && Position2player >1){
            ClearScreen();
            BallmovementY(&BallpositionY,&BallmoveY);
            BallmovementX(&BallpositionX,&BallmoveX);
            BallmovementCollision(&BallpositionY,&BallmoveY);
            RocketsCollision(&Position1player,&BallpositionY,&Position2player,&BallpositionX,&BallmoveX);
            Position2playerMoveUp(&Position2player);
            PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);            
        }else if(action == 'M' || action == 'm' && Position2player <24){
            ClearScreen();
            BallmovementY(&BallpositionY,&BallmoveY);
            BallmovementX(&BallpositionX,&BallmoveX);
            BallmovementCollision(&BallpositionY,&BallmoveY);
            RocketsCollision(&Position1player,&BallpositionY,&Position2player,&BallpositionX,&BallmoveX);
            Position2playerMoveDown(&Position2player);
            PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);
        }else if(action == 'Q' || action == 'q'){
            ClearScreen();
            printf("-------------------------------------------");
            printf("\n|             Thanks for game             |");
            printf("\n-------------------------------------------");
            P2score= 21;
            break;
        }else if (action == ' '){
            ClearScreen();
            BallmovementY(&BallpositionY,&BallmoveY);
            BallmovementX(&BallpositionX,&BallmoveX);
            BallmovementCollision(&BallpositionY,&BallmoveY);
            RocketsCollision(&Position1player,&BallpositionY,&Position2player,&BallpositionX,&BallmoveX);
            PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);
        }
    }
    return 0;
}

//PrintField

int PrintField(int Position1player,int Position2player,int BallpositionX,int BallpositionY,int P1score,int P2score){
    printf("Player 1: %d                                                            Player 2: %d\n", P1score, P2score);
    printf("+--------------------------------------------------------------------------------+\n");
    for(int i=0;i<26;i++){
        printf("|");
        for(int j=0;j<80;j++){
            if(j==0 && (i == Position1player || i == Position1player-1 || i == Position1player+1))
                printf("]");
            else if(j==79 && (i == Position2player || i == Position2player-1 || i == Position2player+1))
                printf("[");
            else if (i== BallpositionY && j== BallpositionX)
                printf("*");
            else
                printf(" ");
        }
        printf("|");
        printf("\n");
    }
    printf("+--------------------------------------------------------------------------------+\n");
    return 0;
}

//move rockets

int Position1playerMoveUp(int *Position1player){
    *Position1player=*Position1player-1;
    return *Position1player;
}    
int Position2playerMoveUp(int *Position2player){
    *Position2player=*Position2player-1;
    return *Position2player;
}
int Position1playerMoveDown(int *Position1player){
    *Position1player=*Position1player+1;
    return *Position1player;
}
int Position2playerMoveDown(int *Position2player){
    *Position2player=*Position2player+1;
    return *Position2player;
}
 
//Ballmovement
int BallmovementX(int *BallpositionX,int *BallmoveX){
    *BallpositionX=*BallpositionX+*BallmoveX;
    return *BallpositionX;
}
 
int BallmovementY(int *BallpositionY,int *BallmoveY){
    *BallpositionY=*BallpositionY+*BallmoveY;
    return *BallpositionY;
}
 
//Rockets and pole Collision
 
int BallmovementCollision(int *BallpositionY,int *BallmoveY){
    if(*BallpositionY == 25 || *BallpositionY == 0)
    *BallmoveY = *BallmoveY*(-1);
    return *BallmoveY;
}
 
int RocketsCollision(int *Position1player,int *BallpositionY,int *Position2player,int *BallpositionX, int *BallmoveX){
    if(*BallpositionX+1 == 79 && (*BallpositionY == *Position2player || *BallpositionY == *Position2player -1 || *BallpositionY == *Position2player+1))
    *BallmoveX = *BallmoveX*(-1);
    if(*BallpositionX-1 == 0 && (*BallpositionY == *Position1player || *BallpositionY == *Position1player -1 || *BallpositionY == *Position1player +1))
    *BallmoveX = *BallmoveX*(-1);
    return *BallmoveX;
}
 
//clear screen
 
void ClearScreen(){
    printf("\33[0d\33[2J");
}
 
//score changer
 
int P1Score(int *P1score,int *BallpositionX){
    if (*BallpositionX == 1)
    *P1score=*P1score+1;
    return *P1score;
}
 
int P2Score(int *P2score,int *BallpositionX){
    if (*BallpositionX == 79)
    *P2score=*P2score+1;  
    return *P2score;
}
 
//New round
 
int NewGame(int *BallpositionX) {
    int flag = 0;
    if (*BallpositionX <= 0) {
        flag = 1;
    }
    if (*BallpositionX >= 79) {
        flag = 2;
    }
    return flag;
}