#include <iostream>
#include <windows.h>
#include "../GFX.hpp"

int main()
{
  std::vector<std::vector < char>> game_state = {
    {'1', '2', '3' },
    {'4', '5', '6' },
    {'7', '8', '9' }
  };

  HWND console = GetConsoleWindow();
  RECT ConsoleRect;
  GetWindowRect(console, &ConsoleRect);

  MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);

  GFX Graphics;
  while (true)
  {
    Graphics.draw_welcome_message();
    Sleep(1 *1000);
    Graphics.clear();
    Graphics.draw_board(game_state);
    Sleep(1 *1000);
    Graphics.draw_continue_message();
    Sleep(1 *1000);
    Graphics.draw_p1_wins_message();
    Sleep(1 *1000);
    Graphics.draw_p2_wins_message();
    Sleep(1 *1000);
    Graphics.draw_tie_message();
    Sleep(1 *1000);
    Graphics.draw_exit_message();
    Sleep(1 *1000);

    Sleep(3 *1000);
  }
}