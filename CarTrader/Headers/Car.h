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
        int originalPrice;
        int notSoldBonus;
        int currentPrice;
        int yearBuilt;
        int yearsOwned;
    public:
        //GET
        User getOwnedBy();
        std::string getCompany();
        std::string getModel();
        int getLowerValuePerYear();
        int getOriginalPrice();
        int getNotSoldBonus();
        int getCurrentPrice();
        int getYearBuilt();
        int getYearsOwned();
        //SET
        int setOwnedBy(User user);
        int setCompany(std::string company);
        int setModel(std::string model);
        int setLowerValuePerYear(int value);
        int setOriginalPrice(int price);
        int setNotSoldBonus(int bonus);
        int setCurrentPrice(int price);
        int setYearBuilt(int year);
        //OTHER
        int resetYearsOwned();
        int addYearsOwned();
        int calculatePrice(int year);
};