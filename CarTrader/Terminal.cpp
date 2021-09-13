#include <iostream>

#include "Headers/Terminal.h"

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
        std::string username = "guest";
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