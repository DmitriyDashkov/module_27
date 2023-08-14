#include "chat.h"
#include <iostream>

int main()
{
    Chat* chat = new Chat("OurChat");
    chat->working();

    delete chat;
    return 0;
}