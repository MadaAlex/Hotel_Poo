#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <stdexcept>

class Client {
public:
    Client();
    Client(std::string name, int age, std::string email, bool vip);
    ~Client();

    [[maybe_unused]] [[maybe_unused]] void doClientSpecificTask();
    Client& operator=(const Client& other);
    friend std::ostream& operator<<(std::ostream& os, const Client& client);

private:
    std::string clientName;
    int clientAge;
    std::string email;
    bool isVIP;

    void validateAge(int age);

    [[maybe_unused]] static void validateEmail(const std::string& email);
};

#endif // CLIENT_H
