#ifndef _H_TEXTFIELD
#define _H_TEXTFIELD_

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class TextField {
public:
    TextField();
    void setPosition(float _x, float y);
    void draw(sf::RenderWindow* window);
    void Update();
    string getText() { return text_str; };

private:
    float _x;
    float _y;
    sf::RectangleShape* rectangle;
    sf::Font font;
    sf::Text text;
    string text_str;
    float text_margin_x;
    float text_margin_y;
    bool write_once;

    void aux_write_text(string c);
};

#endif // _H_TEXTFIELD
