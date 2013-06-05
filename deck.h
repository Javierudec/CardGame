#ifndef _DECK_H_
#define _DECK_H_

#include <SFML/Graphics.hpp>
#include "Card.h"
#include "infomanager.h"
#include "Field.h"

class Deck {
public:
    Deck();
    void Render(sf::RenderWindow* window);
    void SetPosition(float x, float y);
    void SetMargin(float m_x, float m_y);
    void Update();
    void RenderAllCardsOnDeck(sf::RenderWindow* window);
    void SetManager(manager* man);
    void SetWindow(sf::RenderWindow* window) { this->window = window; };
    void SetField(Field* field) { this->field = field; };
    void LoadDeck();
    void Shuffle();
    bool CardIsSelected() { return (bViewing == true) ? bSelected : false; };
    Card GetSelectedCard() { return lastCardClicked; };
    void View() { bViewing = true; };
    void Close() { bViewing = false; };

private:
    sf::Texture       back_card_texture;
    sf::Sprite        back_card_sprite;
    float _x;
    float _y;
    float margin_x;
    float margin_y;
    int num_cards;
    Card card[50];
    float pos_x_list;
    float pos_y_list;
    manager* man;
    sf::RenderWindow* window;
    Field* field;
    Card lastCardClicked;
    bool bSelected;
    bool bViewing;
};

#endif // _DECK_H_
