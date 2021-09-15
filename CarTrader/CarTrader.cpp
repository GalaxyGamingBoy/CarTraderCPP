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

    Car car;
    terminal.startTerminal(cl);

    return 0;
}