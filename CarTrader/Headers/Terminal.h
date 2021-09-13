#pragma once

#include <iostream>

#include "CommandList.h"

class Terminal{
    private:
        CommandList commandList;
        bool debugMode = false;
        bool loop;
        int findCommand(std::string command);
    public:
        void startTerminal(CommandList cl);
        void requestForUserInput();
};