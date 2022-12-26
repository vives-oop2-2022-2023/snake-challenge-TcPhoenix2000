#include "gameMenu.h"

namespace Linked_List::gameMenu {
displayOptionsMenu::displayOptionsMenu() {
    // Add some options to the menu
    optionsMenu.push_back("terminal renderer (default)");
    optionsMenu.push_back("sensehat renderer");
    optionsMenu.push_back("Return to main menu");

    while (true) {
        std::cout << "select renderer" << std::endl;
        // Display the options menu
        for (size_t i = 0; i < optionsMenu.length(); i++) {
            std::cout << i << "-" << optionsMenu.get(i) << std::endl;
        }

        std::cout << "Enter the number of the option you want to select: ";
        int selection;
        std::cin >> selection;

        if (selection < 0 || selection >= optionsMenu.length()) {
            std::cout << "Invalid selection" << std::endl;
            continue;
        }

        // Select the option
        optionsMenu.getNode(selection)->selected(true);

        // Display the selected option
        std::cout << "Selected: " << optionsMenu.get(selection) << std::endl;

        // Do something based on the selected option
        switch (selection) {
            case 0:
                // Select the renderer default
                break;
            case 1:
                // Select the renderer sensehat
                break;
            case 2:
                // Return to the main menu
                return;
        }
    }
}    
displayMenu::displayMenu() {
    // Add some menu items
    menu.push_back("Options");
    menu.push_back("Play");
    menu.push_back("Quit");

    while (true) {
        std::cout << "select menu option" << std::endl;
        // Display the menu
        for (size_t i = 0; i < menu.length(); i++) {
            std::cout << i << "-" << menu.get(i) << std::endl;
        }

        std::cout << "Enter the number of the menu item you want to select: ";
        int selection;
        std::cin >> selection;

        if (selection < 0 || selection >= menu.length()) {
            std::cout << "Invalid selection" << std::endl;
            continue;
        }

        // Select the menu item
        menu.getNode(selection)->selected(true);

        // Display the selected menu item
        std::cout << "Selected: " << menu.get(selection) << std::endl;

        // Do something based on the selected menu item
        switch (selection) {
            case 0:
                // Show the options
                displayOptionsMenu();
                break;
            case 1:
                // Play the game
                //game.start();
                break;
            case 2:
                // Quit the program
                return;
        }
    }
}
}
