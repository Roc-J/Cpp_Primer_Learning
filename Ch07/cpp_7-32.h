#include<vector>
#include<string>

class Screen;

class Window_mgr {
    public:
        using ScreenIndex = std::vector<Screen>::size_type;

        void clear(ScreenIndex);
    private:
        std::vector<Screen> screens;   //这里不能够初始化
};

class Screen
{
    friend void Window_mgr::clear(ScreenIndex);
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd),contents(ht*wd, ' ') {}
    Screen(pos ht, pos wd, char c):height(ht), width(wd),contents(ht*wd, c) {}
    
    Screen &set(char);
    Screen &set(pos, pos, char);

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;  //显式内联函数

    Screen &move(pos r, pos c);

    Screen &display(std::ostream &os) 
                    { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const 
                    { do_display(os); return *this; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;    

    void do_display(std::ostream &os) const { os << contents; }
};

//友元函数定义 在class Screen后
inline void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r*width + c] = ch;
    return *this;
}

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row+c];
}