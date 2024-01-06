#include "Client.h"

Client::Client()
        : clientName("DefaultClient"), clientAge(0), email("default@example.com"), isVIP(false)
{
}

Client::Client(std::string name, int age, std::string email, bool vip)
        : clientName(std::move(name)), clientAge(0), email(std::move(email)), isVIP(vip)
{
    validateAge(age);
}

Client::~Client() {
    std::cout << "Client destructor" << "\n";
}

[[maybe_unused]] void Client::doClientSpecificTask() {
    std::cout << "Client " << clientName << " is performing a specific task." << std::endl;
}

Client& Client::operator=(const Client& other) {
    if (this != &other) {
        clientName = other.clientName;
        validateAge(other.clientAge);
        email = other.email;
        isVIP = other.isVIP;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Client& client) {
    os << "Client Name: " << client.clientName
       << ", Age: " << client.clientAge
       << ", Email: " << client.email
       << ", VIP Status: " << (client.isVIP ? "Yes" : "No");

    return os;
}

void Client::validateAge(int age) {
    if (age < 0) {
        throw std::invalid_argument("Invalid argument: Age must be non-negative.");
    }
    clientAge = age;
}

void Client::validateEmail(const std::string& email) {
    try {
        std::cout << "Email is valid: " << email << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid email: " << e.what() << std::endl;
    }
}