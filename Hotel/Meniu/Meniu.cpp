// Meniu.cpp

#include "Meniu.h"
#include <iostream>

Meniu::Meniu() : cladire(1, "Sample Address", "Building 1"), cameraInstance(1, 101, "red", "double") {
}

void Meniu::run() {
    int choice;

    do {
        std::cout << "Meniu:" << std::endl;
        std::cout << "1. Display Building Information" << std::endl;
        std::cout << "2. Add a Client" << std::endl;
        std::cout << "3. Add a Floor" << std::endl;
        std::cout << "4. Add a Room to a Floor" << std::endl;
        std::cout << "5. Salariu" << std::endl;
        std::cout << "6. Add a Subordinate to an Employee" << std::endl;
        std::cout << "7. Exit" << std::endl;

        std::cout << "Enter your choice (1-7): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << cladire << std::endl;
                break;
            case 2: {
                std::string name, email;
                int age;
                bool isVIP;

                std::cout << "Enter client name: ";
                std::cin >> name;

                std::cout << "Enter client age: ";
                std::cin >> age;

                std::cout << "Enter client email: ";
                std::cin >> email;

                std::cout << "Is the client VIP? (1 for yes, 0 for no): ";
                std::cin >> isVIP;

                cladire.addClient(Client(name, age, email, isVIP));
                break;
            }
            case 3: {
                int floorId;
                std::cout << "Enter floor ID: ";
                std::cin >> floorId;

                std::string floorAddress, floorName;
                std::cout << "Enter floor address: ";
                std::cin >> floorAddress;

                std::cout << "Enter floor name: ";
                std::cin >> floorName;


                etaj.setId(floorId);
                etaj.setAddress(floorAddress);
                etaj.setName(floorName);

                cladire.addFloor(etaj);
                break;
            }
            case 4: {
                int floorId, roomId;
                std::cout << "Enter floor ID: ";
                std::cin >> floorId;

                std::cout << "Enter room ID: ";
                std::cin >> roomId;

                std::string roomColor, roomType;
                std::cout << "Enter room color: ";
                std::cin >> roomColor;

                std::cout << "Enter room type: ";
                std::cin >> roomType;

                Camera camera(roomId, floorId, roomColor, roomType);

                break;
            }
            case 5: {
                int percentageIncrease;
                int salariu = 5000;

                std::cout << "Enter percentage increase for salary: ";
                std::cin >> percentageIncrease;

                Angajati::maresteSalariu(percentageIncrease, salariu);

                //std::cout << "Annual Salary: " << Angajati::calculeazaSalariuAnual() << std::endl;
                break;
            }
            case 6: {
                int managerId, subordinateId;

                std::cout << "Enter manager's ID: ";
                std::cin >> managerId;

                std::cout << "Enter subordinate's ID: ";
                std::cin >> subordinateId;

                break;
            }
            case 7:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 7." << std::endl;
        }

    } while (choice != 7);
}
