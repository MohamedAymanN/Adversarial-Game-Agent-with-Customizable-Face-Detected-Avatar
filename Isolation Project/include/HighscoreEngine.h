#ifndef HIGHSCOREENGINE_H
#define HIGHSCOREENGINE_H
#include <iostream>
#include<assert.h>
#include <bits/stdc++.h>
#include <fstream>

template<class T>
class Queue{
public:
    Queue();
    void enQueue(T e);
    T deQueue();
    T front();
    bool isEmpty();
private:
    struct Node;
    typedef Node * Link;
    struct Node{
        T data;
        Link next;
    };
    Link f;
    Link r;
};
template<class T>
Queue<T>::Queue(){
    f=0;
    r=0;
}

template<class T>
void Queue<T>::enQueue(T e){
    Link n=new Node;
    assert(n);
    n->next = 0;
    n->data = e;
    if(f!=0){
        r->next = n;
        r = n;
    }
    else{
        f=n;
        r=n;
    }
}
template<class T>
T Queue<T>::deQueue(){
    assert(f);
    Link n=f;
    T frontElement=f->data;
    f=f->next;
    delete n;
    if(f==0)
        r=0;
    return frontElement;
}

template<class T>
T Queue<T>::front(){
    assert(f);
    return f->data;
}

template<class T>
bool Queue<T>::isEmpty(){
    return (f==0);
}


struct pScore{
    std::string name;
    int score;
};



class HighscoreEngine
{
    public:
        HighscoreEngine();
        ~HighscoreEngine();
        int writeFile(std::string name,int score);

    protected:

    private:
};

#endif // HIGHSCOREENGINE_H
