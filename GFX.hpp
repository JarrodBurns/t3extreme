#include <iostream>
#include <windows.h>
#include <vector>

class GFX
{
    private:
    const std::string welcome_message ="\n             __      __       .__                                  __                     \n            /  \\    /  \\ ____ |  |   ____  ____   _____   ____   _/  |_  ____             \n            \\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\  \\   __\\/  _ \\            \n             \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/   |  | (  <_> )           \n              \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >  |__|  \\____/            \n                   \\/       \\/          \\/            \\/     \\/                           \n      ___________  /\\  ________              ____  ___ __                                 \n      \\__    ___/ /  \\ \\_____  \\        ____ \\   \\/  //  |________   ____   _____   ____  \n        |    |    \\/\\/   _(__  <      _/ __ \\ \\     /\\   __\\_  __ \\_/ __ \\ /     \\_/ __ \\ \n        |    |          /       \\     \\  ___/ /     \\ |  |  |  | \\/\\  ___/|  Y Y  \\  ___/ \n        |____|         /______  /      \\___  >___/\\  \\|__|  |__|    \\___  >__|_|  /\\___  >\n                              \\/           \\/      \\_/                  \\/      \\/     \\/ \n\n\n\n\n\n\n         __           __                 __    __       __                .__  __    __   \n        / /   _______/  |______ ________/  |_  \\ \\     / /    ____ ___  __|__|/  |_  \\ \\  \n       / /   /  ___/\\   __\\__  \\\\_  __ \\   __\\  \\ \\   / /   _/ __ \\\\  \\/  /  \\   __\\  \\ \\ \n       \\ \\   \\___ \\  |  |  / __ \\|  | \\/|  |    / /   \\ \\   \\  ___/ >    <|  ||  |    / / \n        \\_\\ /____  > |__| (____  /__|   |__|   /_/     \\_\\   \\___  >__/\\_ \\__||__|   /_/  \n                 \\/            \\/                                \\/      \\/               \n";
    const std::string continue_message = "\n\n\n                 _________                __  .__                   _________ \n                 \\_   ___ \\  ____   _____/  |_|__| ____  __ __   ___\\_____   \\\n                 /    \\  \\/ /  _ \\ /    \\   __\\  |/    \\|  |  \\_/ __ \\ /   __/\n                 \\     \\___(  <_> )   |  \\  | |  |   |  \\  |  /\\  ___/|   |   \n                  \\______  /\\____/|___|  /__| |__|___|  /____/  \\___  >___|   \n                         \\/            \\/             \\/            \\/<___>   \n\n\n\n\n\n\n\n\n                   __                        __       __                 __   \n                  / /  ___.__. ____   ______ \\ \\     / /   ____   ____   \\ \\  \n                 / /  <   |  |/ __ \\ /  ___/  \\ \\   / /   /    \\ /  _ \\   \\ \\ \n                 \\ \\   \\___  \\  ___/ \\___ \\   / /   \\ \\  |   |  (  <_> )  / / \n                  \\_\\  / ____|\\___  >____  > /_/     \\_\\ |___|  /\\____/  /_/  \n                       \\/         \\/     \\/                   \\/              \n\n\n";
    const std::string input_boarder = "\n\n===============================================================================================";
    const std::string p1_wins_message = "\n\n                       __________.__                     __________     \n                       \\______   \\  | _____  ___.__. ____\\______   \\    \n                       |     ___/  | \\__  \\<   |  |/ __ \\|       _/    \n                       |    |   |  |__/ __ \\___  \\  ___/|    |   \\    \n                       |____|   |____(____  / ____|\\___  >____|_  /    \n                                          \\/\\/         \\/       \\/     \n                                                                       \n                                   ____   ____   ____                  \n                                  /  _ \\ /    \\_/ __ \\                 \n                                 (  <_> )   |  \\  ___/                 \n                                  \\____/|___|  /\\___  >                \n                                             \\/     \\/                 \n\n\n\n\n\n                          __      __.___ _______    _________._.       \n                         /  \\    /  \\   |\\      \\  /   _____/| |       \n                         \\   \\/\\/   /   |/   |   \\ \\_____  \\ | |       \n                          \\        /|   /    |    \\/        \\ \\|       \n                           \\__/\\  / |___\\____|__  /_______  / __       \n                                \\/              \\/        \\/  \\/       \n";
    const std::string p2_wins_message = "\n\n                       __________.__                     __________     \n                       \\______   \\  | _____  ___.__. ____\\______   \\    \n                        |     ___/  | \\__  \\<   |  |/ __ \\|       _/    \n                        |    |   |  |__/ __ \\___  \\  ___/|    |   \\    \n                        |____|   |____(____  / ____|\\___  >____|_  /    \n                                           \\/\\/         \\/       \\/     \n                                    __                                  \n                                  _/  |___  _  ______                   \n                                  \\   __\\ \\/ \\/ /  _ \\                  \n                                   |  |  \\     (  <_> )                 \n                                   |__|   \\/\\_/ \\____/                  \n\n\n\n\n\n\n                           __      __.___ _______    _________._.       \n                          /  \\    /  \\   |\\      \\  /   _____/| |       \n                          \\   \\/\\/   /   |/   |   \\ \\_____  \\ | |       \n                           \\        /|   /    |    \\/        \\ \\|       \n                            \\__/\\  / |___\\____|__  /_______  / __       \n                                 \\/              \\/        \\/  \\/       \n";
    const std::string exit_message = "\n\n\n\n              ___________.__                   __     _____.___.              \n              \\__    ___/|  |__ _____    ____ |  | __ \\__  |   | ____  __ __  \n                |    |   |  |  \\__  \\  /    \\|  |/ /  /   |   |/  _ \\|  |  \\ \n                |    |   |   Y  \\/ __ \\|   |  \\    <   \\____   (  <_> )  |  / \n                |____|   |___|  (____  /___|  /__|_ \\  / ______|\\____/|____/  \n                              \\/     \\/     \\/     \\/  \\/                     \n\n                                   _____                                      \n                                 _/ ____\\___________                          \n                                 \\   __\\/  _ \\_  __ \\                         \n                                  |  | (  <_> )  | \\/                         \n                                  |__|  \\____/|__|                            \n\n                             .__                .__                           \n                      ______ |  | _____  ___.__.|__| ____    ____             \n                      \\____ \\|  | \\__  \\<   |  ||  |/    \\  / ___\\            \n                      |  |_> >  |__/ __ \\___  ||  |   |  \\/ /_/  >           \n                      |   __/|____(____  / ____||__|___|  /\\___  /            \n                      |__|             \\/\\/             \\//_____/             \n\n\n";
    const std::string tie_message = "\n\n\n\n\n\n\n\n\n\n                           ________               __      __ \n                           \\______ \\____________ /  \\    /  \\\n                            |    |  \\_  __ \\__  \\\\   \\/\\/   /\n                            |    `   \\  | \\// __ \\\\        / \n                           /_______  /__|  (____  /\\__/\\  /  \n                                   \\/           \\/      \\/   \n\n\n\n\n\n\n\n\n\n";

    // Game Board
    const std::string board_left_side = "                             | |   ";
    const std::string board_right_side = "   | |";
    const std::string board_ns_divider = "   |   ";
    const std::string board_ew_divider = "                             | |          |          |          | |\n                             | +----------+----------+----------+ |\n                             | |          |          |          | |\n";
    const std::string board_top = "\n\n\n                             +------------------------------------+\n                             | +--------------------------------+ |\n                             | |          |          |          | |\n";
    const std::string board_bottom = "                             | |          |          |          | |\n                             | +--------------------------------+ |\n                             +------------------------------------+\n\n\n";

    public:
    void clear()
        {
            COORD topLeft = { 0, 0 };
            HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO screen;
            DWORD written;

            GetConsoleScreenBufferInfo(console, &screen);
            FillConsoleOutputCharacterA(
                console, ' ', screen.dwSize.X *screen.dwSize.Y, topLeft, &written
        );
            FillConsoleOutputAttribute(
                console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
                screen.dwSize.X *screen.dwSize.Y, topLeft, &written
        );
            SetConsoleCursorPosition(console, topLeft);
        }

    void draw_board(std::vector<std::vector < char>> &game_state)
    {
        std::cout << board_top;

        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                if (y % 3 == 0)
                {
                    std::cout << board_left_side;
                }

                std::cout << std::string(4, game_state[x % 3][y % 3]);

                if ((y + 1) % 3 == 0)
                {
                    std::cout << board_right_side << "\n";
                }
                else
                {
                    std::cout << board_ns_divider;
                }
            }

            if (x > 1)
            {
                break;
            }

            std::cout << board_ew_divider;

        }

        std::cout << board_bottom;

    }


    void draw_welcome_message()
    {
        clear();
        std::cout << input_boarder << "\n";
        std::cout << welcome_message << "\n";
        std::cout << input_boarder << "\n";
    }

    void draw_continue_message()
    {
        clear();
        std::cout << input_boarder << "\n";
        std::cout << continue_message << "\n";
        std::cout << input_boarder << "\n";
    }

    void draw_input_boarder()
    {
        std::cout << input_boarder << "\n";
    }

    void draw_p1_wins_message()
    {
        clear();
        std::cout << input_boarder << "\n";
        std::cout << p1_wins_message << "\n";
        std::cout << input_boarder << "\n";
    }

    void draw_p2_wins_message()
    {
        clear();
        std::cout << input_boarder << "\n";
        std::cout << p2_wins_message << "\n";
        std::cout << input_boarder << "\n";
    }

    void draw_tie_message()
    {
        clear();
        std::cout << input_boarder << "\n";
        std::cout << tie_message << "\n";
        std::cout << input_boarder << "\n";
    }

    void draw_exit_message()
    {
        clear();
        std::cout << input_boarder << "\n";
        std::cout << exit_message << "\n";
        std::cout << input_boarder << "\n";
    }
};
