#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include <vector>
#include <SFML/Graphics.hpp>

class Input_Manager
{
    public:
        Input_Manager();
        ~Input_Manager();

        void Update(sf::RenderWindow &window,sf::Event event);
        bool key_pressed(sf::Keyboard::Key key);
        bool mouse_left_clicked();
        bool mouse_left_release();

        //bool key_pressed(vector<int> v1);


    protected:

    private:
        sf::Event ev;
};

#endif // INPUT_MANAGER_H
