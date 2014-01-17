#include <iostream>
#include <string>
#include <windows.h>
class Player {
public:
    std::string Cards[2];
    float Money;
    Player() {
        Cards[0] = ""; // Reset Cards
        Cards[1] = "";
        Money = 100.0; // Reset Money
    }
};

class Pot {
public:
    std::string Cards[5];
    float Money;
    Pot(){
        Cards[0] = ""; // Reset Cards
        Cards[1] = "";
        Cards[2] = "";
        Cards[3] = "";
        Cards[4] = "";
        Money = 0.0; // Reset Money
    }
};
void ClearScreen() {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }
int main()
{
    // Set up Players/Pot
    Player Plyr1, Plyr2;
    Pot ThePot;
    // Backend variables
    int Opt = 0;
    int OOpt = 0;
    while(true) {
        ClearScreen();
        std::cout << "Welcome to Texas Hold'em!\n"; // Main Menu
        std::cout << "[1] Play Game\n";
        std::cout << "[2] Options\n";
        std::cout << "[3] Help\n";
        std::cout << "[4] Quit\n";
        std::cin >> Opt;
        if(Opt > 4) Opt = 4;
        if(Opt < 0) Opt = 0;
        if(Opt == 1) {
            ClearScreen();
            while(true) {
                std::string Deck[52][2] = {
                // Spades
                {"A|S", "false"},
                {"2|S", "false"},
                {"3|S", "false"},
                {"4|S", "false"},
                {"5|S", "false"},
                {"6|S", "false"},
                {"7|S", "false"},
                {"8|S", "false"},
                {"9|S", "false"},
                {"10|S", "false"},
                {"J|S", "false"},
                {"Q|S", "false"},
                {"K|S", "false"},
                // Hearts
                {"A|H", "false"},
                {"2|H", "false"},
                {"3|H", "false"},
                {"4|H", "false"},
                {"5|H", "false"},
                {"6|H", "false"},
                {"7|H", "false"},
                {"8|H", "false"},
                {"9|H", "false"},
                {"10|H", "false"},
                {"J|H", "false"},
                {"Q|H", "false"},
                {"K|H", "false"},
                // Diamonds
                {"A|D", "false"},
                {"2|D", "false"},
                {"3|D", "false"},
                {"4|D", "false"},
                {"5|D", "false"},
                {"6|D", "false"},
                {"7|D", "false"},
                {"8|D", "false"},
                {"9|D", "false"},
                {"10|D", "false"},
                {"J|D", "false"},
                {"Q|D", "false"},
                {"K|D", "false"},
                // Club
                {"A|c", "false"},
                {"2|C", "false"},
                {"3|C", "false"},
                {"4|C", "false"},
                {"5|C", "false"},
                {"6|C", "false"},
                {"7|C", "false"},
                {"8|C", "false"},
                {"9|C", "false"},
                {"10|C", "false"},
                {"J|C", "false"},
                {"Q|C", "false"},
                {"K|C", "false"}
                };
                std::cout << "[" << Deck[20][0] << "]";
            }
            // TODO: Play Game
        } else if(Opt == 2) {
            while(true){ //Options
                ClearScreen();
                std::cout << "Texas Holdem [Options]\n";
                std::cout << "[1] Set Starting amount of money\n";
                std::cout << "[2] Exit Menu\n";
                std::cin >> OOpt;
                if(OOpt > 2) OOpt = 2;
                if(OOpt < 0) OOpt = 0;
                if(OOpt == 1) {
                    // TODO: Set Starting Amount
                } else if(OOpt == 2) {
                    ClearScreen();
                    break;
                }
            }
        } else if(Opt == 3) { // Help Menu
            while(true) {
                ClearScreen();
                std::cout << "The game is Texas Holdem.\n";
                std::cout << "Be sure that you know how to play this game, if you do not, look at \nwww.texasholdem-poker.com/beginnersintro";
                std::cout << "\nThe cards are designed like so:\n";
                std::cout << "[8|H] 8 of Hearts\n";
                std::cout << "[8|C] 8 of Clubs\n";
                std::cout << "[8|S] 8 of Spades\n";
                std::cout << "[8|D] 8 of Diamonds\n";
                std::cout << "[J|H] Jack of Hearts\n";
                std::cout << "[Q|H] Queen of Hearts\n";
                std::cout << "[K|H] King of Hearts\n";
                std::cout << "Press any key to continue..";
                std::cin.ignore();
                std::cin.get();
                break;
            }
        } else if(Opt == 4) {
            break;
        }
    }
    return 0;
}
