#include "deck.h"

bool shuffle_sort(Card c1, Card c2)
{
    int num = rand() % 2;
    if(num == 0) return true;
    else return false;
}

Deck::Deck()
{
    back_card_texture.loadFromFile("data/cards/back.jpg");
    back_card_sprite.setTexture(back_card_texture);
    back_card_sprite.scale(0.34f, 0.34f);

    pos_x_list = 365;
    pos_y_list = 100;

    bSelected = false;
    bViewing = false;
}

void Deck::Render(sf::RenderWindow* window)
{
    if(bViewing) {
        RenderAllCardsOnDeck(window);
    }

    for(int i = 0; i < num_cards; i++)
    {
        back_card_sprite.setPosition(_x + margin_x * i, _y + margin_y * i);
        window->draw(back_card_sprite);
    }
}

void Deck::SetPosition(float x, float y)
{
    _x = x;
    _y = y;
    back_card_sprite.setPosition(_x, _y);
}

void Deck::Shuffle()
{
    /*
    srand(time(NULL));
    sort(card, card + num_cards, shuffle_sort);
    */
    srand(time(NULL));
    for(int i = 0; i < num_cards; i++)
    {
        int id = card[i].getID();
        int newpos = rand() % num_cards;
        card[i].SetCard(card[newpos].getID());
        card[newpos].SetCard(id);
    }

}

void Deck::SetMargin(float m_x, float m_y)
{
    margin_x = m_x;
    margin_y = m_y;
}

void Deck::Update()
{
    /*
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        num_cards--;
    }
    */
    if(bViewing) {
        for(int i = 0; i < 6; i++)
        {
            if(card[i].Update()) {
                lastCardClicked = card[i];
                bSelected = true;
            }
        }
    }
}

void Deck::RenderAllCardsOnDeck(sf::RenderWindow* window)
{
    for(int i = 0; i < 6; i++)
    {
        card[i].setPosition(pos_x_list + i * 100, pos_y_list);
        window->draw(card[i].getSprite());
    }
}

void Deck::SetManager(manager* man)
{
    this->man = man;
}

void Deck::LoadDeck()
{
    num_cards = 50;
    card[0].SetCard(2);
    card[1].SetCard(2);
    card[2].SetCard(2);
    card[3].SetCard(2);
    card[4].SetCard(9);
    card[5].SetCard(14);
    card[6].SetCard(7);
    card[7].SetCard(8);
    card[8].SetCard(3);
    card[9].SetCard(6);
    card[10].SetCard(9);
    card[11].SetCard(15);
    card[12].SetCard(10);
    card[13].SetCard(14);
    card[14].SetCard(12);
    card[15].SetCard(7);
    card[16].SetCard(9);
    card[17].SetCard(17);
    card[18].SetCard(11);
    card[19].SetCard(10);
    card[20].SetCard(16);
    card[21].SetCard(8);
    card[22].SetCard(11);
    card[23].SetCard(12);
    card[24].SetCard(11);
    card[25].SetCard(12);
    card[26].SetCard(5);
    card[27].SetCard(5);
    card[28].SetCard(5);
    card[29].SetCard(5);
    card[30].SetCard(4);
    card[31].SetCard(4);
    card[32].SetCard(13);
    card[33].SetCard(15);
    card[34].SetCard(15);
    card[35].SetCard(15);
    card[36].SetCard(17);
    card[37].SetCard(17);
    card[38].SetCard(17);
    card[39].SetCard(8);
    card[40].SetCard(8);
    card[41].SetCard(12);
    card[42].SetCard(11);
    card[43].SetCard(14);
    card[44].SetCard(14);
    card[45].SetCard(9);
    card[46].SetCard(16);
    card[47].SetCard(16);
    card[48].SetCard(16);
    card[49].SetCard(7);
    for(int i = 0; i < num_cards; i++)
    {
        card[i].SetInfoManager(man);
        card[i].SetWindow(window);
    }
}
