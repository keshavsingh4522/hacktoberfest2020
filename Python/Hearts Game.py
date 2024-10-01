from __future__ import annotations
from cgitb import handler
from enum import Enum
from random import shuffle
import random as rand


class Rank(Enum):
    Two = 2
    Three = 3
    Four = 4
    Five = 5
    Six = 6
    Seven = 7
    Eight = 8
    Nine = 9
    Ten = 10
    Jack = 11
    Queen = 12
    King = 13
    Ace = 14

    def __lt__(self, other: Rank) -> bool:
        return self.value < other.value


class Suit(Enum):
    Clubs = 1
    Diamonds = 2
    Spades = 3
    Hearts = 4

    def __lt__(self, other: Suit) -> bool:
        return self.value < other.value


class Card:

    def __init__(self, rank: Rank, suit: Suit) -> None:
        self.rank = rank
        self.suit = suit

    def __repr__(self) -> str:
        return self.__str__()

    def __str__(self) -> str:
        statement = str(self.rank.name) + " of "+str(self.suit.name)
        return statement

    def __eq__(self, other: Card) -> bool:
        if self.rank == other.rank and self.suit == other.suit:
            is_equal = True
        else:
            is_equal = False
        return is_equal

    def __lt__(self, other: Card) -> bool:
        if self.suit == other.suit:
            return self.rank < other.rank
        else:
            return self.suit < other.suit


class BasicAIPlayer:
    def __init__(self, name: str):
        self.hand = []
        self.round_score = 0
        self.total_score = 0
        self.name = name

    def __str__(self) -> str:
        return self.name

    def __repr__(self) -> str:
        return self.__str__()

    def play_card(self, trick: list[Card], broken_hearts: bool) -> Card:
        new_list = self.sortCard()
        self.hand = new_list

        for cardinCopy in new_list:
            if self.check_valid_play(cardinCopy, trick, broken_hearts)[0] == True:
                self.hand.remove(cardinCopy)
                return cardinCopy

    def pass_cards(self) -> str:
        new_list = self.sortCard()
        remove_num = len(new_list) - 3
        new_list2 = new_list[remove_num:]

        # res = ''
        # for card in new_list2:
        #     res += card.__str__() + '\n'
        #     self.hand.remove(card)
        return new_list2

    def sortCard(self) -> list:
        new_list = []
        CardsinHand = len(self.hand)
        copyhandList = self.hand.copy()
        passedCards = []

        while copyhandList:
            minCard = copyhandList[0]
            for cardi in copyhandList:
                # add another condition to compare the suit
                if cardi.__lt__(minCard) == True:
                    minCard = cardi

            new_list.append(minCard)
            copyhandList.remove(minCard)
        return new_list

    def check_valid_play(self, card: Card, trick: list[Card], broken_hearts: bool) -> tuple(bool, str):
        # player leading
        has_two_of_spade = False
        only_heart_suit = True
        if len(trick) == 0:
            for i in range(len(self.hand)):
                if self.hand[i].rank == Rank.Two and self.hand[i].suit == Suit.Clubs:
                    has_two_of_spade = True
                elif self.hand[i].suit != Suit.Hearts:
                    only_heart_suit = False
            if has_two_of_spade == True and card.rank != Rank.Two and card.suit != Suit.Clubs:
                return (False, "Player must lead with Two of Clubs")
            elif broken_hearts == False and not only_heart_suit:
                if card.suit == Suit.Hearts or (card.rank == Rank.Queen and card.suit == Suit.Spades):
                    return (False, "Player must not lead with Hearts when heart is not broken")
        # player not leading
        else:
            for i in self.hand:
                if i.suit == trick[0].suit and card.suit != trick[0].suit:
                    return (False, "Player still has cards from the suit of the current trick")

            if trick[0].rank == Rank.Two and trick[0].suit == Suit.Clubs and (
                    card.suit == Suit.Hearts or (card.rank == Rank.Queen and card.suit == Suit.Spades)):
                return (False, "Player cannot play Hearts or the Queen of Spades in first round")
        return (True, '')


players = [BasicAIPlayer("Player 1"), BasicAIPlayer(
    "Player 2"), BasicAIPlayer("Player 3"), BasicAIPlayer("Player 4")]


class Round:
    broken_hearts = False

    def __init__(self, players) -> None:
        self.players = players
        self.start_round()

    def check_other_than_spades(self, player_cards):
        flag = False
        values = []

        for card in player_cards:
            if card.suit == Suit.Spades and card.rank == Rank.Queen:
                values.append(1)
            elif card.suit == Suit.Hearts:
                values.append(1)
            else:
                values.append(0)

        if sum(values) == len(values):
            return False

        return True

    def start_round(self):

        round = 0
        round_order = []
        starting_player_index = 0
        """
        index in round order represent the order of players
        0 represents the first player, 1 represent the second player and....(the index of player in players)
        so, round_order = [2,3,0,1] means player 3 lead. then player 4 plays next and goes back to player 1, and end with player 2
        the loop below create a list according to the number of player, ex. [0,1,2,3,4] for 5 players
        """
        for i in range(len(self.players)):
            round_order.append(i)

        # check who hold two of Clubs
        if round == 0:
            for i in range(len(self.players)):
                for card in self.players[i].hand:
                    if card.rank == Rank.Two and card.suit == Suit.Clubs:
                        starting_player_index = i

        while len(self.players[0].hand) > 0:
            trick = []
            round_order = self.reorder_list(starting_player_index, round_order)
            for index in round_order:

                # addition start
                if len(self.players[index].hand) == 0:
                    return
                elif self.check_other_than_spades(self.players[index].hand) == False:
                    return
                # addition end

                card_played = self.players[index].play_card(
                    trick, self.broken_hearts)
                trick.append(card_played)
                player = self.players[index]

                print(f"{player} plays {card_played}")
                self.check_heart_broken(card_played)

            starting_player_index = self.check_highest_rank(trick)
            starting_player_index_in_round_order = round_order[starting_player_index]

            taker = self.players[starting_player_index_in_round_order].name
            penalty = self.cal_penalty_point(trick)
            self.players[starting_player_index_in_round_order].round_score += penalty

            print(f"{taker} takes the trick. Points received: {penalty}")
            round += 1

    def reorder_list(self, starting_index, round_order):
        """
        this will reorder round_order, for example, if the round is starting with player 2, it will rearrange the round_order from [0,1,2,3] to [1,2,3,0]
        """
        temp = round_order[:starting_index]
        for i in range(starting_index):
            round_order.pop(0)
        round_order = round_order + temp
        return round_order

    def check_highest_rank(self, trick):
        """ this method will check for the highest ranking card of leading suit in the trick and return the index of the card in the trick, representing the index of the player in that round (the index is the """
        current_suit = trick[0].suit
        max_in_current_suit = trick[0].rank.value
        max_index = 0

        for i in range(len(trick)):
            if trick[i].suit == current_suit and trick[i].rank.value > max_in_current_suit:
                max_in_current_suit = trick[i].rank.value
                max_index = i
        return max_index

    def cal_penalty_point(self, trick):
        """
        this method will calculate the penalty point of current completed trick and return it
        """
        point = 0
        for card in trick:
            if card.suit == Suit.Hearts:
                point += 1
            elif card.suit == Suit.Spades and card.rank == Rank.Queen:
                point += 13

        return point

    def check_heart_broken(self, card):
        """
        this method will check if player break the heart
        """
        if self.broken_hearts == False and card.suit == Suit.Hearts:
            self.broken_hearts = True
            print("Hearts have been broken!")

    def round_end_display(self):
        """
        this method display each player's score after the round ends
        """
        for player in self.players:
            player.total_score += player.round_score
            print(f"{player}'s total score: {player.total_score}")
            player.round_score = 0


class Hearts:

    # def __init__(self, score, no_players) -> None:
    #     self.target_score = score
    #     self.no_players = no_players
    #     self.players = []
    #     self.scores = []
    #     for i in range(self.no_players):
    #         self.scores.append(0)
    def __init__(self) -> None:
        self.target_score = 0
        self.no_players = 0
        self.players = []
        self.scores = []
        self.run_game()

    def create_dec(self):
        self.deck = [Card(rank, suit) for suit in Suit for rank in Rank]
        shuffle(self.deck)

    def create_players(self):
        self.players = []
        for i in range(1, self.no_players + 1):
            self.players.append(BasicAIPlayer("Player "+str(i)))
            self.players[i-1].total_score += self.scores[i-1]
            self.scores[i-1] = 0

    def assign_cards(self):
        deck = self.deck
        if self.no_players == 3:
            deck.remove(Card(Rank.Two, Suit.Diamonds))
        elif self.no_players == 5:
            deck.remove(Card(Rank.Two, Suit.Diamonds))
            deck.remove(Card(Rank.Two, Suit.Spades))

        inner = int(len(deck)/self.no_players)
        for i in range(self.no_players):
            for j in range(inner):
                index = rand.randint(0, len(deck)-1)
                self.players[i].hand.append(deck[index])
                deck.pop(index)

        for i in range(len(self.players)):
            print(f"Player {i+1} was dealt {self.players[i].hand}")

    def give_cards(self, player, to_add, to_remove):
        for i in range(3):
            player.hand.append(to_add[i])
            player.hand.remove(to_remove[i])

        return player

    def start_game(self):
        # passing cards
        if self.no_players == 3:
            pass_1 = self.players[0].pass_cards()
            pass_2 = self.players[1].pass_cards()
            pass_3 = self.players[2].pass_cards()
            self.players[1] = self.give_cards(self.players[1], pass_1, pass_2)
            self.players[2] = self.give_cards(self.players[2], pass_2, pass_3)
            self.players[0] = self.give_cards(self.players[0], pass_3, pass_1)

            print(f"Player {1} passed {pass_1} to Player {2}")
            print(f"Player {2} passed {pass_2} to Player {3}")
            print(f"Player {3} passed {pass_3} to Player {1}")

        elif self.no_players == 4:
            pass_1 = self.players[0].pass_cards()
            pass_2 = self.players[1].pass_cards()
            pass_3 = self.players[2].pass_cards()
            pass_4 = self.players[3].pass_cards()
            self.players[1] = self.give_cards(self.players[1], pass_1, pass_2)
            self.players[2] = self.give_cards(self.players[2], pass_2, pass_3)
            self.players[3] = self.give_cards(self.players[3], pass_3, pass_4)
            self.players[0] = self.give_cards(self.players[0], pass_4, pass_1)

            print(f"Player {1} passed {pass_1} to Player {2}")
            print(f"Player {2} passed {pass_2} to Player {3}")
            print(f"Player {3} passed {pass_3} to Player {4}")
            print(f"Player {4} passed {pass_4} to Player {1}")

        elif self.no_players == 5:
            pass_1 = self.players[0].pass_cards()
            pass_2 = self.players[1].pass_cards()
            pass_3 = self.players[2].pass_cards()
            pass_4 = self.players[3].pass_cards()
            pass_5 = self.players[4].pass_cards()
            self.players[1] = self.give_cards(self.players[1], pass_1, pass_2)
            self.players[2] = self.give_cards(self.players[2], pass_2, pass_3)
            self.players[3] = self.give_cards(self.players[3], pass_3, pass_4)
            self.players[4] = self.give_cards(self.players[4], pass_4, pass_5)
            self.players[0] = self.give_cards(self.players[0], pass_5, pass_1)

            print(f"Player {1} passed {pass_1} to Player {2}")
            print(f"Player {2} passed {pass_2} to Player {3}")
            print(f"Player {3} passed {pass_3} to Player {4}")
            print(f"Player {4} passed {pass_4} to Player {5}")
            print(f"Player {5} passed {pass_5} to Player {1}")

    def check_highest_with_total(self):
        highest = 0
        for player in self.players:
            if player.total_score > highest:
                highest = player.total_score
        if highest >= self.target_score:
            return True
        else:
            return False

    def save_scores(self, players):
        for i in range(self.no_players):
            self.scores[i] += players[i].total_score

    def check_winner(self, players):
        scores = [player.total_score for player in players]
        lowest = scores[0]
        index = 0
        for i in range(1, len(scores)):
            if scores[i] < lowest:
                lowest = scores[i]
                index = i
        return index + 1

    def run_game(self):

        target_score = input("Please enter a target score to end the game: ")
        while(not target_score.isdigit()):
            target_score = input(
                "Please enter a target score to end the game: ")
        self.target_score = int(target_score)

        # for number of players
        no_players = input("Enter number of players 3-5: ")
        while(no_players.strip().isdigit() == False):
            no_players = input("Please enter a number: ")
        no_players = int(no_players)
        while no_players < 3 or no_players > 5:
            no_players = input("Please enter between 3-5: ")
        self.no_players = int(no_players)

        for i in range(self.no_players):
            self.scores.append(0)

        i = 1
        while(self.check_highest_with_total() == False):
            print(f"========= Starting round {i} =========")
            self.create_dec()
            self.create_players()
            self.assign_cards()
            self.start_game()
            round = Round(self.players)
            print(f"========= End of round {i} =========")
            round.round_end_display()
            self.save_scores(round.players)
            i += 1

        print(f"Player {self.check_winner(self.players)} is the winner!")


if __name__ == "__main__":
    Hearts()
    # # for target score
    # target_score = input("Please enter a target score to end the game: ")
    # while(not target_score.isdigit()):
    #     target_score = input("Please enter a target score to end the game: ")
    # target_score = int(target_score)

    # # for number of players
    # no_players = input("Enter number of players 3-5: ")
    # while(no_players.strip().isdigit() == False):
    #     no_players = input("Please enter a number: ")
    # no_players = int(no_players)
    # while no_players < 3 or no_players > 5:
    #     no_players = input("Please enter between 3-5: ")
    # no_players = int(no_players)

    # # initialize object
    # hearts = Hearts(target_score, no_players)

    # i = 1
    # while(hearts.check_highest_with_total() == False):
    #     print(f"========= Starting round {i} =========")
    #     hearts.create_dec()
    #     hearts.create_players()
    #     hearts.assign_cards()
    #     hearts.start_game()
    #     round = Round(hearts.players)
    #     print(f"========= End of round {i} =========")
    #     round.round_end_display()
    #     hearts.save_scores(round.players)
    #     i += 1

    # print(f"Player {hearts.check_winner(round.players)} is the winner!")
