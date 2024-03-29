#include <iostream>
#include <algorithm>
#include <random>

#include "../Header/GameText.h"
#include "../Header/Game.h"
#include "../Header/Card.h"
#include "../Header/CardTypes/DumplingCard.h"
#include "../Header/CardTypes/MakiCard.h"
#include "../Header/CardTypes/NigiriCard.h"
#include "../Header/CardTypes/SashimiCard.h"
#include "../Header/CardTypes/TempuraCard.h"

Game::~Game()
{
	for (Player* player : _players) {
		delete player; player = nullptr;
	}

	for (Card* card : _gameDeck) {
		delete card; card = nullptr;
	}
}

void Game::initGame() {
	std::cout << TITLE_TEXT << std::endl;
	initPlayers();
	createDeck();
	shuffleDeck();
}

void Game::initPlayers()
{
	for (int i = 0; i < 2; ++i) {
		_players.emplace_back(new Player());
	}
}

void Game::createDeck()
{
	for (int i = 0; i < 14; ++i) {
		_gameDeck.emplace_back(new TempuraCard());
		_gameDeck.emplace_back(new SashimiCard());
		_gameDeck.emplace_back(new DumplingCard());
	}

	for (int i = 0; i < 12; ++i) {
		_gameDeck.emplace_back(new MakiCard(2));
	}

	for (int i = 0; i < 10; ++i) {
		_gameDeck.emplace_back(new NigiriCard(Salmon));
	}

	for (int i = 0; i < 8; ++i) {
		_gameDeck.emplace_back(new MakiCard(3));
	}

	for (int i = 0; i < 6; ++i) {
		_gameDeck.emplace_back(new MakiCard(1));
	}

	for (int i = 0; i < 5; ++i) {
		_gameDeck.emplace_back(new NigiriCard(Egg));
		_gameDeck.emplace_back(new NigiriCard(Squid));
	}
}

void Game::shuffleDeck()
{
	shuffle(_gameDeck.begin(), _gameDeck.end(), std::default_random_engine(std::random_device()()));
}

void Game::populateHands()
{
	for (Player* player : _players) {
		for (int i = 0; i < 10; ++i) {
			player->addCardToHand(_gameDeck.at(i));
			_gameDeck.erase(_gameDeck.begin() + i);
		}
	}
}

void Game::displayHand(Player* player)
{
	std::cout << "Current hand:" << std::endl;
	int cardNo = 1;
	for (Card* card : player->getHand()) {
		std::cout << std::to_string(cardNo) + ". " + card->str() << std::endl;
		cardNo++;
	}
}

/**
 * @brief Swaps the players hands
 *
 * This method swaps the hands of the players
 *
 * @details Assumptions:
 * 1. This method assumes that there are only 2 players
 */
void Game::swapHands()
{
	std::vector<Card*> temp = _players[0]->getHand();
	_players[0]->setHand(_players[1]->getHand());
	_players[1]->setHand(temp);
}

/**
 * @brief Gets input from the user
 *
 * This method is used to input from the user
 * The method handles any errors, and incorrect user input
 *
 * @params handSize, used to check if the user input is out of the allowed range
 *
 * @return input, returns the user input
 *
 * @notes
 * 1. usage of clear and ignore are to remove any left of invalid characters from the input stream
 */
int Game::getUserInput(int handSize)
{
	int input;
	std::cout << "Select a card to add to your tableau:" << std::endl;
	while (!(std::cin >> input) || input < 1 || input > handSize) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input < 1 || input > handSize) {
			std::cout << "Invalid input. Please enter a valid card number: ";
		}
		else {
			std::cout << "Invalid input. Please enter an integer: ";
		}
	}
	return input;
}

void Game::playTurn()
{
	bool validTurn = true;
	while (validTurn) {
		for (Player* player : _players) {
			if (player->getHand().empty()) {
				//if the player's hand it empty they cannot play a turn, therefore exit the while loop
				validTurn = false;
			}
			else {
				_currentPlayer = player;
				std::cout << "PLAYER " + player->getName() + " TURN" << std::endl;
				player->printTableau();
				displayHand(player);
				int userInput = getUserInput(10);
				player->addCardToTableau(player->getHand().at(userInput - 1));
			}
		}
	}
}

void Game::getRoundScore() {
	std::cout << "~~~ End of round scoring ~~~" << std::endl;
	for (Player* player : _players) {
		Player* otherPlayer = (player == _players[0]) ? _players[1] : _players[0];
		std::cout << player->getName() << "'s score is " << player->calculateRoundScore(otherPlayer->getTableau()) << std::endl;
	}
}

void Game::getTotalScore()
{

	//finds the element of the _players vector which has the highest total score
	auto winner = std::max_element(_players.begin(), _players.end(),
		[](const auto& player1, const auto& player2) {
			//compare two players total score and return the higher of the two
			return player1->getTotalScore() < player2->getTotalScore();
		}
	);

	std::cout << "~~~ End of game! ~~~" << std::endl;
	for (Player* player : _players) {
		std::cout << "  PLAYER " << player->getName() << " final score: " << player->getTotalScore() << std::endl;
	}
	//dereference the iterator of winner
	std::cout << "PLAYER " << (*winner)->getName() << " WINS!" << std::endl;
}

void Game::play()
{
	initGame();
	while (_currentRound != _maxRounds) {
		for (Player* player : _players) {
			player->clearTableau();
		}
		populateHands();
		std::cout << "~~~ Round " + std::to_string(_currentRound + 1) + "/3 ~~~" << std::endl;
		playTurn();
		getRoundScore();
		_currentRound++;
	}
	getTotalScore();
}