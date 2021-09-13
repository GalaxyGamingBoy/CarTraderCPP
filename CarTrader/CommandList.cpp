#include <iostream>

#include "Headers/CommandList.h"

int CommandList::ping(){
    std::cout << "Pong!" << std::endl;
    return 200;
}