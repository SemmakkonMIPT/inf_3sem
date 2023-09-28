/*
Разработайте класс, представляющий некоторую физическую величину и предоставляющий интерфейс для
записи и чтения её значения в различных единицах измерения. Например, Вы можете разработать класс
для энергии, хранить ее значение в джоулях, и реализовать функции-члены для записи и чтения значения
с соответствующими преобразованиями в эргах и электрон-вольтах. Для хранения констант, используемых
функциями-членами, рекомендуется использовать статические константы с inline определениями.
*/

#include <iostream>

class Energy {
private:
    double joules; // Энергия в джоулях

public:
    Energy(double Joules) : joules(Joules) {}

    static inline const auto  electronCharge = 1.602176634e-19;

    double getJoules() const {
        return joules;
    }

    double getErgs() const {
        return joules * 1e7; // 1 джоуль = 1e7 эргов
    }

    double getElectronVolts() const {
        //inline static const auto electronCharge = 1.602176634e-19; // Заряд электрона в Кулонах
        return joules / electronCharge; // 1 электрон-вольт = 1 Кулон * 1 Вольт
    }

    void setJoules(double value) {
        joules = value;
    }

    void setErgs(double value) {
        joules = value / 1e7;
    }

    void setElectronVolts(double value) {
        //inline static const auto electronCharge = 1.602176634e-19; // Заряд электрона в Кулонах
        joules = value * electronCharge; // 1 электрон-вольт = 1 Кулон * 1 Вольт
    }
};

int main() {
    Energy energy(1000.0); // 1000 джоулей

    std::cout << "Energy in Joules: " << energy.getJoules() << std::endl;
    std::cout << "Energy in Ergs: " << energy.getErgs() << std::endl;
    std::cout << "Energy in Electron Volts: " << energy.getElectronVolts() << std::endl;

    energy.setElectronVolts(1.0); // Установить значение в 1 электрон-вольт
    std::cout << "\nEnergy in Joules: " << energy.getJoules() << std::endl;
    std::cout << "Energy in Ergs: " << energy.getErgs() << std::endl;
    std::cout << "Energy in Electron Volts: " << energy.getElectronVolts() << std::endl;

    return 0;
}