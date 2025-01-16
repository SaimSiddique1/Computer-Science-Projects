"""
File: mancala.py
Author: Saim Siddique
Date: 11/03/2023
Section: 14
E-mail: saims1@umbc.edu
Description:
    Welcome to mancala. Enter the player names that you desire, and choose a cup to move
        according to who's turn it is. The top cups are for player one, and the bottom cups
        are for player tww. When either the top or bottom cups run out, the game concludes.
"""
BLOCK_WIDTH = 6
BLOCK_HEIGHT = 5
BLOCK_SEP = "*"
SPACE = ' '
NUM_CUPS = 6
STONES = 'Stones'

def draw_board(top_cups, bottom_cups, mancala_a, mancala_b):
    board = [[SPACE for _ in range((BLOCK_WIDTH + 1) * (len(top_cups) + 2) + 1)] for _ in range(BLOCK_HEIGHT * 2 + 3)]
    for p in range(len(board)):
        board[p][0] = BLOCK_SEP
        board[p][len(board[0]) - 1] = BLOCK_SEP

    for q in range(len(board[0])):
        board[0][q] = BLOCK_SEP
        board[len(board) - 1][q] = BLOCK_SEP

    # draw midline
    for p in range(BLOCK_WIDTH + 1, (BLOCK_WIDTH + 1) * (len(top_cups) + 1) + 1):
        board[BLOCK_HEIGHT + 1][p] = BLOCK_SEP

    for i in range(len(top_cups)):
        for p in range(len(board)):
            board[p][(1 + i) * (1 + BLOCK_WIDTH)] = BLOCK_SEP

    for p in range(len(board)):
        board[p][1 + BLOCK_WIDTH] = BLOCK_SEP
        board[p][len(board[0]) - BLOCK_WIDTH - 2] = BLOCK_SEP

    for i in range(len(top_cups)):
        draw_block(board, i, 0, top_cups[i])
        draw_block(board, i, 1, bottom_cups[i])

    draw_mancala(0, mancala_a, board)
    draw_mancala(1, mancala_b, board)

    print('\n'.join([''.join(board[i]) for i in range(len(board))]))


def draw_mancala(fore_or_aft, mancala_data, the_board):
    if fore_or_aft == 0:
        for i in range(len(mancala_data)):
            data = mancala_data[i][0: BLOCK_WIDTH].rjust(BLOCK_WIDTH)
            for j in range(len(mancala_data[0])):
                the_board[1 + i][1 + j] = data[j]
    else:
        for i in range(len(mancala_data)):
            data = mancala_data[i][0: BLOCK_WIDTH].rjust(BLOCK_WIDTH)
            for j in range(len(mancala_data[0])):
                the_board[1 + i][len(the_board[0]) - BLOCK_WIDTH - 1 + j] = data[j]


def draw_block(the_board, pos_x, pos_y, block_data):
    for i in range(BLOCK_HEIGHT):
        data = block_data[i][0: BLOCK_WIDTH].rjust(BLOCK_WIDTH)
        for j in range(BLOCK_WIDTH):
            the_board[1 + pos_y * (BLOCK_HEIGHT + 1) + i][1 + (pos_x + 1) * (BLOCK_WIDTH + 1) + j] = data[j]


# determines when the game is over, adds either the top together or the bottom together
# if either total = 0, game is done, winner is announced
def dead_game(game):
    if game[0] + game[1] + game[2] + game[3] + game[4] + game[5] == 0:
        return False
    elif game[7] + game[8] + game[9] + game[10] + game[11] + game[12] == 0:
        return False
    return True


# function that determines whether a stone lands in a mancala
def is_player_mancala(bin_num, player_one):
    return (player_one and bin_num == 6) or (not player_one and bin_num == 13)


# function to create cups
def create_cups(start, end, initial_stones=None, clockwise=False):
    cups = []
    if clockwise:
        cup_range = range(start, end + 1)
    else:
        # reverses cup number order
        cup_range = range(end, start - 1, -1)

    for i in cup_range:
        # alot of space after cup so it prints on the left side
        current_cup = ["Cup"+'    ', str(i)]
        current_cup.append("Stones")
        if initial_stones is not None and i - start < len(initial_stones):
            current_cup.append(str(initial_stones[i - start]))
        else:
            current_cup.append("0")
        for _ in range(BLOCK_HEIGHT - 3):
            current_cup.append(" " * BLOCK_WIDTH)
        cups.append(current_cup)
    return cups


# function that stores the info needed for both mancala's
# gets called in my print board function
def create_mancalas(player_one_name, player_two_name, player_one_stones, player_two_stones):
    mancala_a = []
    mancala_b = []
    for i in range(2 * BLOCK_HEIGHT):
        # appended value to the list based on different numbers, specifically their index going down the list
        if i == 2:
            mancala_a.append(player_two_name.ljust(BLOCK_WIDTH))
            mancala_b.append(player_one_name.ljust(BLOCK_WIDTH))
        elif i == 6:
            mancala_a.append(STONES.ljust(BLOCK_WIDTH))
            mancala_b.append(STONES.ljust(BLOCK_WIDTH))
        elif i == 7:
            mancala_a.append(player_two_stones.ljust(BLOCK_WIDTH))
            mancala_b.append(player_one_stones.ljust(BLOCK_WIDTH))
        else:
            mancala_a.append(" " * BLOCK_WIDTH)
            mancala_b.append(" " * BLOCK_WIDTH)
    return mancala_a, mancala_b


# function that runs the whole game
def run_game(game, player_one_name, player_two_name, clockwise=False):
    def print_board():
        # allows the board to print the numbers in reverse order, using info given in line 92
        if clockwise:
            first_cups = create_cups(1, NUM_CUPS, game[0:6])
            second_cups = create_cups(8, 13, game[7:13], clockwise=True)
        else:
            first_cups = create_cups(1, NUM_CUPS, game[0:6], clockwise=True)
            second_cups = create_cups(8, 13, game[7:13])

        # once again was unsure how not to return two things here from the mancala function
        # as each mancala had to be stored on its own to print in the board
        mancala_one, mancala_two = create_mancalas(player_one_name, player_two_name, str(game[6]), str(game[13]))

        # prints the board
        draw_board(first_cups, second_cups, mancala_one, mancala_two)


    # determines if the move made is allowed, and is specific to each player
    # if player one = true, its player one and if player two = false, its player two
    def valid_move(user_choice, player_one):
        if player_one:
            return 1 <= user_choice <= 6 and game[user_choice - 1] > 0
        else:
            return 8 <= user_choice <= 13 and game[user_choice - 1] > 0


    def make_move(user_choice, player_one):
        # gets number of stone in a cup chosen by the user
        stones = game[user_choice - 1]
        current_bin = user_choice
       # sets that cups value to 0
        game[user_choice - 1] = 0

        while stones > 0:
            current_bin = (current_bin % 14) + 1
            if (current_bin == 6 and not player_one) or (current_bin == 13 and player_one):
                pass  # Skip the opponent's mancala
            game[current_bin - 1] += 1
            stones -= 1
        if (current_bin == 7 and player_one) or (current_bin == 14 and not player_one):
            print(player_name+' landed in a Mancala.')
            return current_bin, True  # Returns True to indicate an extra turn
        else:
            return current_bin, False # False indicates no extra turn

    player_one = True

    while dead_game(game):
        print_board()
        # this line sets whoever the current player is = to the players name that I use in the print statements
        player_name = player_one_name if player_one else player_two_name
        user_choice = None

        while user_choice is None:
            message = f"{player_name}'s turn. Choose a bin (1-6 for {player_one_name}, 8-13 for {player_two_name}): "
            user_input = input(message)

            # fancy function I found, allows me to funnel through different user inputs
            # if it's a number, we continue with our checking process, if not we stop (probably illegal idk)
            if user_input.isdigit():
                user_choice = int(user_input)

                if valid_move(user_choice, player_one):
                    last_bin, extra_turn = make_move(user_choice, player_one)
                    if not extra_turn:
                        player_one = not player_one
                else:
                    print("Invalid move. Try again.")
            else:
                print("Invalid input. Please enter a valid bin number (1-6 or 8-13).")

    print_board()
    print("The game is over!")

    # determines win loss or draw
    if game[6] < game[13]:
        print(f"{player_two_name} has won the game!")
    elif game[6] > game[13]:
        print(f"{player_one_name} has won the game!")
    else:
        print("The game ended in a tie")


# gets names of the player, was unsure on how to accomplish this without returning two variables
def get_player_names():
    player_one_name = input('Player 1, please tell me your name: ')
    player_two_name = input('Player 2, please tell me your name: ')
    return player_one_name, player_two_name


if __name__ == '__main__':
    game = [4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 4, 4, 0]
    names = get_player_names()
    player_one_name = names[0]
    player_two_name = names[1]
    # runs game, once again was unsure how to do this without returning both names out the function, probably with some sort of dictionary,
    # but i would still end up with a global variable, which is what I have for the names
    run_game(game, player_one_name, player_two_name)