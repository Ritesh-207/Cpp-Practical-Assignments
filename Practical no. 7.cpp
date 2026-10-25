
#include <iostream>
#include <iomanip>
using namespace std;

// Compile-time polymorphism: Function overloading
double area(double side) {
    return side * side;  // Square
}

double area(double length, double breadth) {
    return length * breadth;  // Rectangle
}

double area(double radius, char type) {
    const double PI = 3.14159;
    return PI * radius * radius;  // Circle
}

// Base class
class Shape {
public:
    virtual double calculateArea() {
        return 0;
    }

    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double calculateArea() {
        return area(radius, 'C');
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
    double length, breadth;

public:
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    double calculateArea() {
        return area(length, breadth);
    }
};

// Derived class: Triangle
class Triangle : public Shape {
    double base, height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double calculateArea() {
        return 0.5 * base * height;
    }
};

int main() {
    int choice;
    double x, y;

    cout << fixed << setprecision(2);
    cout << "=== SHAPE AREA CALCULATOR ===\n";
    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "4. Square \n";
    cout << "Enter your choice: ";
    cin >> choice;

    Shape* shape = NULL;

    switch (choice) {
    case 1:
        cout << "Enter radius: ";
        cin >> x;

        if (x <= 0) {
            cout << "Dimensions must be positive.\n";
            return 0;
        }

        shape = new Circle(x);
        break;

    case 2:
        cout << "Enter length and breadth: ";
        cin >> x >> y;

        if (x <= 0 || y <= 0) {
            cout << "Dimensions must be positive.\n";
            return 0;
        }

        shape = new Rectangle(x, y);
        break;

    case 3:
        cout << "Enter base and height: ";
        cin >> x >> y;

        if (x <= 0 || y <= 0) {
            cout << "Dimensions must be positive.\n";
            return 0;
        }

        shape = new Triangle(x, y);
        break;

    case 4:
        cout << "Enter side of square: ";
        cin >> x;

        if (x <= 0) {
            cout << "Dimension must be positive.\n";
            return 0;
        }

        cout << "Area of Square: " << area(x) << endl;
        return 0;

    default:
        cout << "Invalid choice.\n";
        return 0;
    }

    // Runtime polymorphism
    cout << "Area: " << shape->calculateArea() << endl;

    delete shape;

    return 0;
}

