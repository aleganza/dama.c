#include <stdio.h>

#define W 8
#define H 8

void clearBoard(char mat[W][H]){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            mat[i][j] = ' ';
        }    
    }
}

void printBoard(char mat[W][H]){
    for(int i=0; i<H; i++){
        printf ("| ");
        for(int j=0; j<W; j++){
            printf ("%c | ", mat[i][j]);
        }
        printf ("\n");
        for(int j=0; j<W; j++){
            printf ("____");
        }
        printf ("\n");
    }
}

/* void initBoard(char mat[][]){

} */

int main(){
    char board[W][H];

    clearBoard(board);
    printBoard(board);
    /* initBoard(board); */

    printf("\n");
    return 0;
}