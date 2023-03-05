#include <stdio.h>
 
int game();
int PrintField(int Position1player,int Position2player,int BallpositionX,int BallpositionY,int P1score,int P2score);
int Position1playerMoveUp(int Position1player); 
int Position2playerMoveUp(int Position2player);
int Position1playerMoveDown(int Position1player);
int Position2playerMoveDown(int Position2player);
int BallmovementX(int BallpositionX,int BallmoveX);
int BallmovementY(int BallpositionY,int BallmoveY);
int BallmovementCollision(int BallpositionY,int BallmoveY);
int RocketsCollision(int Position1player,int BallpositionY,int Position2player,int BallpositionX, int BallmoveX);
void clear_sreen();
int P1Score(int P1score,int BallpositionX);
int P2Score(int P2score,int BallpositionX);
int NewGame(int BallpositionX);
 
 
int main()
{
    game();
    return 0;
}
 
//main game
 
int game(){
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
    while(P2score!=21 || P1score!=21){
        char action;
        action = getchar();
        check = NewGame(BallpositionX);
        if (check) {
            if (check == 2) {
                P2score = P2Score(P2score,BallpositionX);
                clear_sreen();
                printf("-------------------------------------------");
                printf("\n|                 Player 2 win            |");
                printf("\n-------------------------------------------");
            } else {
                P1score = P1Score(P1score,BallpositionX);
                clear_sreen();
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
            clear_sreen();
            BallpositionY = BallmovementY(BallpositionY,BallmoveY);
            BallpositionX = BallmovementX(BallpositionX,BallmoveX);
 
            BallmoveY = BallmovementCollision(BallpositionY,BallmoveY);
            BallmoveX = RocketsCollision(Position1player,BallpositionY,Position2player,BallpositionX,BallmoveX);
 
            Position1player = Position1playerMoveUp(Position1player);
 
            P1score = P1Score(P1score,BallpositionX);
            P2score = P2Score(P2score,BallpositionX);
            PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);
        
        }else if(action == 'Z' || action == 'z' && Position1player <24){
            clear_sreen();
            BallpositionY = BallmovementY(BallpositionY,BallmoveY);
            BallpositionX = BallmovementX(BallpositionX,BallmoveX);
 
            BallmoveY = BallmovementCollision(BallpositionY,BallmoveY);
            BallmoveX = RocketsCollision(Position1player,BallpositionY,Position2player,BallpositionX,BallmoveX);
            
            Position1player = Position1playerMoveDown(Position1player);
 
            P1score = P1Score(P1score,BallpositionX);
            P2score = P2Score(P2score,BallpositionX);
            PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);
            
        }else if(action == 'K' || action == 'k' && Position2player >1){
            clear_sreen();
            BallpositionY = BallmovementY(BallpositionY,BallmoveY);
            BallpositionX = BallmovementX(BallpositionX,BallmoveX);
 
            BallmoveY = BallmovementCollision(BallpositionY,BallmoveY);
            BallmoveX = RocketsCollision(Position1player,BallpositionY,Position2player,BallpositionX,BallmoveX);
 
            Position2player = Position2playerMoveUp(Position2player);
 
            P1score = P1Score(P1score,BallpositionX);
            P2score = P2Score(P2score,BallpositionX);
            PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);
            
        }else if(action == 'M' || action == 'm' && Position2player <24){
            clear_sreen();
            BallpositionY = BallmovementY(BallpositionY,BallmoveY);
            BallpositionX = BallmovementX(BallpositionX,BallmoveX);
 
            BallmoveY = BallmovementCollision(BallpositionY,BallmoveY);
            BallmoveX = RocketsCollision(Position1player,BallpositionY,Position2player,BallpositionX,BallmoveX);
 
            Position2player = Position2playerMoveDown(Position2player);
 
            P1score = P1Score(P1score,BallpositionX);
            P2score = P2Score(P2score,BallpositionX);
            PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);
            
        }else if(action == '\n'){
            clear_sreen();
            BallpositionY = BallmovementY(BallpositionY,BallmoveY);
            BallpositionX = BallmovementX(BallpositionX,BallmoveX);
 
            BallmoveY = BallmovementCollision(BallpositionY,BallmoveY);
            BallmoveX = RocketsCollision(Position1player,BallpositionY,Position2player,BallpositionX,BallmoveX);
            
            P1score = P1Score(P1score,BallpositionX);
            P2score = P2Score(P2score,BallpositionX);
            PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);
        }else if(action == 'Q' || action == 'q'){
            clear_sreen();
            P2score=+ 21;
            break;
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
 
int Position1playerMoveUp(int Position1player){
    Position1player--;
    return Position1player;
}    
int Position2playerMoveUp(int Position2player){
    Position2player--;
    return Position2player;
}
int Position1playerMoveDown(int Position1player){
    Position1player++;
    return Position1player;
}
int Position2playerMoveDown(int Position2player){
    Position2player++;
    return Position2player;
}
 
//Ballmovement
int BallmovementX(int BallpositionX,int BallmoveX){
    BallpositionX=BallpositionX+BallmoveX;
    return BallpositionX;
}
 
int BallmovementY(int BallpositionY,int BallmoveY){
    BallpositionY=BallpositionY+BallmoveY;
    return BallpositionY;
}
 
//Rockets and pole Collision
 
int BallmovementCollision(int BallpositionY,int BallmoveY){
    if(BallpositionY == 25 || BallpositionY == 0)
    BallmoveY = BallmoveY*(-1);
    return BallmoveY;
}
 
int RocketsCollision(int Position1player,int BallpositionY,int Position2player,int BallpositionX, int BallmoveX){
    if(BallpositionX+1 == 79 && (BallpositionY == Position2player || BallpositionY == Position2player -1 || BallpositionY == Position2player+1))
    BallmoveX = BallmoveX*(-1);
    if(BallpositionX-1 == 0 && (BallpositionY == Position1player || BallpositionY == Position1player -1 || BallpositionY == Position1player +1))
    BallmoveX = BallmoveX*(-1);
    return BallmoveX;
}
 
//clear screen
 
void clear_sreen(){
    printf("\33[0d\33[2J");
}
 
//score changer
 
int P1Score(int P1score,int BallpositionX){
    if (BallpositionX == 1)
    P1score++;
    return P1score;
}
 
int P2Score(int P2score,int BallpositionX){
    if (BallpositionX == 79)
    P2score++;  
    return P2score;
 
}
 
//New round
 
int NewGame(int ball_position_x) {
    int flag = 0;
    if (ball_position_x <= 0) {
        flag = 1;
    }
    if (ball_position_x >= 79) {
        flag = 2;
    }
    return flag;
}