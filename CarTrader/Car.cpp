#include <iostream>

#include "Headers/Car.h"
#include "Headers/User.h"

// GET
User Car::getOwnedBy(){
    return Car::ownedBy;
}
std::string Car::getCompany(){
    return Car::company;
}
std::string Car::getModel(){
    return Car::model;
}
int Car::getLowerValuePerYear(){
    return Car::lowerValuePerYear;
}
int Car::getOriginalPrice(){
    return Car::originalPrice;
}
int Car::getNotSoldBonus(){
    return Car::notSoldBonus;
}
int Car::getCurrentPrice(){
    return Car::currentPrice;
}
int Car::getYearBuilt(){
    return Car::yearBuilt;
}
int Car::getYearsOwned(){
    return Car::yearsOwned;
}

// SET

int Car::setOwnedBy(User user){
    Car::ownedBy = user;
    return 200;
}
int Car::setCompany(std::string company){
    Car::company = company;
    return 200;
}
int Car::setModel(std::string model){
    Car::model = model;
    return 200;
}
int Car::setLowerValuePerYear(int value){
    Car::lowerValuePerYear = value;
    return 200;
}
int Car::setOriginalPrice(int price){
    Car::originalPrice = price;
    return 200;
}
int Car::setNotSoldBonus(int bonus){
    Car::notSoldBonus = bonus;
    return 200;
}
int Car::setCurrentPrice(int price){
    Car::currentPrice = price;
    return 200;
}
int Car::setYearBuilt(int year){
    Car::yearBuilt = year;
    return 200;
}

// OTHER

int Car::resetYearsOwned(){
    Car::yearsOwned = 0;
    return 200;
}

int Car::addYearsOwned(){
    Car::yearsOwned += 1;
    return 200;
}

int Car::calculatePrice(int year){
    int price = Car::getOriginalPrice();
    int tmpPrice;
    int yearLeft;
    yearLeft = year - Car::getYearBuilt();
    tmpPrice = Car::getLowerValuePerYear() * yearLeft;
    int oldPrice = price;
    price -= tmpPrice;
    if (price < 100)
    {
        price = oldPrice;
    }
    Car::setCurrentPrice(price);
    return 200;
}