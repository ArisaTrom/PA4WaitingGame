#ifndef OFFICE_H
#define OFFICE_H
#include "Window.h"
#include <string>

class Office{
    public:
        Office();
        Office(std::string officeType, int windowNum);
        ~Office();
    private:
        int m_openWindows;
        std::string m_officeType;
        Window* m_windows;

};

#endif