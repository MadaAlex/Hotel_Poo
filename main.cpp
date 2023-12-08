#include <iostream>
#include "Hotel/Cladire/Cladire.h"
#include "Hotel/Client/Client.h"
#include "Hotel/Angajati/Angajati.h"

int main() {
    Cladire cladire(1, "Sample Address", "Building 1");
    Camera cameraInstance(1, 101, "red", "double");
    int choice;

    do {
        std::cout << "Meniu:" << std::endl;
        std::cout << "1. Display Building Information" << std::endl;
        std::cout << "2. Add a Client" << std::endl;
        std::cout << "3. Add a Floor" << std::endl;
        std::cout << "4. Add a Room to a Floor" << std::endl;
        std::cout << "5. Display All Clients" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "Enter your choice (1-6): ";
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

                cladire.addRoomToFloor(floorId,cameraInstance);
                break;
            }
            case 5:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
        }

    } while (choice != 6);

    Angajati angajat;

    int initialSalary = 5000;

    Angajati::maresteSalariu(10, initialSalary);

    std::cout << angajat;

    return 0;
}
