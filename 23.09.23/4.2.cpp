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

class MyClass;

struct Passkey {
    friend class MyClass;
    private:
};

class MyClass {
private:
    int privateData;

public:
    MyClass() : privateData(0) {}

    int getPrivateData(const Passkey&) const {
        return privateData;
    }

    void setPrivateData(const Passkey&, int value) {
        privateData = value;
    }
};

int main() {
    MyClass obj;
    Passkey key;

    obj.setPrivateData(key, 42);
    std::cout << "Accessed privateData through Passkey: " << obj.getPrivateData(key) << std::endl;

    return 0;
}

/*
Сравнение:
Идиома "Attorney-Client" и паттерн "Passkey" оба обеспечивают ограниченный доступ к приватным членам класса.
Однако паттерн "Passkey" предоставляет более явный способ передачи ключа доступа, что может быть более
безопасным и читаемым.

Оба подхода имеют свои преимущества, и выбор между ними зависит от конкретных требований и структуры вашего проекта.*/
