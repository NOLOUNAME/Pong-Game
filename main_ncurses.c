#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
 
#define S_SPEED 3000000
 
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
    printf("-------------------------------------------\n");
    printf("|                 BONG GAME               |\n");
    printf("-------------------------------------------\n");
    usleep(S_SPEED);
    initscr();
    nodelay(stdscr, TRUE);
    while(P2score!=21 || P1score!=21){
        char action;
        action = getch();
        check = NewGame(BallpositionX);
        if (check) {
            if (check == 2) {
                P2score = P2Score(P2score,BallpositionX);
                clear_sreen();
                printf("\n|                 Player 2 win            |\n");
                usleep(S_SPEED/2);
            } else {
                P1score = P1Score(P1score,BallpositionX);
                clear_sreen();
                printf("\n|                 Player 1 win            |\n");
                usleep(S_SPEED/2);
            }
            BallpositionX = 39;
            BallpositionY = 13;
            Position1player = 13;
            Position2player = 13;
        }
 
        BallpositionY = BallmovementY(BallpositionY,BallmoveY);
        BallpositionX = BallmovementX(BallpositionX,BallmoveX);
        P1score = P1Score(P1score,BallpositionX);
        P2score = P2Score(P2score,BallpositionX);
        BallmoveY = BallmovementCollision(BallpositionY,BallmoveY);
        BallmoveX = RocketsCollision(Position1player,BallpositionY,Position2player,BallpositionX,BallmoveX);
        PrintField(Position1player,Position2player,BallpositionX,BallpositionY,P1score,P2score);
 
        if((action == 'A' || action == 'a') && Position1player >1){
 
            Position1player = Position1playerMoveUp(Position1player);
        
        }else if((action == 'Z' || action == 'z') && Position1player <24){
            
            Position1player = Position1playerMoveDown(Position1player);
            
        }else if((action == 'K' || action == 'k') && Position2player >1){
 
            Position2player = Position2playerMoveUp(Position2player);
            
        }else if((action == 'M' || action == 'm') && Position2player <24){
 
            Position2player = Position2playerMoveDown(Position2player);
 
        }else if(action == 'Q' || action == 'q'){
            clear_sreen();
            P2score=+ 21;
            break;
        }
    }
    nodelay(stdscr, FALSE);
    refresh();
    endwin();
    return 0;
}
 
//PrintField
 
int PrintField(int Position1player,int Position2player,int BallpositionX,int BallpositionY,int P1score,int P2score){
    clear();
    usleep(50000);
    printw("Player 1: %d                                                            Player 2: %d\n", P1score, P2score);
    printw("+--------------------------------------------------------------------------------+\n");
    for(int i=0;i<26;i++){
        printw("|");
        for(int j=0;j<80;j++){
            if(j==0 && (i == Position1player || i == Position1player-1 || i == Position1player+1))
                printw("]");
            else if(j==79 && (i == Position2player || i == Position2player-1 || i == Position2player+1))
                printw("[");
            else if (i== BallpositionY && j== BallpositionX)
                printw("O");
            else
                printw(" ");
        }
        printw("|");
        printw("\n");
    }
    printw("+--------------------------------------------------------------------------------+\n");
    refresh();
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