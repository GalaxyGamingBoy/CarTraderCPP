#pragma once

#include <iostream>
#include <vector>

#include "CommandList.h"
#include "User.h"
#include "Car.h"

class Terminal{
    private:
        CommandList commandList;
        bool debugMode = false;
        bool loop;
        int findCommand(std::string command);
    public:
    int year = 2021;
        User loggedInUser;
        std::vector<User> registeredUsers;
        std::vector<Car> registeredCars;
        void startTerminal(CommandList cl);
        void registerUser();
        int loginUser();
        void requestForUserInput();
};