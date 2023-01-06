#pragma once

#include <iostream>
#include <string>
#include "linkedList.h"
#include "../game.h"

#include "../renderers/TextRenderer.h"
#include "../renderers/bitmap_renderer.h"
#include "../renderers/sensehatRenderer.h"

namespace Linked_List {
    class displayMenu {
    private:
        VIVES::Game game;
        linkedList<std::string> menu;
        linkedList<std::string> optionsMenu;
    public:
        displayMenu();
        void OptionsMenu();
    };
}