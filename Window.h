#ifndef WINDOW_H
#define WINDOW_H

class Window{
    public:
        Window();
        ~Window();
        void studentVisiting(int windowTime);
        void studentLeaving();
        bool m_isOpen;
};

#endif