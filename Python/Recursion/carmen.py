"""
File: carmen.py
Author: Saim Siddique
Date: 5/12/2024
Section: 14
E-mail: saims1@umbc.edu
Description:
        Welcome to Carmen Sandiego, the python game! Talk to people, investigate clues,
         and go to different places to try and catch Carmen. Beware, you only get three tries,
          good luck!

ATTENTION: PLEASE READ FILE NAMED COMMANDS LIST TO KNOW HOW TO PLAY!!
"""

import json


def load_game(game_file_name):
    """
    :param game_file_name: a string with the game file name
    :return: a dictionary with the game data, or empty if the game file doesn't exist.
    """

    try:
        game = {}
        with open(game_file_name) as game_file:
            game = json.loads(game_file.read())
    except FileNotFoundError:
        print('That file does not exist. ')
        return None

    return game

# the unlock time function essentially takes care of opening up the world for us,
#   it gets called through the clue function and the talk to function
def unlock_time(game, people, clues, locations):
    for person in people:
        game['people'][person]['starts-hidden'] = False
    for clue in clues:
        game['clues'][clue]["starts-hidden"] = False
    for location in locations:
        game['locations'][location]['starts-locked'] = False

# display people shows us the people we can speak to based on what location we are at
def display_people(game, location):
    for person in game["people"]:
        # checks if our person is hidden or not
        starts_hidden = game['people'][person]['starts-hidden']
        if starts_hidden == False:
            # checks if our person is at the location we are searching from
            if game['people'][person]['location'] == location:
                # checks if we talked to said person
                if game['people'][person]['spoken-to'] == False:
                    print(f"{person}        Not spoken to yet")
                else:
                    speach = game['people'][person]['conversation']
                    print(f"{person}        {speach}")

# display location shows us the locations we have available to travel to
def display_location(game):
    for spot in game["locations"]:
        # checks if the location is locked or not
        starts_locked = game['locations'][spot]['starts-locked']
        if starts_locked == False:
            print(spot)

# display clue displays our clues
def display_clue(game):
    for clue in game["clues"]:
        # checks if the clue is locked or not
        starts_hidden = game['clues'][clue]['starts-hidden']
        if starts_hidden == False:
            # checks if we searched the clue or not
            if game['clues'][clue]['searched'] == False:
                print(f"{clue}")
            else:
                big_clue = game['clues'][clue]['clue-text']
                print(f"{clue}        {big_clue}")


# the clue time function pulls the info we need from the clues and unlocks the right things
def clue_time(game, the_clue):
    what_the_clue = game['clues'][the_clue]['clue-text']
    # prints out what our clue is
    print(what_the_clue)
    game['clues'][the_clue]['searched'] = True
    unlocked_people = game['clues'][the_clue]['unlock-people']
    unlocked_clues = game['clues'][the_clue]['unlock-clues']
    unlocked_locations = game['clues'][the_clue]['unlock-locations']
    unlock_time(game, unlocked_people, unlocked_clues, unlocked_locations)

# the talk to function and the clue function are very simular, one for clues, one for people
def talk_to(game, person, list):
    if person in list:
        speach = game['people'][person]['conversation']
        # prints what our person says in convo
        print(speach)
        # sets our spoken to key = to True
        game['people'][person]['spoken-to'] = True
        unlocked_people = game['people'][person]['unlock-people']
        unlocked_clues = game['people'][person]['unlock-clues']
        unlocked_locations = game['people'][person]['unlock-locations']
        # unlocks our game accordingly
        unlock_time(game, unlocked_people, unlocked_clues, unlocked_locations)
    else:
        print("They ain't here big dawg")


# the go-to function is our recursive function, visited_locations is a list so that
#  we don't enter infinite recursion
def go_to(game, current_location, destination, visited_locations):
    # checks if location exists
    if destination not in game['locations']:
        print(f'{destination} does not exist.')
        return False
    # destination cannot be accessed if it is locked
    if game['locations'][destination]['starts-locked']:
        print(f'{destination} is locked.')
        return False
    # if we arrive at destination, the recursion was successful
    if current_location == destination:
        return True
    # ends one of the recursive calls if our call already occurred and was unsuccessful
    if current_location in visited_locations:
        return False

    visited_locations.append(current_location)

    for connected_location in game['locations'][current_location]['connections']:
        # checks every location connected to the previous
        if go_to(game, connected_location, destination, visited_locations):
            return True

    return False


# allows us to try and catch carmen
def catch_carmen(game, current_location):
    if game['locations'][current_location]['carmen'] == True:
        print('You have caught Carmen Sandiego! You win the game!')
        return True
    else:
        return False

# main game loop
def carmen_sandiego(game_file_name):
    game = load_game(game_file_name)
    # if the game dictionary is empty the file didn't exist, we can return here
    game_over = False
    starting_location = game['starting-location']

    # sets a new key, did we speak to a person yet?
    for person in game["people"]:
        game['people'][person]['spoken-to'] = False
    # sets a new key, did we search this clue yet?
    for clue in game['clues']:
        game['clues'][clue]['searched'] = False
    current_location = starting_location
    print(f"You are at: {current_location}")
    # count for tries
    count = 3
    while game_over == False:
        # checks the people we are allowed to speak with
        list_we_talk = []
        for person in game["people"]:
            starts_hidden = game['people'][person]['starts-hidden']
            if starts_hidden == False:
                if game['people'][person]['location'] == current_location:
                    if person not in list_we_talk:
                        # now allows us to speak to the person
                        list_we_talk.append(person)

        action = input('What would you like to do? ')
        action_list = action.split(' ')

        if len(action_list) == 1:
            # command for quit
            if action == 'quit':
                game_over = True

        if len(action_list) == 2:
            # command for displaying people
            if action == 'display people':
                display_people(game, current_location)

            # command for displaying locations
            if action == 'display locations':
                display_location(game)

            # command for displaying clues
            if action == 'display clues':
                display_clue(game)

            # command for catching carmen
            if action == 'catch Carmen':
                if catch_carmen(game, current_location) == True:
                    game_over = True
                else:
                    # eats up one of our tries
                    count -= 1
                    print(f'Carmen is not here, {count} tries left...')


        if len(action_list) == 3:
            # command for speaking to people
            if action_list[0] == 'talk' and action_list[1] == 'to':
                talk_to(game, action_list[2], list_we_talk)

            # command for traveling to locations
            if action_list[0] == 'go' and action_list[1] == 'to':
                visited_list = []
                if go_to(game, current_location, action_list[2], visited_list) == True:
                    current_location = action_list[2]
                    print(f"You are now in: {current_location}")

            # command for investigating clues
            if action_list[0] == 'investigate' and action_list[1] == 'the':
                if action_list[2] in game['clues']:
                    clue_time(game, action_list[2])
                else:
                    print('What clue??????')

        if count == 0:
            print('You lost, game over! Nice try, Malcom')
            game_over = True

# main game loop
if __name__ == '__main__':
    game_file_name = "carmen1.game"
    carmen_sandiego(game_file_name)
