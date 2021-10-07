#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Headers/Terminal.h"
#include "Headers/JSON/json.hpp"

void Terminal::registerTestCars(){
    for (int i; i < Terminal::startCars["Count"]; i++){
        std::cout << "Registering Car Model: " << Terminal::startCars["Cars"][i]["model"] << std::endl;
        Car newCar;
        newCar.setCompany(Terminal::startCars["Cars"][i]["company"]);
        newCar.setModel(Terminal::startCars["Cars"][i]["model"]);
        newCar.setLowerValuePerYear(Terminal::startCars["Cars"][i]["lowerValuePerYear"]);
        newCar.setOriginalPrice(Terminal::startCars["Cars"][i]["originalPrice"]);
        newCar.setNotSoldBonus(Terminal::startCars["Cars"][i]["notSoldBonus"]);
        newCar.setYearBuilt(Terminal::startCars["Cars"][i]["yearBuilt"]);
        newCar.resetYearsOwned();
        newCar.setOwnedBy(Terminal::loggedInUser);
        Terminal::registeredCars.push_back(newCar);
    }
}

std::string readfile(std::string file){
    std::string ln;
    std::string content;
    std::ifstream fl(file);
    if(fl.is_open()){
        while(std::getline(fl, ln)){
            content += ln;
            content += "\n";
        }
        fl.close();
        return content;
    }else return "ERROR: UNABLE / NOT FOUND REQUESTED FILE!";
}
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
    else if (command == "cars"){
        std::cout << "Cars Owned By User: " << Terminal::loggedInUser.getUsername() << std::endl;
        for (Car i : Terminal::registeredCars){
            if (i.getOwnedBy().getUsername() == Terminal::loggedInUser.getUsername())
            {
                i.calculatePrice(Terminal::year);
                std::cout <<
                "Car Model: " << i.getModel() << ", " <<
                "Car Comapny: " << i.getCompany() << ", " <<
                "Owned For: " << i.getYearsOwned() << " Year/s, " <<
                "Car Built: " << i.getYearBuilt() << ", " <<
                "Original Price: " << i.getOriginalPrice() << ", " <<
                "Decrease per year: " << i.getLowerValuePerYear() << ", " <<
                "Not Sold Bonus: " << i.getNotSoldBonus() << ", " <<
                "Current Price: " << i.getCurrentPrice() << std::endl;
            }
        }
        return 200;
    }
    else if (command == "registerTestCars"){
        Terminal::registerTestCars();
        return 200;
    }
    else if (command == "test"){
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

    Terminal::startCars = nlohmann::json::parse(readfile("./Files/startCars.json"));

    // Generate start cars
    Terminal::registerTestCars();

    Terminal::requestForUserInput();
}