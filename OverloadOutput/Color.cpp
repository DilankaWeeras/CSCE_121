#include <iostream>
#include "Color.h"

using namespace std;

void Color::printColor() {
    cout << "rgb(" << red << "," << green << "," << blue << ")";
}

Color::Color() : red(255), green(255), blue(255) {}

Color::Color(int red, int green, int blue) :
    red(red), green(green), blue(blue) {}

Color operator+(const Color& lhs, const Color& rhs) {
    Color c;
    c.set_red((lhs.get_red() + rhs.get_red())/2);
    c.set_green((lhs.get_green() + rhs.get_green())/2);
    c.set_blue((lhs.get_blue() + rhs.get_blue())/2);
    return c;
}

Color& Color::operator+=(const Color& rhs) {
    this->red = (this->red + rhs.red)/2;
    this->green = (this->green + rhs.green)/2;
    this->blue = (this->blue + rhs.blue)/2;
    return *this;
}

// Add overloaded output operator definition (which is also a declaration) here
std::ostream& operator<<(std::ostream& os, const Color& c)
{
	os << "rgb(" << c.get_red() << "," << c.get_green() << "," << c.get_blue() << ")";
	return os;
}



