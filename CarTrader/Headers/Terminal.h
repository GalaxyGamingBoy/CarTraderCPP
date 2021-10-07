#pragma once

#include <iostream>
#include <vector>

#include "CommandList.h"
#include "User.h"
#include "Car.h"
#include "JSON/json.hpp"

class Terminal{
    private:
        CommandList commandList;
        bool debugMode = false;
        bool loop;
        int findCommand(std::string command);
    public:
        int year = 2021;
        nlohmann::json startCars;
        User loggedInUser;
        std::vector<User> registeredUsers;
        std::vector<Car> registeredCars;
        void startTerminal(CommandList cl);
        void registerUser();
        void registerTestCars();
        int loginUser();
        void requestForUserInput();
};