#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

class TicTacToe
{
    public:
        bool is_player_one_turn = true;
    int score = 0;
    std::vector<std::vector<char>> game_state = 
    {
      {'1', '2', '3'},
      {'4', '5', '6'},
      {'7', '8', '9'}
    };
    std::map<int, std::pair<int, int>> position = 
    {
      { 1, {0, 0} },
      { 2, {0, 1} },
      { 3, {0, 2} },
      { 4, {1, 0} },
      { 5, {1, 1} },
      { 6, {1, 2} },
      { 7, {2, 0} },
      { 8, {2, 1} },
      { 9, {2, 2} },
    };


    bool check_score()
    {
        if (score == 3)
        {
            return true;
        }

        score = 0;
        return false;

    }

    bool assert_win(char marker)
    {
        if (assert_horizontal_win(marker) || assert_vertical_win(marker) || assert_diagonal_win(marker))
        {
            return true;
        }

        return false;
    }

    bool assert_horizontal_win(char marker)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (game_state[x % 3][y] == marker)
                {
                    score += 1;
                }
                else
                {
                    score -= 1;
                }
            }

            if (check_score())
            {
                return true;
            }
        }

        return false;
    }

    bool assert_vertical_win(char marker)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (game_state[y][x] == marker)
                {
                    score += 1;
                }
                else
                {
                    score -= 1;
                }
            }

            if (check_score())
            {
                return true;
            }
        }

        return false;
    }

    bool assert_diagonal_win(char marker)
    {
        // EAST to WEST diag
        for (int x = 0; x < 1; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (game_state[y][y] == marker)
                {
                    score += 1;
                }
            }
        }

        if (check_score())
        {
            return true;
        }

        // WEST to EAST diag
        for (int x = 0; x < 1; x++)
        {
            for (int y = 2; y > -1; y--)
            {
                if (game_state[abs(y - 2)][y] == marker)
                {
                    score += 1;
                }
            }
        }

        if (check_score())
        {
            return true;
        }

        return false;
    }

    bool assert_invalid_move(int pos)
    {
        if (game_state[position[pos].first][position[pos].second] == 'x' || game_state[position[pos].first][position[pos].second] == 'o')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void board_update(int pos)
    {
        game_state[position[pos].first][position[pos].second] = is_player_one_turn ? 'x' : 'o';
    }

    bool continue_session(std::string player_input)
    {
        /*I have elected to allow any input as yes, if you with to change that behavior,
        use this method to validate (yes) conditions. */

        std::set<std::string > yes = { "yes", "y", "1", "start", "s" };

        transform(player_input.begin(), player_input.end(), player_input.begin(), ::tolower);

        if (yes.find(player_input) != yes.end())
        {
            return true;
        }

        return false;
    }

    bool exit_session(std::string player_input)
    {
        std::set<std::string > no = { "no", "n", "quit", "q", "exit", "e", "0" };

        transform(player_input.begin(), player_input.end(), player_input.begin(), ::tolower);

        if (no.find(player_input) != no.end())
        {
            return true;
        }

        return false;
    }
};