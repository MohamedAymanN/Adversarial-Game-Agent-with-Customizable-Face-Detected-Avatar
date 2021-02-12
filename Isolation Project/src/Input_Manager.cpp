#include "Input_Manager.h"
#include<iostream>
/*
    responsible for managing every mouse and kevboard events.
*/
Input_Manager::Input_Manager(){}

Input_Manager::~Input_Manager(){}

void Input_Manager::Update(sf::RenderWindow &window,sf::Event event){
    ev=event;
}

bool Input_Manager::key_pressed(sf::Keyboard::Key key){
    return sf::Keyboard::isKeyPressed(key);
}

bool Input_Manager::mouse_left_clicked(){
    if(ev.type==sf::Event::MouseButtonPressed && ev.mouseButton.button==sf::Mouse::Left){
        return true;
    }
    return false;
}

bool Input_Manager::mouse_left_release(){
    if(ev.type==sf::Event::MouseButtonReleased && ev.mouseButton.button==sf::Mouse::Left){
        return true;
    }
    return false;
}
