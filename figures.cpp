#include <iostream>
#include <cmath>
#include <random>
#include <vector>

using namespace std;

class Shape {
    public:
        Shape() {}
    

    void generateRandomPos() {
        vector<int> result;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> screen(0, 512);

        int x = screen(gen);
        int y = screen(gen);
        result.push_back(x);
        result.push_back(y);

        coords.push_back(result);
    }

    void printCoords (){
        for (int i = 0; i < coords.size(); i++){
            cout << "X: " << coords[i][0] << endl;
            cout << "Y: " << coords[i][1] << endl;
        }
    }

    protected:
        vector<vector<int>> coords;

};

class Circle : public Shape {
    public:
        Circle () {
            generateRandomPos();
            generateRadius();
        };

        void printInfo() {
            printCoords();
            cout << "Radius: " <<  radius << endl;
        }

    private:
        void generateRadius() {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> radSize(5, 100);

            radius = radSize(gen);
        }

        int radius{0};
};




class Line : public Shape {

    public:
        Line() {
            generateRandomPos();
            generateRandomPos();
            getLength();
        }

        void getLength() {
            length = sqrt(pow(coords[0][1]-coords[0][0], 2) + pow(coords[1][1]-coords[1][0], 2));
        }

        void printInfo() {
            printCoords();
            cout << "Line length: "<< length << endl;
        }

    private:
        int length{0};
};

class Rectangle : public Shape {
    public:
        Rectangle() {
            generateRandomPos();
        }

        void inpKeyboard() {
            
        }

        void inpRand() {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> radSize(0, 100);

            width = radSize(gen);
            heigth = radSize(gen);

        }

        void areaCalc() {
            area = width * heigth;
        }

        void perimeterCalc() {
            perimeter = width*2 + heigth*2;
        }

        void printInfo(){
            printCoords();
            cout << "Width: " << width << endl;
            cout << "Height: " << heigth << endl;
            cout << "Perimeter: " << perimeter << endl;
            cout << "Area: " << area << endl;
        }



    protected: 
        int width{0};
        int heigth{0};
        int area;
        int perimeter{0};

};

class Square : public Rectangle{
    public:
        Square() {}

        void inpRand() {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> radSize(10, 100);

            width = radSize(gen);
            heigth = width;
        }
};




int main() {
    cout << "Shape" << endl;
    Shape test;
    test.generateRandomPos();
    test.printCoords();


    cout << "Circle" << endl;
    Circle circle;
    circle.printInfo();

    cout << "Line" << endl;
    Line line;
    line.printInfo();

    cout << "Rectangle" << endl;
    Rectangle rectangle;
    rectangle.inpRand();
    rectangle.areaCalc();
    rectangle.perimeterCalc();
    rectangle.printInfo();

    cout << "Square" << endl;
    Square square;
    square.inpRand();
    square.areaCalc();
    square.perimeterCalc();
    square.printInfo();

}