#include <iostream>

#include "Headers/User.h"

int main(){
    User guestUser;
    guestUser.setUsername("guest");
    guestUser.setPassword("password", "");
    return 0;
}