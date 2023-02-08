#include <iostream>

class board {
    public:
        char board[3][3] = {
            {'-', '-', '-'},
            {'-', '-', '-'},
            {'-', '-', '-'}
        };
};

class playerOne {
    public:
        int score = 0;
        bool isTurn = true;
        bool haveWon = false;
};

class playerTwo {
    public:
        int score = 0;
        bool isTurn = false;
        bool haveWon = false;
};

bool canPlace(int row, int column, board& b) {
    if(column > 3 || row > 3) {
        std::cout << "Number out of range!" << std::endl;
        return false;
    }

    if(b.board[row][column] == '-') {
        return true;
    } else {return false;}
}

int placeDown(int row, int column, board &b, playerOne &p1, playerTwo &p2) {

    if(canPlace(row-1,column-1, b) == false) {
        std::cout << "Already Occupied" << std::endl;
        return 1;
    }

    if(p1.isTurn == true) {
        b.board[row-1][column-1] = 'x';
        std::cout << b.board[row][column] << std::endl;
        p1.isTurn = false;
        p2.isTurn = true;
        return 0;
    }

    if(p2.isTurn == true) {
        b.board[row-1][column-1] = 'o';
        p1.isTurn = true;
        p2.isTurn = false;
        return 0;
    }
    return 0;
}

void printBoard(board &b, playerOne &p1, playerTwo &p2) {
    /*
         x | o | x
        ___|___|___
         o | x | o
        ___|___|___
         o | x | x
    */
    printf(
        " %c | %c | %c \n"
        "___|___|___\n"
        " %c | %c | %c \n"
        "___|___|___\n"
        " %c | %c | %c \n",
        b.board[0][0],
        b.board[0][1],
        b.board[0][2],
        b.board[1][0],
        b.board[1][1],
        b.board[1][2],
        b.board[2][0],
        b.board[2][1],
        b.board[2][2]
    );
    if(p1.isTurn == true) {
        std::cout << "Player One turn" << std::endl;
    } else if(p2.isTurn == true) {
        std::cout << "Player Two turn" << std::endl;
    }
}

void checkWin(board &b, playerOne &p1, playerTwo &p2) {
    for(int i=0;i < sizeof(b.board);i++) {

        // Horizontal Line
        if(b.board[i][0] == 'x' && b.board[i][1] == 'x' && b.board[i][2] == 'x') {
            p1.haveWon = true;
        } else if(b.board[i][0] == 'o' && b.board[i][1] == 'o' && b.board[i][2] == 'o') {
            p2.haveWon = true;
        }

        // Vertical Line
        if(b.board[0][i] == 'x' && b.board[1][i] == 'x' && b.board[2][i] == 'x') {
            p1.haveWon = true;
        } else if(b.board[0][i] == 'o' && b.board[1][i] == 'o' && b.board[2][i] == 'o') {
            p2.haveWon = true;
        }

        // Vertical - Top Left to Bottom Right
        if(b.board[0][0] == 'x' && b.board[1][1] == 'x' && b.board[2][2] == 'x') {
            p1.haveWon = true;
        } else if(b.board[0][0] == 'o' && b.board[1][1] == 'o' && b.board[2][2] == 'o') {
            p2.haveWon = true;
        }

        // Vertical - Bottom Left to Top Right
        if(b.board[2][0] == 'x' && b.board[1][1] == 'x' && b.board[0][2] == 'x') {
            p1.haveWon = true;
        } else if(b.board[2][0] == 'o' && b.board[1][1] == 'o' && b.board[0][2] == 'o') {
            p2.haveWon = true;
        }
    }
}

int main() {
    board b;
    playerOne p1;
    playerTwo p2;

    while(p1.haveWon == false || p2.haveWon == false) {
        int row;
        int column;

        checkWin(b, p1, p2);
        printBoard(b, p1, p2);
        
        if(p1.haveWon == true) {
            std::cout << "Player One Wins!" << std::endl;
            break;
        } else if (p2.haveWon == true) {
            std::cout << "Player Two Wins!" << std::endl;
            break;
        }

        std::cout << "Row number: ";
        std::cin >> row;
        std::cout << "Column number: ";
        std::cin >> column;
        placeDown(row, column, b, p1, p2);

    }
}
