#pragma once

#include "Card.hpp"

class Deck {
  private:
    Card cards[30];
    int cardCount;
  public:
    Deck();
    ~Deck() = default;
    Deck(const Deck&) = delete;
    Deck& operator=(const Deck&) = delete;

    void AddCard(const Card& card);

    int GetCardCount() const {
        return cardCount;
    }

    const Card& GetCard(int index);
};