#include <stdio.h>
#include <conio.h>
#include <string.h>

#define W 8
#define H 8
#define PLAYER_1 'x'
#define PLAYER_1_KING 'X'
#define PLAYER_2 'o'
#define PLAYER_2_KING 'O'

// clear all the matrix values
void clearBoard(char mat[W][H]){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            mat[i][j] = ' ';
        }
    }
}

// print the board with the matrix values
void printBoard(char mat[W][H]){
    for(int i=0; i<H; i++){
        printf ("%d -> ", 0+i); // rows numbers
        for(int j=0; j<W; j++){
            printf("[%c] ", mat[i][j]);
        }
        printf ("\n");
    }
    // columns letters
    printf("      ");
    for(int i=0; i<H; i++){
        /* printf ("%c   ", 65+i); */
        printf ("%d   ", 0+i);
    }
}

// initialize the matrix
void initBoard(char mat[W][H]){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            // player 1 / player 2
            if(i < H/2){
                if( ((i+j) % 2 == 0) && ( (i != H/2) && (i != H/2 - 1) )){
                    mat[i][j] = PLAYER_1;
                }
            }else{
                if( ((i+j) % 2 == 0) && ( (i != H/2) && (i != H/2 - 1) )){
                    mat[i][j] = PLAYER_2;
                }
            }
        }    
    }
}

// move the pawn whenever is possible
void movePawn(int len, char player[len], char pawn, char mat[W][H]){
    int row, column;

    // check if the coordinates you digit correspond to a pawn of yours, in order to be able to move it
    // repeat if there is no pawn or if there is an enemy pawn in that box
    do{
        // getting row and column of the pawn
        printf("%s, which pawn do you want to move?\n", player);

        do{
            printf("Insert row: ");
            scanf("%d", &row); // i
            fflush(stdin);
        }while(row < 0 || row > H-1);

        printf("\n");
        
        do{
            printf("Insert column: ");
            scanf("%d", &column); // j
            fflush(stdin);
        }while(column < 0 || column > W-1);

    printf("PAWN: %c, INSERED: %c", pawn, mat[row][column]); // test

    }while(mat[row][column] != pawn);

    // check if the move requested is possible to do
    printf("Where do you want to move the pawn?");
    
}

int main(){
    char board[W][H];
    int choice;

    do{
        printf("--- COMMAND LINE DAMA ---\n");
        printf("\t-- menu --\n\n");

        printf ("1 - New game\n");
        printf ("2 - Exit\n\n");
        printf ("Your choice: ");
        scanf("%d",&choice);
        if (choice == 2) break;

        switch(choice){
            case 1: {
                int nicknameMaxLen = 10;
                int nicknameMinLen = 3;
                char player1[nicknameMaxLen], player2[nicknameMaxLen];

                // player 1 nickname
                do{
                    printf("Player 1 (%c), enter a nickname (min %d character, max %d characters): ", PLAYER_1, nicknameMinLen, nicknameMaxLen);
                    scanf("%s", player1);
                }while(strlen(player1) < nicknameMinLen || strlen(player1) > nicknameMaxLen);

                // player 2 nickname
                do{
                    printf("\nPlayer 2 (%c), enter a nickname (min %d character, max %d characters): ", PLAYER_2, nicknameMinLen, nicknameMaxLen);
                    scanf("%s", player2);
                }while(strlen(player2) < nicknameMinLen || strlen(player2) > nicknameMaxLen);
                
                // game start
                printf("\n\n--- GAME START ---\n");

                // board initialization
                clearBoard(board);
                initBoard(board);
                printBoard(board);

                int end; // flag for the game end

                // the game
                movePawn(nicknameMaxLen, player1, PLAYER_1, board);

                // while(end==0){
                    
                // };
                
                break;
            }
            default: {
                printf("Invalid choice");
                break;
            }
        }
        printf("\n\n");
    }while(choice != 0);

    printf ("Game ended");

    printf("\n");
    return 0;
}