#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

enum class COLOR {
    RED,
    GREEN,
    BLUE,
    BLACK,
    GRAY,
    WHITE,
    YELLOW,
    ORANGE,
};

string getColor(COLOR color) {
    switch (color) {
    case COLOR::RED:
        return "RED";
    case COLOR::GREEN:
        return "GREEN";
    case COLOR::BLUE:
        return "BLUE";
    case COLOR::BLACK:
        return "BLACK";
    case COLOR::GRAY:
        return "GRAY";
    case COLOR::WHITE:
        return "WHITE";
    case COLOR::YELLOW:
        return "YELLOW";
    case COLOR::ORANGE:
        return "ORANGE";
    }
}

enum class DESTINATION {
    LIGHT_DRESS,
    DENSE_DRESS,
    SUIT
};

string get_destination(DESTINATION destination) {
    switch (destination) {
    case DESTINATION::LIGHT_DRESS:
        return "LIGHT_DRESS";
    case DESTINATION::DENSE_DRESS:
        return "DENSE_DRESS";
    case DESTINATION::SUIT:
        return "SUIT";
    }
}

class Linen_fabric {
    DESTINATION destination;
    unsigned int density;
    unsigned int length;
    unsigned int width;
    COLOR color;
public:
    Linen_fabric(DESTINATION destination, unsigned int density, COLOR color, unsigned int length,unsigned int width ) :
       density(density), destination(destination),
       length(length),
       width(width), color(color){
    }


    string getDescription() {
        return get_destination(destination) + " " + to_string(density )+ " "  + getColor(color) + " " + to_string(length) + ", " + to_string(width);
    }

    static Linen_fabric* light_dress() {
        return new Linen_fabric(DESTINATION::LIGHT_DRESS,100, COLOR::ORANGE, 3000, 100);
    }

    static Linen_fabric* dense_dress() {
        return new Linen_fabric(DESTINATION::DENSE_DRESS,150, COLOR::BLACK, 3500, 300);
    }

    static Linen_fabric* fabric_for_suit(COLOR color = COLOR::GRAY) {
        return new Linen_fabric(DESTINATION::SUIT,250, color, 2000, 200);
    }
};

int main() {
    vector<Linen_fabric*> fabrics1, fabrics2;

    fabrics1.push_back(Linen_fabric::light_dress());

    for (int i = 0; i < 5; i++) {
        fabrics1.push_back(Linen_fabric::fabric_for_suit(COLOR::ORANGE));
    }

    cout << "Order 1: " << endl;
    for (int i = 0, len = fabrics1.size(); i < len; i++) {
        std::cout << fabrics1[i]->getDescription() << endl;
    }

    for (int i = 0; i < 5; i++) {
        fabrics2.push_back(Linen_fabric::dense_dress());
    }

    cout << "Order 2: " << endl;
    for (int i = 0, len = fabrics2.size(); i < len; i++) {
        std::cout << fabrics2[i]->getDescription() << endl;
    }

    return 0;
}