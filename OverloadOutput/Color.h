#ifndef COLOR_H
#define COLOR_H
#include <ostream>;

class Color {
    int red;
    int green;
    int blue;
public:
    Color(); // default constructor
    Color(int red, int green, int blue); // parameterized constructor
    Color& operator+=(const Color& rhs); // lhs is this pointer
    int get_red(void) const { return red; }
    int get_green(void) const { return green; }
    int get_blue(void) const { return blue; }
    void set_red(int red) { this->red = red; }
    void set_green(int green) { this->green = green; }
    void set_blue(int blue) { this->blue = blue; }
	void printColor();
};

Color operator+(const Color& lhs, const Color& rhs);
// Add overloaded output operator declaration here

std::ostream& operator<<(std::ostream& os, const Color& c);


#endif  /* COLOR */