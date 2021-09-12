#include <iostream>

#include "Headers/User.h"

// GET
std::string User::getUsername(){
    return User::username;
}

std::string User::getPassword(){
    return User::password;
}

// SET

int User::setUsername(std::string username){
    User::username = username;
    return 200;
}

int User::setPassword(std::string oldPassword, std::string newPassword) {
    if (User::password == oldPassword) {
        User::password = newPassword;
        return 200;
    }else{
        return 400;
    }
}