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
void clearBoard (char mat[W][H]) {
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            mat[i][j] = ' ';
        }
    }
}

// print the board with the matrix values
void printBoard (char mat[W][H]) {
    for (int i=0; i<H; i++) {
        printf  ("%d -> ", 0+i); // rows numbers
        for (int j=0; j<W; j++) {
            printf ("[%c] ", mat[i][j]);
        } 
        printf ("\n");
    } 
    // columns letters
    printf ("      ");
    for (int i=0; i<H; i++) {
        /* printf  ("%c   ", 65+i); */
        printf ("%d   ", 0+i);
    }
}

// initialize the matrix
void initBoard (char mat[W][H]) {
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            // player 1 / player 2
            if (i < H/2) {
                if ( ((i+j) % 2 == 0) &&  ((i != H/2) && (i != H/2 - 1)) ) {
                    mat[i][j] = PLAYER_1;
                } 
            } else {
                if ( ((i+j) % 2 == 0) &&  ((i != H/2) && (i != H/2 - 1)) ) {
                    mat[i][j] = PLAYER_2;
                }
            }
        }
    }
}

// ask for an element coordinate in the matrix
int insertXorY (int el, int range) {
    do {
        scanf ("%d", &el);
        fflush (stdin);

        if (el < 0 || el > range-1) {
            printf ("Insert a correct value!\n");
        }
    } while (el < 0 || el > range-1); // must be an existing column

    return el;
}

// check if in the box there is a pawn or a king
int isPawnOrKing (int box, char king) {
    if (box == king) return 1;
    else return 0;
}

// check the main direction of the player pawns
int checkDirection (char pawn) {
    if (pawn == PLAYER_1) return 1;
    else return 0;
}

int isInTheBoard (int i, int j) {
    // if the move box is still inside the board
    if (i >= 0 && i < W && j >= 0 && j < H) return 1;
    else return 0;
}

// move the pawn whenever is possible
void movePawn (int len, char player[len], char pawn, char king, char mat[W][H]) {
    int row, column;

    // check if the coordinates you digit correspond to a pawn of yours, in order to be able to move it
    // repeat if there is no pawn or if there is an opponent pawn in that box
    do {
        // getting row and column of the pawn
        printf ("\n\n%s, which pawn do you want to move?\n", player);

        // asking for column and row
        printf ("Insert column: ");
        column = insertXorY (column, W);

        printf ("\n");

        printf ("Insert row: ");
        row = insertXorY (row, H);

        printf ("\nPAWN: %c, INSERED: %c\n", pawn, mat[column][row]);

        // exceptions
        if (mat[column][row] == ' ') {
            printf ("This box is empty...");
        } else if (mat[column][row] != pawn && mat[column][row] != king) {
            printf ("Can't move an opponent pawn!");
        } 

    } while (mat[column][row] != pawn && mat[column][row] != king); // repeat until there is a pawn of yours in that box
    
    // check if is a pawn or a king
    int isKing = isPawnOrKing (mat[column][row], king);

    int iBox, jBox; // destination box coordinates
    int move; // move entered by the player

    // check if the move requested is possible to do
    do {
        printf ("\nIn which direction do you want to move the pawn?\n0 - TL; 1 - TR; 2 - BR; 3 - BL\n");
        scanf("%d", &move);
        fflush (stdin);

        // exceptions
        if (move != 0 && move != 1 && move != 2 && move != 3) {
            printf ("Insert a correct direction!\n");
        }
    } while (move != 0 && move != 1 && move != 2 && move != 3);

    int done = 0; // flag, the move can be done
    int dir = checkDirection (pawn); // main direction of the player pawns (up 0, down 1)
    
    do {
        switch (move) {
            case 0: {
                // TL
                if (dir == 0) { // if your main dir is up you can move top left or top right
                   
                } else {
                    printf ("Can't move in this direction!\n");
                }

                break;
            }
            case 1: {
                // TR
                if (dir == 0) { // if your main dir is up you can move top left or top right
                   
                } else {
                    printf ("Can't move in this direction!\n");
                }

                break;
            }
            case 2: {
                // BR
                if (dir == 1) { // if your main dir is down you can move bottom left or bottom right
                   
                } else {
                    printf ("Can't move in this direction!\n");
                }

                break;
            }
            case 3: {
                // BL
                if (dir == 1) { // if your main dir is down you can move bottom left or bottom right
                   
                } else {
                    printf ("Can't move in this direction!\n");
                }

                break;
            }
        }
    } while (done != 1);

}

int main () {
    char board[W][H];
    int choice;

    do {
        printf ("--- COMMAND LINE DAMA ---\n\n");

        printf  ("1 - New game\n");
        printf  ("2 - Exit\n\n");
        printf  ("Your choice: ");
        scanf ("%d",&choice);
        if (choice == 2) break;

        switch (choice) {
            case 1: {
                int nicknameMaxLen = 10;
                int nicknameMinLen = 3;
                char player1[nicknameMaxLen], player2[nicknameMaxLen];

                // player 1 nickname
                do {
                    printf ("Player 1 (%c), enter a nickname (min %d character, max %d characters): ", PLAYER_1, nicknameMinLen, nicknameMaxLen);
                    scanf ("%s", player1);
                } while (strlen (player1) < nicknameMinLen || strlen (player1) > nicknameMaxLen);

                // player 2 nickname
                do {
                    printf ("\nPlayer 2 (%c), enter a nickname (min %d character, max %d characters): ", PLAYER_2, nicknameMinLen, nicknameMaxLen);
                    scanf ("%s", player2);
                } while (strlen (player2) < nicknameMinLen || strlen (player2) > nicknameMaxLen);
                
                // game start
                printf ("\n\n--- GAME START ---\n");

                // board initialization
                clearBoard (board);
                initBoard (board);
                printBoard (board);

                int end; // flag for the game end

                // the game
                movePawn (nicknameMaxLen, player2, PLAYER_2, PLAYER_2_KING, board);

                // while (end==0) {
                    
                // } ;
                
                break;
            }
            default: {
                printf ("Invalid choice");
                break;
            }
        } 
        printf ("\n\n");
    } while (choice != 0);

    printf  ("Game ended");

    printf ("\n");
    return 0;
}