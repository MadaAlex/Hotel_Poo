// Client.h

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <stdexcept>
#include <string>

class Meniu;  // Forward declaration

class Client {
private:
    std::string clientName;
    int clientAge;
    std::string email;
    bool isVIP;

    void validateAge(int age);


public:
    Client();
    Client(std::string name, int age, std::string email, bool vip);
    ~Client();

    [[maybe_unused]] void doClientSpecificTask();

    Client& operator=(const Client& other);

    friend std::ostream& operator<<(std::ostream& os, const Client& client);

    static void validateEmail(const std::string& email);


    friend class Meniu;
};

#endif  // CLIENT_H
