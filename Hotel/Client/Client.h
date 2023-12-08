#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <vector>

class Client
{
private:
    std::string clientName;
    int clientAge;
    std::string email;
    bool isVIP;

public:
    Client();
    ~Client();
    Client(std::string  name, int age, std::string  email, bool vip);
    Client& operator=(const Client& other);
    friend std::ostream& operator<<(std::ostream& os, const Client& client);

    [[maybe_unused]] void doClientSpecificTask();
};

#endif // CLIENT_H