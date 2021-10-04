#include <iostream>

#include "Headers/User.h"
#include "Headers/Terminal.h"
#include "Headers/CommandList.h"
#include "Headers/Car.h"

int main(){
    int year = 2021;
    User guestUser;
    guestUser.setUsername("guest");
    guestUser.setPassword("password", "guestPassword");

    CommandList cl;
    Terminal terminal;

    terminal.loggedInUser = guestUser;
    terminal.registeredUsers.push_back(guestUser);

    Car testCar;
    testCar.setYearBuilt(2020);
    testCar.setLowerValuePerYear(1000);
    testCar.setNotSoldBonus(testCar.getLowerValuePerYear() / 4);
    testCar.setCompany("GComp");
    testCar.setOwnedBy(terminal.registeredUsers[0]);
    testCar.setOriginalPrice(10000);
    testCar.setModel("Model G");
    testCar.addYearsOwned();

    terminal.registeredCars.push_back(testCar);
    terminal.startTerminal(cl);

    return 0;
}