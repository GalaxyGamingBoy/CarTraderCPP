#pragma once

#include <iostream>

class User{
private:
    std::string username;
    std::string password = "password"; 
public:
    // GET
    std::string getUsername();
    std::string getPassword();
    // SET
    int setUsername(std::string username);
    int setPassword(std::string oldPassword, std::string newPassword);
};