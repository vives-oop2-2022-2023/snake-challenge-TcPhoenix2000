#include "gameMenu.h"

namespace Linked_List {
void displayMenu::OptionsMenu() {
    // Add some options to the menu
    optionsMenu.clear();
    optionsMenu.push_back("Terminal renderer (default)");
    optionsMenu.push_back("Sensehat renderer");
    optionsMenu.push_back("BitMap renderer");
    VIVES::TextRenderer *newTextRenderer = new VIVES::TextRenderer();
    VIVES::BitmapRenderer *newBitRenderer = new VIVES::BitmapRenderer();
    
        std::cout << "select renderer" << "\r\n";
        // Display the options menu
        for (size_t i = 0; i < optionsMenu.length(); i++) {
            std::cout << i << "-" << optionsMenu.get(i) << "\r\n";
        }

        std::cout << "Enter the number of the option you want to select: ";
        size_t selection;
        std::cin >> selection;

        if (selection < 0 || selection >= optionsMenu.length()) {
            game.StartupSign();
            std::cout << "Invalid selection" << "\r\n";
            
        }
        else{
        
        game.StartupSign();
        // Display the selected option
        std::cout << "Selected: " << optionsMenu.get(selection) << "\r\n";
        // Do something based on the selected option
        switch (selection) {
            case 0:
                // Select the renderer default
                game.setRenderer(newTextRenderer);
                break;
            case 1:
                // Select the renderer sensehat
                //game.setRenderer(new VIVES::SenseHatRenderer());
                break;
            case 2:
                // Select the renderer Bitmap
                game.setRenderer(newBitRenderer);
                break;
            }

        }
    //}
}   

displayMenu::displayMenu() {
    // Add some menu items
    menu.clear();
    menu.push_back("Options");
    menu.push_back("Play");
    menu.push_back("Quit");

        while (true) {
            std::cout << "select menu option" << "\r\n";
            // Display the menu
            for (size_t i = 0; i < menu.length(); i++) {
                std::cout << i << "-" << menu.get(i) << "\r\n";
            }

            std::cout << "Enter the number of the menu item you want to select: ";
            size_t selection;
            std::cin.clear();
            std::cin.sync();
            if (!(std::cin >> selection)) {
                // Clear the error state and try again
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                game.StartupSign();
                std::cout << "Invalid selection" << "\r\n";
                continue;
            }else if (selection < 0 || selection >= menu.length()) {
                game.StartupSign();
                std::cout << "Invalid selection" << "\r\n";
                continue;
            }else{
            // Select the menu item
            //menu.getNode(selection);

            game.StartupSign();
            // Display the selected menu item
            std::cout << "Selected: " << menu.get(selection) << "\r\n";

            // Do something based on the selected menu item
            switch (selection) {
                case 0:
                    // Show the options
                    OptionsMenu();
                    break;
                case 1:
                    // Play the game
                    game.start();
                    break;
                case 2:
                    menu.clear();
                    // Quit the program
                    exit(0);
                    break;
                }
            }
        }    
    }
}
