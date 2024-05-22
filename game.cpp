#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<char>> board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker = ' ';
int current_player = 0;

void drawboard() {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " | ";
        }
        std::cout << std::endl;
        std::cout << "---------" << std::endl;
    }
}

bool placemarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

int winner() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }

    return 0;
}

void swap_player_and_marker() {
    current_marker = (current_marker == 'X') ? 'O' : 'X';
    current_player = (current_player == 1) ? 2 : 1;
}

void game() {
    char marker_pl;
    std::cout << "Player 1, Choose your marker (X/O): ";
    std::cin >> marker_pl;
    current_player = 1;
    current_marker = std::toupper(marker_pl);
    drawboard();

    int player_won = 0;
    for (int i = 0; i < 9; ++i) {
        int slot;
        std::cout << "It's Player " << current_player << "'s turn. Enter your slot (1-9): ";
        std::cin >> slot;
        if (slot < 1 || slot > 9 || !placemarker(slot)) {
            std::cout << "That slot is invalid or occupied! Try again" << std::endl;
            --i; // Re-try the same turn
            continue;
        }

        drawboard();
        player_won = winner();
        if (player_won) {
            std::cout << "Player " << player_won << " WON! CONGRATULATIONS!" << std::endl;
            return;
        }

        swap_player_and_marker();
    }

    if (!player_won) {
        std::cout << "That is a Tie Game!" << std::endl;
    }
}

int main() {
    game();
    return 0;
}
