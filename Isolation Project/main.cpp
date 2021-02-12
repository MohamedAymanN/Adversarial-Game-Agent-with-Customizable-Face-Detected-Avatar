#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<queue>
#include "Screen_Manager.h"
#include "AI_Winner_Screen.h"
using namespace std;


int main()
{

    //Initiating the game screen
    sf::RenderWindow window(sf::VideoMode(1200, 950), "Isolation Game");
    window.setPosition(sf::Vector2i(350, 0));
    window.setFramerateLimit(20);

    window.setKeyRepeatEnabled(false);

    //Adding the Game Icon
    sf::Image icon;
    icon.loadFromFile("Images/icon.png");
    window.setIcon(256,256,icon.getPixelsPtr());

    //Initiating the Screen_Manager
    Screen_Manager::GetInst().initiate();
    Screen_Manager::GetInst().LoadContent();

    //Playing the background music
    sf::Music m1;
    m1.openFromFile("Sounds/bgmusic.wav");
    m1.play();
    m1.setLoop(true);

    //Setting the buffer for the click sound
    sf::SoundBuffer buffer;
    buffer.loadFromFile("Sounds/click_effect1.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);


    //Game loop ; this is responsible for running the whole game
    while (window.isOpen())
    {
        //Event Queue; Responsible for queuing the events
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Closing Event
            if(event.type == sf::Event::Closed){
                m1.stop();
                window.close();
            //Mouse Clicking event
            }else if(event.type == sf::Event::MouseButtonPressed){
                sound.play();
            //Keyboard Pressing event
            }else if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::F9) {
                    Screen_Manager::GetInst().addscreen(new AI_Winner_Screen("","",1,1,""));
                }
            }


        }
        //Updating the current Screen and displaying its content
        window.clear();
        Screen_Manager::GetInst().Update(window,event);
        Screen_Manager::GetInst().Draw(window);
        window.display();
    }

    return 0;
}
