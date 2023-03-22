#include "Office.h"

Office::Office(){
    m_officeType = "";
    m_openWindows = 0;
}

Office::Office(std::string officeType, int windows){
    m_officeType = officeType;
    m_openWindows = windows;
    m_windows = new Window[m_openWindows];      // array of windows 
    for (int i = 0; i < m_openWindows; ++i){
        m_windows[i] = Window();
    }
}

Office::~Office(){
    delete[] m_windows;
}

// TO DO: make method calculateMeanWaitTime() maybe