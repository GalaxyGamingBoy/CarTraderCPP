#include <iostream>

#include "Headers/User.h"
#include "Headers/Terminal.h"
#include "Headers/CommandList.h"

int main(){
    User guestUser;
    guestUser.setUsername("guest");
    guestUser.setPassword("password", "guestPassword");

    CommandList cl;
    Terminal terminal;

    terminal.loggedInUser = guestUser;
    terminal.registeredUsers.push_back(guestUser);

    terminal.startTerminal(cl);

    return 0;
}