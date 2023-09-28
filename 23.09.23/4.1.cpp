/*
Использование модификатора доступа friend делает все компоненты класса доступными для дружественной
сущности, даже если ей нужны только некоторые из них, что приводит к ухудшению инкапсуляции и поэтому
обычно считается сомнительной практикой. Непосредственная возможность дать доступ только к одной части
членов класса для одних пользователей, к другой - для других, а к третьей - третьим отсутствует. Существуют
идиома Attorney-Client и паттерн Passkey, которые обеспечивают ограниченный доступ для друзей класса. Они
основаны на дополнительном посреднике между исходным классом и другом. Реализуйте указанные идиому
и паттерн и сравните их с точки зрения удобства использования. Можете воспользоваться StackOverflow.
*/

#include <iostream>

class Attorney;

class MyClass {
private:
    int privateData;

    friend class Attorney; // Дружественный класс Attorney

public:
    MyClass() : privateData(0) {}

    int getPrivateData() const {
        return privateData;
    }
};

class Attorney {
public:
    static void AccessPrivateData(MyClass& obj) {
        obj.privateData = 42; // Пример доступа к приватным членам
    }
};

int main() {
    MyClass obj;
    Attorney::AccessPrivateData(obj);

    std::cout << "Accessed privateData through Attorney: " << obj.getPrivateData() << std::endl;

    return 0;
}
