#include <stdio.h>
#include <string.h>

char board[3][3];
char currentPlayer;

void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int isMoveValid(int move) {
    return (move >= 1 && move <= 9 && board[(move - 1) / 3][(move - 1) % 3] != 'X' && board[(move - 1) / 3][(move - 1) % 3] != 'O');
}

int checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;
    return 0;
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
        }
    }
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void computerMove() {
    char opponent = (currentPlayer == 'X') ? 'O' : 'X';

    
    for (int i = 0; i < 9; i++) {
        if (board[i / 3][i % 3] != 'X' && board[i / 3][i % 3] != 'O') {
            board[i / 3][i % 3] = currentPlayer;
            if (checkWin(currentPlayer)) {
                return;  
            }
            board[i / 3][i % 3] = '1' + i;  
        }
    }

    
    for (int i = 0; i < 9; i++) {
        if (board[i / 3][i % 3] != 'X' && board[i / 3][i % 3] != 'O') {
            board[i / 3][i % 3] = opponent;
            if (checkWin(opponent)) {
                board[i / 3][i % 3] = currentPlayer;  
                return;
            }
            board[i / 3][i % 3] = '1' + i;  
        }
    }

    
    if (board[1][1] != 'X' && board[1][1] != 'O') {
        board[1][1] = currentPlayer;
        return;
    }

    
    int corners[] = {0, 2, 6, 8};
    for (int i = 0; i < 4; i++) {
        int corner = corners[i];
        if (board[corner / 3][corner % 3] != 'X' && board[corner / 3][corner % 3] != 'O') {
            board[corner / 3][corner % 3] = currentPlayer;
            return;
        }
    }

   
    for (int i = 0; i < 9; i++) {
        if (board[i / 3][i % 3] != 'X' && board[i / 3][i % 3] != 'O') {
            board[i / 3][i % 3] = currentPlayer;
            return;
        }
    }
}

int main() {
    int move;
    int mode;
    initializeBoard();
    currentPlayer = 'X';

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Choose mode: '1' for PvP or '2' for PvC: ");
    scanf("%d", &mode);

    printBoard();

    while (1) {
        if (mode == 2 && currentPlayer == 'O') {
            printf("Computer's turn:\n");
            computerMove();
            printBoard();
        } else {
            printf("Player %c, enter a move (1-9): ", currentPlayer);
            scanf("%d", &move);

            if (isMoveValid(move)) {
                board[(move - 1) / 3][(move - 1) % 3] = currentPlayer;
                printBoard();
            } else {
                printf("Invalid move. Please try again.\n");
                continue;
            }
        }

        if (checkWin(currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isBoardFull()) {
            printf("The game is a draw!\n");
            break;
        }

        if (mode == 2 && currentPlayer == 'O') {
            currentPlayer = 'X';
        } else {
            switchPlayer();
        }
    }

    return 0;
}
