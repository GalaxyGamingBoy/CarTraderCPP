#pragma once

#include <iostream>
#include <vector>

#include "CommandList.h"
#include "User.h"

class Terminal{
    private:
        CommandList commandList;
        bool debugMode = false;
        bool loop;
        int findCommand(std::string command);
    public:
        User loggedInUser;
        std::vector<User> registeredUsers;
        void startTerminal(CommandList cl);
        void registerUser();
        int loginUser();
        void requestForUserInput();
};