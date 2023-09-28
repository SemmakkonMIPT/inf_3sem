#include <iostream>
#include <cmath>

const auto PI = 3.1415926535;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getRadius() const {
        return radius;
    }

    double getPerimeter() const {
        return 2 * PI * radius;
    }

    double getArea() const {
        return PI * radius * radius;
    }
};

class Triangle {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double getSide1() const {
        return side1;
    }

    double getSide2() const {
        return side2;
    }

    double getSide3() const {
        return side3;
    }

    double getPerimeter() const {
        return side1 + side2 + side3;
    }

    double getArea() const {
        double s = getPerimeter() / 2;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

class Square {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double getSide() const {
        return side;
    }

    double getPerimeter() const {
        return 4 * side;
    }

    double getArea() const {
        return side * side;
    }
};

int main() {
    // Примеры использования классов
    Circle circle(5.0);
    Triangle triangle(3.0, 4.0, 5.0);
    Square square(6.0);

    std::cout << "Circle:" << std::endl;
    std::cout << "Radius: " << circle.getRadius() << std::endl;
    std::cout << "Perimeter: " << circle.getPerimeter() << std::endl;
    std::cout << "Area: " << circle.getArea() << std::endl;

    std::cout << "\nTriangle:" << std::endl;
    std::cout << "Side 1: " << triangle.getSide1() << std::endl;
    std::cout << "Side 2: " << triangle.getSide2() << std::endl;
    std::cout << "Side 3: " << triangle.getSide3() << std::endl;
    std::cout << "Perimeter: " << triangle.getPerimeter() << std::endl;
    std::cout << "Area: " << triangle.getArea() << std::endl;

    std::cout << "\nSquare:" << std::endl;
    std::cout << "Side: " << square.getSide() << std::endl;
    std::cout << "Perimeter: " << square.getPerimeter() << std::endl;
    std::cout << "Area: " << square.getArea() << std::endl;

    return 0;
}
