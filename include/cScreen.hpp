#ifndef CSCREENS_HPP_INCLUDED
#define CSCREENS_HPP_INCLUDED

class cScreen
{
public :
    virtual int Run (sf::RenderWindow &App, sf::Music& music) = 0;
};

#endif // SCREENS_HPP_INCLUDED
