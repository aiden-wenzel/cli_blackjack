#include <string>
#include <fstream>
#include <random>
#include <vector>
#include "deck.hpp"

Deck::Deck(std::ifstream &suits_input, std::ifstream &ranks_input) {
    std::vector<std::string> suits;
    std::vector<std::string> ranks;

    // load in suits
    std::string suit_temp;
    while (suits_input >> suit_temp) {
        suits.push_back(suit_temp);
    }

    // load in ranks
    std::string rank_temp;
    while (ranks_input >> rank_temp) {
        ranks.push_back(rank_temp);
    }

    for (int i = 0; i < suits.size(); i++) {
        for (int j = 0; j < ranks.size(); j++) {
            Card card_temp(ranks[j], suits[i]);
            this->cards.push_back(card_temp);
        }
    }
    this->num_cards = this->cards.size();
}

Card Deck::get_card(int index) {
    return this->cards[index];
}

int Deck::get_num_cards() {
    return this->num_cards;
}

void Deck::shuffle_deck(int num_swaps) {
    for (int i = 0; i < num_swaps; i++) {
        int random_index_1 = std::rand() % this->num_cards;
        int random_index_2 = std::rand() % this->num_cards;
        std::swap(this->cards[random_index_1], this->cards[random_index_2]);
    }
}