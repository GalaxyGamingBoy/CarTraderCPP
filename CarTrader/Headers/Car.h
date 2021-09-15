#pragma once

#include <iostream>
#include <string>

#include "User.h"

class Car {
    private:
        User ownedBy;
        std::string company;
        std::string model;
        int lowerValuePerYear;
        int decreaseAmmount;
        int originalPrice;
        int bonus;
        int currentPrice;
        int yearBuilt;
        int yearsOwned;
    public:
        //GET
        User getOwnedBy();
        std::string getCompany();
        std::string getModel();
        int getLowerValuePerYear();
        int getDecreaseAmmount();
        int getOriginalPrice();
        int getBonus();
        int getCurrentPrice();
        int getYearBuilt();
        int getYearsOwned();
        //SET
        int setOwnedBy(User user);
        int setCompany(std::string company);
        int setModel(std::string model);
        int setLowerValuePerYear(int value);
        int setDecreaseAmmount(int ammount);
        int setOriginalPrice(int price);
        int setBonus(int bonus);
        int setCurrentPrice(int price);
        int setYearBuilt(int year);
        //OTHER
        int resetYearsOwned();
        int addYearsOwned();
        int calculatePrice(int year);
};