#include "Office.h"

Office::Office(){
    m_officeType = ' ';
    m_openWindows = 0;
    m_officeQueue = new ListQueue<Customer*>();
}

Office::Office(char officeType, int windows){
    m_officeType = officeType;
    m_openWindows = windows;
    m_officeQueue = new ListQueue<Customer*>();
    m_windows = new Window*[m_openWindows];      // array of windows 
    for (int i = 0; i < m_openWindows; ++i){
        m_windows[i] = new Window();
    }
}

Office::~Office(){
    delete[] m_windows;
}

// TO DO: make method calculateMeanWaitTime() maybe
