#include "terminal.h"

namespace Bios {

  void Terminal::clear(void) {
    system("clear");
  }

  void Terminal::flush(void) {
    fflush(stdout);
  }

  void Terminal::hide_cursor(void) {
    printf("\33[?25l");
  }

  void Terminal::show_cursor(void) {
    printf("\e[?25h");
  }

  void Terminal::move_cursor(unsigned int x, unsigned int y) {
    printf("%c[%d;%df", 0x1B, y, x);
  }

  void Terminal::foreground_color(std::string color, bool bright) {
    std::string colorCode = Terminal::colors.at(color);
    printf("%s%s", colorCode.substr(0, colorCode.length()-1).c_str(), (bright ? ";1m" : "m"));
  }

  void Terminal::reset_foreground_color(void) {
    printf("\u001b[0m");
  }

  void Terminal::background_color(std::string color, bool bright) {
    std::string colorCode = Terminal::colors.at(color);
    colorCode.replace(colorCode.find('3'), 1, "4");   // Replace 3 by 4 in colorCode for background
    printf("%s%s", colorCode.substr(0, colorCode.length()-1).c_str(), (bright ? ";1m" : "m"));
  }

  void Terminal::reset_background_color(void) {
    printf("\u001b[0m");
  }

  const std::map<std::string,std::string> Terminal::colors = {
    { "black", "\u001b[30m" },
    { "red", "\u001b[31m" },
    { "green", "\u001b[32m" },
    { "yellow", "\u001b[33m" },
    { "blue", "\u001b[34m" },
    { "magenta", "\u001b[35m" },
    { "cyan", "\u001b[36m" },
    { "white", "\u001b[37m" },
  };
};