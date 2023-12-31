
// Meniu.cpp
#include "Meniu.h"
#include <iostream>

Meniu::Meniu() : cladire(1, "Sample Address", "Building 1"),
                 cameraInstance(1, 101, "red", "double"),
                 angajat(1, 5000, "John Doe") {
}

void Meniu::run() {

    do {
        try {
            std::cout << "Meniu:" << std::endl;
            std::cout << "1. Display Building Information" << std::endl;
            std::cout << "2. Add a Client" << std::endl;
            std::cout << "3. Add a Floor" << std::endl;
            std::cout << "4. Add a Room to a Floor" << std::endl;
            std::cout << "5. Salariu" << std::endl;
            std::cout << "6. Add a Subordinate to an Employee" << std::endl;
            std::cout << "7. Clean a Room" << std::endl;
            std::cout << "8. Exit" << std::endl;

            std::cout << "Enter your choice (1-8): ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    displayBuildingInfo();
                    break;
                case 2:
                    addClient();
                    break;
                case 3:
                    addFloor();
                    break;
                case 4:
                    addRoom();
                    break;
                case 5:
                    calculateSalary();
                    break;
                case 6:
                    addSubordinate();
                    break;
                case 7:
                    cleanRoom();
                    break;
                case 8:
                    std::cout << "Exiting the program. Goodbye!" << std::endl;
                    break;
                default:
                    throw InvalidChoiceException();
            }
        } catch (const MeniuException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } while (choice != 8);
}

void Meniu::displayBuildingInfo() {
    std::cout << cladire << std::endl;
}

void Meniu::addClient() {
    try {
        std::string name, email;
        int age;
        bool isVIP;

        std::cout << "Enter client name: ";
        std::cin >> name;

        std::cout << "Enter client age: ";
        std::cin >> age;

        std::cout << "Enter client email: ";
        if (!(std::cin >> email)) {

            std::cin.clear();
            throw std::runtime_error("Error: Invalid input for email.");
        }

        if (email.empty()) {
            throw std::runtime_error("Error: Email cannot be empty.");
        }

        std::cout << "Is the client VIP? (1 for yes, 0 for no): ";
        std::cin >> isVIP;

        if (isValidEmail(email)) {

            cladire.addClient(Client(name, age, email, isVIP));
        } else {
            throw InvalidEmailException();
        }

        Client newClient(name, age, email, isVIP);
        cladire.addClient(newClient);

        newClient.doClientSpecificTask();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Meniu::addFloor() {

    long int floorId;
    std::string floorAddress;
    std::string floorName;


    std::cout << "Enter floor ID: ";
    std::cin >> floorId;

    std::cout << "Enter floor address: ";
    std::cin >> floorAddress;

    std::cout << "Enter floor name: ";
    std::cin >> floorName;

    etaj.setId(floorId);
    etaj.setAddress(floorAddress);
    etaj.setName(floorName);

    cladire.addFloor(floorId, etaj);



}
void Meniu::addRoom() {
    try {
        int floorId, roomId;
        std::cout << "Enter floor ID: ";
        std::cin >> floorId;

        std::cout << "Enter room ID: ";
        std::cin >> roomId;

        std::cout << "Enter room color: ";
        std::string roomColor;
        std::cin >> roomColor;

        std::cout << "Enter room type: ";
        std::string roomType;
        std::cin >> roomType;

        auto * newCamera = new Camera(roomId, floorId, roomColor, roomType);
        etaj.adaugaCamera(newCamera);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void Meniu::calculateSalary() {
    try {
        int percentageIncrease;
        int salariu = 4000;

        std::cout << "Enter percentage increase for salary: ";
        std::cin >> percentageIncrease;

        Angajati::maresteSalariu(percentageIncrease, salariu);

        std::cout << "Annual Salary: " << angajat.calculeazaSalariuAnual() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Meniu::addSubordinate() {
    try {
        int managerId, subordinateId;

        std::cout << "Enter manager's ID: ";
        std::cin >> managerId;

        std::cout << "Enter subordinate's ID: ";
        std::cin >> subordinateId;

        std::vector<Angajati> angajatiList;

        try {
            Angajati manager(managerId, 3000, "ManagerName");
            angajatiList.push_back(manager);

            Angajati* managerPtr = nullptr;

            for (auto & i : angajatiList) {
                if (i.getId() == managerId) {
                    managerPtr = &i;
                    break;
                }
            }


            if (!managerPtr) {
                throw ManagerNotFoundException();
            }

            Angajati subordinate(subordinateId, 2000, "John");
            managerPtr->adaugaSubaltern(subordinate);
        } catch (const ManagerNotFoundException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Meniu::cleanRoom() {
    try {
        int roomId;
        std::cout << "Enter room ID to clean: ";
        std::cin >> roomId;

        Camera roomToClean(roomId, 0, "white", "single");
        angajat.curataCamera(roomToClean);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

bool Meniu::isValidEmail(const std::string& email) {
    try {
        Client::validateEmail(email);
        return true;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid email: " << e.what() << std::endl;
        return false;
    }
}

