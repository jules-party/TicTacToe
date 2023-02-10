#pragma once

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
        bool isTurn = true;
        bool haveWon = false;
};

class playerTwo {
    public:
        bool isTurn = false;
        bool haveWon = false;
};