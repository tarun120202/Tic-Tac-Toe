board = [['1', '2', '3'], ['4', '5', '6'], ['7', '8', '9']]
current_marker = ''
current_player = 0

def drawboard():
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

def placemarker(slot):
    global current_marker, board
    row = (slot - 1) // 3
    col = (slot - 1) % 3
    if board[row][col] not in ['X', 'O']:
        board[row][col] = current_marker
        return True
    return False

def winner():
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2]:
            return current_player
        if board[0][i] == board[1][i] == board[2][i]:
            return current_player

    if board[0][0] == board[1][1] == board[2][2]:
        return current_player
    if board[0][2] == board[1][1] == board[2][0]:
        return current_player

    return 0

def swap_player_and_marker():
    global current_marker, current_player
    current_marker = 'X' if current_marker == 'O' else 'O'
    current_player = 1 if current_player == 2 else 2

def game():
    global current_player, current_marker
    marker_pl = input("Player 1, Choose your marker (X/O): ")
    current_player = 1
    current_marker = marker_pl.upper()
    drawboard()

    player_won = 0
    for _ in range(9):
        slot = int(input(f"It's Player {current_player}'s turn. Enter your slot (1-9): "))
        if slot < 1 or slot > 9 or not placemarker(slot):
            print("That slot is invalid or occupied! Try again")
            continue

        drawboard()
        player_won = winner()
        if player_won:
            print(f"Player {player_won} WON! CONGRATULATIONS!")
            return

        swap_player_and_marker()

    if not player_won:
        print("That is a Tie Game!")

if __name__ == '__main__':
    game()