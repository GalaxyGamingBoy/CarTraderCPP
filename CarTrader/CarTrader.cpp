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

    terminal.startTerminal(cl);

    return 0;
}