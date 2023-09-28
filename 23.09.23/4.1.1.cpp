#include <iostream>

class Accessor;

class MyClass {
private:
    int privateValue;

    friend class Accessor; // Дружественный класс Accessor

public:
    MyClass() : privateValue(0) {}

    int getPrivateValue() const {
        return privateValue;
    }
};

class Accessor {
public:
    static void AccessPrivateValue(MyClass& obj) {
        obj.privateValue = 42; // Пример доступа к приватным членам
    }
};

int main() {
    MyClass obj;
    Accessor::AccessPrivateValue(obj);

    std::cout << "Accessed privateValue through Accessor: " << obj.getPrivateValue() << std::endl;

    return 0;
}
