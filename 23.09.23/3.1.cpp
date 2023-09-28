#include <iostream>

class Energy {
private:
    double joules;

public:
    Energy(double Joules) : joules(Joules) {}

    static inline const auto electronCharge = 1.602176634e-19;

    double getJoules() const {
        return joules;
    }

    double getErgs() const {
        return joules * 1e7; // 1 joule = 1e7 ergs
    }

    double getElectronVolts() const {
        return joules / electronCharge; // 1 electron-volt = 1 Coulomb * 1 Volt
    }

    void setJoules(double value) {
        joules = value;
    }

    void setErgs(double value) {
        joules = value / 1e7;
    }

    void setElectronVolts(double value) {
        joules = value * electronCharge;
    }
};

int main() {
    Energy energy(1000.0); // 1000 joules

    std::cout << "Energy in Joules: " << energy.getJoules() << std::endl;
    std::cout << "Energy in Ergs: " << energy.getErgs() << std::endl;
    std::cout << "Energy in Electron Volts: " << energy.getElectronVolts() << std::endl;

    energy.setElectronVolts(1.0); // Set the value to 1 electron-volt
    std::cout << "\nEnergy in Joules: " << energy.getJoules() << std::endl;
    std::cout << "Energy in Ergs: " << energy.getErgs() << std::endl;
    std::cout << "Energy in Electron Volts: " << energy.getElectronVolts() << std::endl;

    return 0;
}
