#include <iostream>
#include <cmath>

const auto PI = 3.1415926535;

class Shape {
protected:
    double dimension1;
    double dimension2;
    double dimension3;

public:
    Shape(double dim1, double dim2 = 0.0, double dim3 = 0.0)
        : dimension1(dim1), dimension2(dim2), dimension3(dim3) {}

    double getDimension1() const {
        return dimension1;
    }

    double getDimension2() const {
        return dimension2;
    }

    double getDimension3() const {
        return dimension3;
    }

    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;
};

class Circle : public Shape {
public:
    Circle(double radius) : Shape(radius) {}

    double getPerimeter() const override {
        return 2 * PI * dimension1;
    }

    double getArea() const override {
        return PI * dimension1 * dimension1;
    }
};

class Triangle : public Shape {
public:
    Triangle(double side1, double side2, double side3)
        : Shape(side1, side2, side3) {}

    double getPerimeter() const override {
        return dimension1 + dimension2 + dimension3;
    }

    double getArea() const override {
        double s = getPerimeter() / 2;
        return std::sqrt(s * (s - dimension1) * (s - dimension2) * (s - dimension3));
    }
};

class Square : public Shape {
public:
    Square(double side) : Shape(side) {}

    double getPerimeter() const override {
        return 4 * dimension1;
    }

    double getArea() const override {
        return dimension1 * dimension1;
    }
};

int main() {
    // Примеры использования классов
    Circle circle(5.0);
    Triangle triangle(3.0, 4.0, 5.0);
    Square square(6.0);

    std::cout << "Circle:" << std::endl;
    std::cout << "Radius: " << circle.getDimension1() << std::endl;
    std::cout << "Perimeter: " << circle.getPerimeter() << std::endl;
    std::cout << "Area: " << circle.getArea() << std::endl;

    std::cout << "\nTriangle:" << std::endl;
    std::cout << "Side 1: " << triangle.getDimension1() << std::endl;
    std::cout << "Side 2: " << triangle.getDimension2() << std::endl;
    std::cout << "Side 3: " << triangle.getDimension3() << std::endl;
    std::cout << "Perimeter: " << triangle.getPerimeter() << std::endl;
    std::cout << "Area: " << triangle.getArea() << std::endl;

    std::cout << "\nSquare:" << std::endl;
    std::cout << "Side: " << square.getDimension1() << std::endl;
    std::cout << "Perimeter: " << square.getPerimeter() << std::endl;
    std::cout << "Area: " << square.getArea() << std::endl;

    return 0;
}
