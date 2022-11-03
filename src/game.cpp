#include "game.h"

using namespace std;

    Game::Game(){
        StartupSign();
    }
    void Game::update(){//update entities

    }
    void Game::draw(){//draw entities on canvas

    }
    void Game::render(){//output canvas to renderer (terminal)
        Canvas();
    }
    void Game::StartupSign(){
        //when the game starts cool ascii title is displayed 
        //    _____  _  _      _  _                 _____  _
        //  /  ___|| |(_)    | |(_)               /  ___|| |
        //  \ `--. | | _   __| | _  _ __    __ _  \ `--. | | _   _   __ _
        //  `--. \| || | / _` || || '_ \  / _` |  `--. \| || | | | / _` |
        //  /\__/ /| || || (_| || || | | || (_| | /\__/ /| || |_| || (_| |
        //  \____/ |_||_| \__,_||_||_| |_| \__, | \____/ |_| \__,_| \__, |
        //                                  __/ |                    __/ |
        //                                  |___/                    |___/
        cout << "   _____  _  _      _  _                 _____  _               " << endl;
        cout << "  /  ___|| |(_)    | |(_)               /  ___|| |              " << endl;
        cout << "  \u005c `--. | | _   __| | _  _ __    __ _  \u005c `--. | | _   _   __ _ " << endl;
        cout << "   `--. \u005c| || | / _` || || '_ \u005c  / _` |  `--. \u005c| || | | | / _` |" << endl;
        cout << "  /\u005c__/ /| || || (_| || || | | || (_| | /\u005c__/ /| || |_| || (_| |" << endl;
        cout << "  \u005c____/ |_||_| \u005c__,_||_||_| |_| \u005c__, | \u005c____/ |_| \u005c__,_| \u005c__, |" << endl;
        cout << "                                  __/ |                    __/ |" << endl;
        cout << "                                 |___/                    |___/ " << endl;
    }