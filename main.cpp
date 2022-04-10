/* 
#======================================================================#
#     T^3 eXtreme | Jarrod Burns | ta747839@gmail.com | 04/10/2022     #
# -------------------------- Version  1.0.0 -------------------------- #
#======================================================================#
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <windows.h>
#include <limits>
#include "GFX.hpp"
#include "TicTacToe.hpp"

int main()
{
    bool first_game = true;
    bool session_active = true;
    std::string replay_input;

    /*Setting the window size, this is a quick implementation, rewrite
    later if you want to remove the scroll bar from the terminal window. */

    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);

    // Session loop 
    while (session_active)
    {
        TicTacToe Game;
        GFX Graphics;
        int turn = 0;
        int player_move;
        std::string start_input;
        char marker = Game.is_player_one_turn ? 'x' : 'o';

        // Display welcome message on first session.
        if (first_game)
        {
            Graphics.draw_welcome_message();
            std::cout << "Input:  ";
            std::cin >> start_input;
            first_game = false;

            if (Game.exit_session(start_input))
            {
                Graphics.draw_exit_message();
                Sleep(3 *1000);
                break;
            }
        }

        // Game loop
        bool invalid_move = false;
        while (turn < 9)
        {
            Graphics.clear();
            Graphics.draw_input_boarder();
            Graphics.draw_board(Game.game_state);
            Graphics.draw_input_boarder();

            if (Game.is_player_one_turn)
            {
                std::cout << "Player ONE input:  ";
                if (invalid_move)
                {
                    std::cout << "Invalid selection, try again.  ";
                    invalid_move = false;
                }
            }
            else
            {
                std::cout << "Player TWO input:  ";
                if (invalid_move)
                {
                    std::cout << "Invalid selection, try again.  ";
                    invalid_move = false;
                }
            }

            std::cin >> player_move;

            // Checks for player markers in the position of player selection.
            if (Game.assert_invalid_move(player_move))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                turn - 1;
                invalid_move = true;
                continue;
            }

            Game.board_update(player_move);
            Graphics.draw_board(Game.game_state);

            /*Turn (5) is the earliest oppertunity for a player to win;
            beginning on that turn, we look for a win state. */

            if (turn >= 4)
            {
                if (Game.assert_win(marker))
                {
                    if (Game.is_player_one_turn)
                    {
                        Graphics.draw_p1_wins_message();
                        Sleep(3 *1000);
                    }
                    else
                    {
                        Graphics.draw_p2_wins_message();
                        Sleep(3 *1000);
                    }

                    break;
                }
            }

            turn += 1;

            if (turn == 9 && !Game.assert_win(marker))
            {
                Graphics.draw_tie_message();
                Sleep(3 *1000);
            }

            Game.is_player_one_turn = !Game.is_player_one_turn;
        }

        /*End of game promt, the user may select to play again or
        exit the session. I elected to allow any input as continue,
        however, I have included a method in "TicTacToe.hpp" to validate
        for (yes) inputs in the event you wish to enable the feature*/

        Graphics.draw_continue_message();
        std::cin >> replay_input;

        if (Game.exit_session(replay_input))
        {
            Graphics.draw_exit_message();
            Sleep(3 *1000);
            break;
        }
    }
}


