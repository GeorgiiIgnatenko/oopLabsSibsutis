#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Shape {
    public:
        Shape() {}
        Shape(int x, int y) {
            this->coords[0][0] = x;
            this->coords[0][1] = y;
        }

    private:
        vector<vector<int>> coords;

};

class Circle : Shape {
    private:
        int radius{0};
};


class Line : Shape {

    public:
        Line(int x1, int y1, int x2, int y2) {
            this->coords[0][0] = x1;
            this->coords[0][1] = y1;
            this->coords[1][0] = x2;
            this->coords[1][1] = y2;
        };

        void getLength() {
            length = sqrt(pow(coords[0][1]-coords[0][0], 2) + pow(coords[1][1]-coords[1][0], 2));
        }

        void print() {
            cout << length << endl;
        }

    private:
        vector<vector<int>> coords;
        int length{0};
};

class Square : Line {
    public:

        void inpKeyboard() {

        }

        void inpRand() {

        }

        void area() {
        }

    private:
        int m_x1{0};
        int m_y1{0};
        int m_x2{0};
        int m_y2{0};
        int m_x3{0};
        int m_y3{0};
        int m_x4{0};
        int m_y4{0};
};

// class Rectangle : Square {

// };




int main() {
    Line l(1,2,1,4);
    l.getLength();
    l.print();
}