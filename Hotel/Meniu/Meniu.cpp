// Meniu.cpp

#include "Meniu.h"
#include <iostream>

Meniu::Meniu() : cladire(1, "Sample Address", "Building 1"), cameraInstance(1, 101, "red", "double"), angajat(1, 5000, "John Doe") {
}

void Meniu::run() {
    int choice;

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

                    if (isValidEmail(email)) {

                        cladire.addClient(Client(name, age, email, isVIP));
                    } else {
                        std::cout << "Invalid email. Client not added." << std::endl;
                    }

                    cladire.addClient(Client(name, age, email, isVIP));
                    break;
                }
                case 3: {
                    int floorId;
                    std::cout << "Enter floor ID: ";
                    std::cin >> floorId;

                    if (floorId < 0) {
                        throw InvalidFloorIdException();
                    }

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
                    camera.getEtaj();
                    break;
                }
                case 5: {
                    int percentageIncrease;
                    int salariu = 4000;

                    std::cout << "Enter percentage increase for salary: ";
                    std::cin >> percentageIncrease;

                    Angajati::maresteSalariu(percentageIncrease, salariu);
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
                case 7: {
                    int roomId;
                    std::cout << "Enter room ID to clean: ";
                    std::cin >> roomId;

                    Camera roomToClean(roomId, 0, "white", "single");
                    angajat.curataCamera(roomToClean);
                    break;
                }
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

bool Meniu::isValidEmail(const std::string& email) {
    try {
        // Call the static function using the class name
        Client::validateEmail(email);
        return true;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid email: " << e.what() << std::endl;
        return false;
    }
}