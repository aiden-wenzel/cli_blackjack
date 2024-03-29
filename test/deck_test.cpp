#include <gtest.h>
#include <cassert>
#include <fstream>
#include "deck.hpp"
#include "card.hpp"

TEST(deck, deck_constructor) {
    std::ifstream suits("../black_jack/suits.in");
    std::ifstream ranks("../black_jack/ranks.in");

    Deck deck(suits, ranks);
    deck.shuffle_deck(100);
    ASSERT_EQ(deck.get_num_cards(), 52);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}