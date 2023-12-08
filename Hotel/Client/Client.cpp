#include "Client.h"

#include <utility>

Client::Client()
        : clientName("DefaultClient"), clientAge(0), email("default@example.com"), isVIP(false)
{
}

Client::Client(std::string  name, int age, std::string  email, bool vip)
        : clientName(std::move(name)), clientAge(age), email(std::move(email)), isVIP(vip)
{
}

Client::~Client() {

    std::cout << "Client destrutor" <<"\n";
}

[[maybe_unused]] void Client::doClientSpecificTask()
{
    std::cout << "Client " << clientName << " is performing a specific task." << std::endl;

}


Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        clientName = other.clientName;
        clientAge = other.clientAge;
        email = other.email;
        isVIP = other.isVIP;
    }
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Client& client)
{
    os << "Client Name: " << client.clientName
       << ", Age: " << client.clientAge
       << ", Email: " << client.email
       << ", VIP Status: " << (client.isVIP ? "Yes" : "No");

    return os;
}