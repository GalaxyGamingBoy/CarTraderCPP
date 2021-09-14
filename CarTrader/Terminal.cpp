#include <iostream>
#include <vector>

#include "Headers/Terminal.h"

void Terminal::registerUser(){
    std::string newUsername;
    std::string newPassword;
    std::string loginOnRegisterUnformatted;
    bool loginOnRegister;

    std::cout << "New User Form" << std::endl << "NO SPACES ALLOWED" << std::endl;
    
    std::cout << "Account Username: ";
    std::cin >> newUsername;

    std::cout << "Account Password: ";
    std::cin >> newPassword;

    std::cout << "Login after register? (y/N): ";
    std::cin >> loginOnRegisterUnformatted;

    if (loginOnRegisterUnformatted == "y"){
        loginOnRegister = true;
    }else{
        loginOnRegister = false;
    }

    User newUser;
    newUser.setUsername(newUsername);
    newUser.setPassword("password", newPassword);
    Terminal::registeredUsers.push_back(newUser);

    if (loginOnRegister){
        Terminal::loggedInUser = newUser;
    }
}

int Terminal::loginUser(){
    User selectedUser;
    std::string enteredUsername;
    std::string enteredPassword;

    std::cout << "Login Form" << std::endl << "NO SPACES ALLOWED" << std::endl;

    std::cout << "Username: ";
    std::cin >> enteredUsername;

    for (User i : Terminal::registeredUsers){
        if (i.getUsername() == enteredUsername){
            selectedUser = i;
        }
    }
    if (selectedUser.getUsername() == ""){
        std::cout << "Username not found!" << std::endl;
        return 400;
    }

    std::cout << "Password: ";
    std::cin >> enteredPassword;

    if (selectedUser.getPassword() == enteredPassword){
        std::cout << "Login Complete!" << std::endl;
        Terminal::loggedInUser = selectedUser;
    }else{
        std::cout << "Password not correct!" << std::endl;
        return 400;
    }

    return 200;
}

int Terminal::findCommand(std::string command){
    if (command == "ping"){
        return Terminal::commandList.ping();
    }
    else if (command == "debugMode"){
        Terminal::debugMode = !Terminal::debugMode;
        if (Terminal::debugMode) {
            std::cout << "Debug Mode: Enabled" << std::endl;
        }else{
            std::cout << "Debug Mode: Disabled" << std::endl;
        }
        return 200;
    }
    else if (command == "register"){
        Terminal::registerUser();
        return 200;
    }
    else if (command == "login"){
        return Terminal::loginUser();
    }
    else if (command == "users"){
        for (User i : Terminal::registeredUsers){
            std::cout << i.getUsername() << std::endl;
        }
        return 200;
    }
    else if (command == "exit" || command == "e"){
        Terminal::loop = false;
        return 200;
    }
    else{
        return 404;
    }
}

void Terminal::requestForUserInput(){
    while (Terminal::loop) {
        std::string username = Terminal::loggedInUser.getUsername();
        std::string currentCommand;

        std::cout << username << " ~ Terminal .:> ";
        std::cin >> currentCommand;

        int rc = Terminal::findCommand(currentCommand);

        if (Terminal::debugMode){
            std::cout << std::endl << "Return Code: " << rc << std::endl;
        }
    }
}

void Terminal::startTerminal(CommandList cl){
    Terminal::commandList = cl;
    Terminal::loop = true;
    Terminal::requestForUserInput();
}