#include <iostream>

#include "Headers/User.h"

int main(){
    User guestUser;
    guestUser.setUsername("guest");
    guestUser.setPassword("password", "guestPassword");

    std::cout << guestUser.getUsername() << std::endl;
    std::cout << guestUser.getPassword() << std::endl;

    return 0;
}