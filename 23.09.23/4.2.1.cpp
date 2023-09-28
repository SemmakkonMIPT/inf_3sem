#include <iostream>

class Passkey;

class MyClass {
private:
    int privateData;

public:
    MyClass() : privateData(0) {}

    int getPrivateData() const {
        return privateData;
    }

    friend class Passkey;
};

class Passkey {
public:
    static void AccessPrivateData(MyClass& obj) {
        obj.privateData = 42;
    }
};

int main() {
    MyClass obj;
    Passkey::AccessPrivateData(obj);

    std::cout << "Accessed privateData through Passkey: " << obj.getPrivateData() << std::endl;

    return 0;
}

/*
При сравнении паттерна "Адвокат" и идиомы "Passkey", можно сказать, что оба подхода
предоставляют ограниченный доступ к приватным членам класса без необходимости делать
другой класс другом. Однако "Passkey" может быть более гибким в случае, если нужно
предоставить доступ только определенным частям кода, а не целому классу Attorney. При
этом "Passkey" требует создания дополнительной структуры-ключа и шаблонных параметров.

Выбор между этими подходами зависит от конкретных потребностей и структуры вашего проекта.*/