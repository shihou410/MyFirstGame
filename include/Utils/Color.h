#pragma once

class Color {
   public:
    Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a){};

    int r, g, b, a;

    static Color RED;
    static Color BLUE;
    static Color BLOCK;
    static Color WHITE;
    static Color YELLOW;
    static Color GREEN;
};
