// gameMenu.h
#pragma once

#include <iostream>
#include <string>
#include "linkedList.h"
#include "../game.h"

namespace Linked_List::gameMenu {
    class displayMenu {
    private:
        linkedList<std::string> menu;
        VIVES::Game game;
    public:
        displayMenu();
    };

    class displayOptionsMenu {
    private:
        linkedList<std::string> optionsMenu;
    public:
        displayOptionsMenu();
    };
}