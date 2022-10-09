#include <stdio.h>
#include <conio.h>

#define W 8
#define H 8

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
        for(int j=0; j<W; j++){
            printf("[%c] ", mat[i][j]);
        }
        printf ("\n");
    }
}

// initialize the matrix
void initBoard(char mat[W][H]){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            // check player 1 / player 2
            if(i < H/2){
                if( ((i+j) % 2 == 0) && ( (i != H/2) && (i != H/2 - 1) )){
                    mat[i][j] = 'x';
                }
            }else{
                if( ((i+j) % 2 == 0) && ( (i != H/2) && (i != H/2 - 1) )){
                    mat[i][j] = 'o';
                }
            }
        }    
    }
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
                clearBoard(board);
                initBoard(board);
                printBoard(board);
                
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