#include <iostream>
#include <vector>

const int SIZE = 3;

void printBoard(const std::vector<std::vector<char> > &board) {
    std::cout << "-------------\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "| ";
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < SIZE; ++i) {
        bool win = true;
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != player) {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }
    }

    for (int j = 0; j < SIZE; ++j) {
        bool win = true;
        for (int i = 0; i < SIZE; ++i) {
            if (board[i][j] != player) {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }
    }

    bool win = true;
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][i] != player) {
            win = false;
            break;
        }
    }
    if (win) {
        return true;
    }

    win = true;
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][SIZE - 1 - i] != player) {
            win = false;
            break;
        }
    }
    return win;
}

bool boardFull(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(SIZE, std::vector<char>(SIZE, ' '));
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        int row,col;
        std::cout << "Ход игрока " << currentPlayer << ". Введите номер строки и столбца (0-2): ";
        std::cin >> row >> col;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            std::cout << "Некорректный ввод. Попробуйте ещё раз.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board,currentPlayer)) {
            printBoard(board);
            std::cout << "Поздравляем! Игрок " << currentPlayer << " победил!\n";
            gameOver = true;
        } else if (boardFull(board)) {
            printBoard(board);
            std::cout << "Ничья!\n";
            gameOver = true;
        }
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    return 0;
}
