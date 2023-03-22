#include "Window.h"

Window::Window(){
    m_isOpen = true;
}

Window::~Window(){

}

// TO DO: mehtod that returns the wait time

void Window::studentVisiting(int windowTime){
    if (!m_isOpen){     // if window is closed
        // do something
    }
    m_isOpen = false;

}

void Window::studentLeaving(){
    m_isOpen = true;
}