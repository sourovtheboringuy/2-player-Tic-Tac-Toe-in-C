#include <stdio.h>

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

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
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

int main() {
    int move;
    currentPlayer = 'X';
    initializeBoard();

    printf("Welcome to Tic-Tac-Toe!\n");
    printBoard();

    while (1) {
        printf("Player %c, enter a move (1-9): ", currentPlayer);
        scanf("%d", &move);

        if (isMoveValid(move)) {
            board[(move - 1) / 3][(move - 1) % 3] = currentPlayer;
            printBoard();

            if (checkWin()) {
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            if (isBoardFull()) {
                printf("The game is a draw!\n");
                break;
            }

            switchPlayer();
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}
