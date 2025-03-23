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

bool checkWin(const std::vector<std::vector<char> > &board, char player) {
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

bool boardFull(const std::vector<std::vector<char> > &board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}


int minimax(std::vector<std::vector<char> > &board, bool isMaximizing) {
    if (checkWin(board, 'O')) {
        return 10;
    }
    if (checkWin(board, 'X')) {
        return -10;
    }
    if (boardFull(board)) {
        return 0;
    }

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(board, false);
                    board[i][j] = ' ';
                    bestScore = std::max(bestScore, score);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(board, true);
                    board[i][j] = ' ';
                    bestScore = std::min(bestScore, score);
                }
            }
        }
        return bestScore;
    }
}

std::pair<int, int> bestMove(std::vector<std::vector<char> > &board) {
    int bestScore = -1000;
    std::pair<int, int> move = {-1, -1};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax(board, false);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    move = {i, j};
                }
            }
        }
    }
    return move;
}

int main() {
    int mode;
    std::cout << "Выберите режим игры:\n";
    std::cout << "1. Человек vs Человек\n";
    std::cout << "2. Человек vs Компьютер\n";
    std::cin >> mode;

    std::vector<std::vector<char> > board(SIZE, std::vector<char>(SIZE, ' '));
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        if (mode == 2 && currentPlayer == 'O') {
            std::cout << "Ход компьютера (" << currentPlayer << "):\n";
            std::pair<int, int> move = bestMove(board);
            if (move.first != -1 && move.second != -1) {
                board[move.first][move.second] = currentPlayer;
            }
        } else {
            int row, col;
            std::cout << "Ход игрока " << currentPlayer << ". Введите номер строки и столбца (0-2): ";
            std::cin >> row >> col;

            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
                std::cout << "Некорректный ввод. Попробуйте ещё раз.\n";
                continue;
            }
            if (board[row][col] != ' ') {
                std::cout << "Ячейка уже занята. Попробуйте ещё раз.\n";
                continue;
            }
            board[row][col] = currentPlayer;
        }

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            if (mode == 2 && currentPlayer == 'O') {
                std::cout << "Компьютер (" << currentPlayer << ") победил!\n";
            } else {
                std::cout << "Поздравляем! Игрок " << currentPlayer << " победил!\n";
            }
            gameOver = true;
        } else if (boardFull(board)) {
            printBoard(board);
            std::cout << "Ничья!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
