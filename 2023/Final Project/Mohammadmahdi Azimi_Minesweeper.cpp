/* This code is a poor attempt at trying to play "Minesweeper" on the 
windows terminal. It isn't the best way to play minesweeper, if not the worst.
Also as a disclaimer, I have used colored outputs in this program, so that some texts 
appear to be colored. This was done using ANSI sequences, so it might not work on some 
devices. But all in all, I hope this silly little game finds you well! :>

- Mohammadmahdi Azimi, Fall 1402.

** The ASCII art used in the main menu in this program is generated using the "Text to ASCII 
art generator" app of the following website; I do not hold any right to the used text art.
    https://patorjk.com/

_________________________________________________________________________________ */

#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int GRID_SIZE_ROW=16;   // Table width.
int GRID_SIZE_COL=16;   // Table height.
int NUMBER_OF_BOMBS=40;


/* "realTable" is the table that holds the location of bombs, and
is not shown to the player. Each entry of "realTable" will hold 
either -1 (bomb) or the number of adjacent bombs.

"playersTable" is the table that the player gradually reveals. 
Each house in this table holds either 1 (revealed), 0 (not revealed) 
or -1 (a house "flagged" by the player). These arrays will be used by almost
all of the functions, so they are declared globally. */

int realTable[20][20]={0};
int playersTable[20][20]={0};


// Declare used functions.

void initTable();                   // Initializes the table with bombs and numbers.
bool isValidHouse(int, int);        // Returns whether a given set of coordinates exists in the table.
void mainMenuBegin();               // Main menu of the game.
void printTable();                  // Prints the game table at any given iteration.
void printTutorial();               // Walks the player through the tutorial.
void setDiff();                     // Adjusts the number of bombs and the size of the grid.
void playGame();                    // Interacts with the player throughout the game.
bool hasWon();                      // Checks if the player has won the game after an input.
void updatePlayersTable(int, int);  // Updates "playersTable" array.


int main() {

    srand(time(0));

    // Fake 5 second loading screen.

    cout << "Make sure to play in fullscreen!" << endl;
    cout << endl << endl << "\t\t\t\033[38;5;47mLoading";
    for (int i=0; i<5; ++i) {
        cout << ".";
        sleep(1);
    }

    mainMenuBegin();
}   


bool isValidHouse(int row, int column) {
    // This function simply checks if a given set of coordinates is in the playing table or not.

    if (row>=0 && row<GRID_SIZE_ROW && column>=0 && column<GRID_SIZE_COL)
        return true;
    else 
        return false;
}


void initTable() {
    /* This function will initialize the table with bombs (-1) and empty (non-bomb) 
    houses. If a house isn't allocated to a bomb, it will assign the number of adjacent
    bombs to that house. */

    // Initialze both arrays with zeros.

    for (int row=0; row<20; ++row) {
        for (int column=0; column<20; ++column) {
            realTable[row][column]=0;
            playersTable[row][column]=0;
        }
    }

    // Randomly allocate NUMBER_OF_BOMBS bombs inside the squares.

    for (int count=0; count<NUMBER_OF_BOMBS; ++count) {
        int row=rand()%GRID_SIZE_ROW, column=rand()%GRID_SIZE_COL;
        if (realTable[row][column]!=-1) {       
            realTable[row][column]=-1;
        } else {       // Else, recount the iteration.
            --count;
        }
    }

    // If a house doesn't hold a bomb (-1), determine the number it holds.
    
    for (int row=0; row<GRID_SIZE_ROW; ++row) {
        for (int column=0; column<GRID_SIZE_COL; ++column) {

            // Skip if there is a bomb (since the number -1 is already assigned to that house).

            if (realTable[row][column]!=-1) {
                int adjBombs=0;

                // Loop through the 8 *VALID* houses around that house, searching for bombs.

                for (int i=-1; i<=1; ++i) {
                    for (int j=-1; j<=1; ++j) {
                        if (isValidHouse(row+i, column+j) && realTable[row+i][column+j]==-1) {
                            ++adjBombs;
                        }
                    }
                }

                realTable[row][column]=adjBombs;    // Update house entry.
            }
        }
    }
}


// LET THE GAME BEGIN.

void playGame() {
    /* This function will keep interacting with the player, inputting the 
    next move the player wishes to make. Then, it updates the coresponding 
    houses and passes it to another function to print. */

    printTable();
    int moveRow, moveColumn;

    cout << endl << endl << "\033[0mEnter the row you want to choose: ";
    cin >> moveRow;

    // If an unexpected input is given...

    if (cin.fail()) {
    cout << endl << "Invalid input." << endl;
    cin.clear();
    cin.ignore(100, '\n');
    sleep(2);
    playGame();
    }

    cout << "Enter the column you want to choose: ";
    cin >> moveColumn;

    // If an unexpected input is given...

    if (cin.fail()) {
    cout << endl << "Invalid input." << endl;
    cin.clear();
    cin.ignore(100, '\n');
    sleep(2);
    playGame();
    }

    --moveRow;
    --moveColumn;

    if (!isValidHouse(moveRow, moveColumn)) {
        cout << "Invalid input." << endl;
        sleep(2);
        playGame();
    }

    char choice;
    cout << "Press \"f\" to flag the house, or press \"r\" to reveal the house." << endl;
    choice=getch();

    // We make sure that a revealed house isn't flagged later.

    if ((choice=='f' || choice=='F') && playersTable[moveRow][moveColumn]!=1) {
        if (playersTable[moveRow][moveColumn]==-1) {    // If the house is flagged, un-flag it.
            playersTable[moveRow][moveColumn]=0;
        } else {
            playersTable[moveRow][moveColumn]=-1;
        }
        
        playGame();
    } else if (choice=='r' || choice=='R') {

        // If a bomb is chosen, reveal all the bombs and go back to the main menu.

        if (realTable[moveRow][moveColumn]==-1) {   
            for (int row=0; row<GRID_SIZE_ROW; ++row) {
                for (int column=0; column<GRID_SIZE_COL; ++column) {
                    if (realTable[row][column]==-1) {
                        playersTable[row][column]=1;    // Reveal all bombs.
                    }
                }
            }

            printTable();
            cout << endl << endl << "\033[38;5;196mYOU'VE LOST! \033[38;5;154m"     // Poor player :(
            << "Good try though :)\033[0m"      
            << endl << endl << "Press any key to continue... ";

            getch();
            mainMenuBegin();
        } else {
            updatePlayersTable(moveRow, moveColumn);

            // If the player has won...

            if (hasWon()) {
                for (int row=0; row<GRID_SIZE_ROW; ++row) {
                    for (int column=0; column<GRID_SIZE_COL; ++column) {
                        playersTable[row][column]=1;    // Reveal all houses.
                    }
                }

                printTable();
                cout << endl << endl << "\033[38;5;154mYOU'VE WON! :D\033[0m"
                << endl << endl << "Press any key to continue... ";

                getch();
                mainMenuBegin();

            }
        }
            
        playGame();
    } else {
        cout << endl << "Invalid input." << endl;
        sleep(2);
        playGame();
    }
}


void updatePlayersTable(int row, int column) {
    /* This function updates the "playersTable" array. If the chosen house holds a number, this function
    simply displays that number (sets the coresponding house entry equal to 1). But if the house holds 0,
    meaning that all houses around that house are empty, it collapses the table and reveals all empty houses 
    starting from that house, until it reaches a boundary of numbers. This function is written recursively. */

    if (realTable[row][column]!=0 && realTable[row][column]!=-1) {    // Simply display the number if we hit a number.
        playersTable[row][column]=1;
        return;
    } else if (realTable[row][column]==0) {     // Else, collapse the board until we hit a number.

        playersTable[row][column]=1;

        // Loop around the 8 houses near that house.

        for (int i=-1; i<=1; ++i) {
            for (int j=-1; j<=1; ++j) {
                if (i==0 && j==0) continue;     // Do not count the house itself.

                // If the house is in the grid, and hasn't been revealed yet, update it.

                if (isValidHouse(row+i, column+j) && playersTable[row+i][column+j]!=1) {
                    updatePlayersTable(row+i, column+j);
                }
            }
        }
    }

    return;
}


bool hasWon() {
    /* This function checks if the player has won the game, meaning if they have revealed all of 
    the non-bomb houses. */

    for (int row=0; row<GRID_SIZE_ROW; ++row) {
        for (int column=0; column<GRID_SIZE_COL; ++column) {

            /* If there's a house that doesn't hold a bomb and isn't revealed, return false.
            If there's no such house, return true. */

            if (realTable[row][column]!=-1 && playersTable[row][column]!=1) {   
                return false;
            }
        }
    }

    return true;
}


void setDiff() {
    // This function changes the size of the board and the number of bombs as the player desires.

    // Print a simple menu to choose from.

    system("CLS");
    cout << "Choose the difficulty you'd like to play in." << endl
    <<"\033[38;5;216m(Current difficulty:\t" << GRID_SIZE_ROW << "x" << GRID_SIZE_COL << " Grid - " << NUMBER_OF_BOMBS << " Bombs)\033[0m" << endl

    << endl <<  "   1.\t\033[38;5;46mBeginner\t\t(9x9 Grid - 10 Bombs)\033[0m"
    << endl <<  "   2.\t\033[38;5;9mIntermediate\t\t(16x16 Grid - 40 Bombs)\033[0m"
    << endl <<  "   3.\t\033[38;5;33mCustom!\033[0m"
    
    << endl << endl;

    char choice;
    choice=getch();

    if (choice=='1') {
        GRID_SIZE_ROW=9;
        GRID_SIZE_COL=9;
        NUMBER_OF_BOMBS=10;
    } else if (choice=='2') {
        GRID_SIZE_ROW=16;
        GRID_SIZE_COL=16;
        NUMBER_OF_BOMBS=40;
    } else if (choice=='3') {   // If they choose to go the custom route...
        int customGridSizeRow, customGridSizeCol, customNumberOfBombs;

        cout << endl << "Enter the grid height: ";
        cin >> customGridSizeRow;

        // If an unexpected input is given...

        if (cin.fail()) {
            cout << endl << "Invalid input." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            sleep(2);
            setDiff();
        }

        cout << endl << "Enter the grid width: ";
        cin >> customGridSizeCol;

        if (cin.fail()) {
            cout << endl << "Invalid input." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            sleep(2);
            setDiff();
        }

        // If the custom grid is between 1x1 and 20x20, apply changes. Else, load the "Change difficulty" menu again.

        if (!(customGridSizeRow>0 && customGridSizeRow<=20 && customGridSizeCol>0 && customGridSizeCol<=20)) {
            cout << endl << "The grid side length has to be between 1 and 20." << endl;
            sleep(2);
            setDiff();
        }

        cout << endl << "Enter the number of bombs: ";
        cin >> customNumberOfBombs;

        // If an unexpected input is given...

        if (cin.fail()) {
            cout << endl << "Invalid input." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            sleep(2);
            setDiff();
        }

        if (!(customNumberOfBombs>=0 && customNumberOfBombs<GRID_SIZE_ROW*GRID_SIZE_COL)) {
            cout << endl << "Invalid number of bombs." << endl;
            sleep(2);
            setDiff();
        } 

        GRID_SIZE_ROW=customGridSizeRow;
        GRID_SIZE_COL=customGridSizeCol;
        NUMBER_OF_BOMBS=customNumberOfBombs;

    } else { // If the input wasn't among the options, load the menu again.
        cout << endl << "Invalid input" << endl;
        sleep(2);
        setDiff();
    }
    
    cout << endl << "Difficulty updated successfuly!";
    sleep(2);
    mainMenuBegin();
}


void mainMenuBegin() {
    /* This function prints the main menu of the game. That's all. */
    
    system("CLS");

    // Print "MINE SWEEPER" ASCII art. 
    // ** FONT: Merlin1 **

    cout    <<  "\033[38;5;160m ___      ___   __    _____  ___    _______       \033[38;5;33m________  __   __  ___   _______   _______    _______    _______   _______  "
    << endl <<  "\033[38;5;160m|\"  \\    /\"  | |\" \\  (\\\"   \\|\"  \\  /\"     \"|     \033[38;5;33m/\"       )|\"  |/  \\|  \"| /\"     \"| /\"     \"|  |   __ \"\\  /\"     \"| /\"  _   \\ "
    << endl <<  "\033[38;5;160m \\   \\  //   | ||  | |.\\    \\    |(: ______)    \033[38;5;33m(:   \\___/ |'  /    \\:  |(: ______)(: ______)  (. |__) :)(: ______)|: /  \\  | "
    << endl <<  "\033[38;5;160m  \\  \\/.     | |:  | |: \\.   \\   | \\/    |       \033[38;5;33m\\___  \\   |: /'        | \\/    |   \\/    |    |:  ____/  \\/    |  |_____/  ) "
    << endl <<  "\033[38;5;160m|: \\.        | |.  | |.  \\    \\. | /  ___)_       \033[38;5;33m__/   \\   \\/   /\\'    | /  ___)_  /  ___)_   (|  /      /  ___)_  //     /  "
    << endl <<  "\033[38;5;160m|.  \\    /:  | /\\  |\\|    \\    \\ |(:      \"|     \033[38;5;33m/\" \\   :)  /   /  \\    |(:      \"|(:      \"| /|__/ \\    (:      \"||:  __  \\  "
    << endl <<  "\033[38;5;160m|___|\\__/|___|(__\\_|_)\\___|\\____\\) \\_______)    \033[38;5;33m(_______/  |___/    \\___| \\_______) \\_______)(_______)    \\_______)|__|  \\__) "
    << endl << endl << "\033[38;5;244m\t\t\t\t\t\t\t\t\t\t\t\t\t\tBy M. Azimi\033[0m" << endl << endl;

    // Print main menu options.

    cout << "Choose a number to proceed." << endl
    << endl <<  "   1.\tStart new game"
    << endl <<  "   2.\tTutorial"
    << endl <<  "   3.\tChange difficulty"
    << endl <<  "   4.\tExit game"
    << endl << endl;

    char choice=getch();
    
    if (choice=='1') {
        initTable();
        playGame();
    } else if (choice=='2') {
        printTutorial();
    } else if (choice=='3') {
        setDiff();
    } else if (choice=='4') {
        system("CLS");
        cout << "See you next time, fellow \033[38;5;33msweeper :)\033[0m";
        sleep(4);
        exit(0);
    } else {
        cout << "Invalid input." << endl;
        sleep(2);
        mainMenuBegin();
    }

}


void printTable() {
    /* This function prints the revealed table at any given step. Everyhing is 
    color coded to improve the readability of the table. */

    system("CLS");

    // Print the number of rows at the top first.

    cout << "\t";
    for (int i=1; i<=GRID_SIZE_COL; ++i) {
        cout << i;

        /* Space into the next house, space one less if the number is two digits since if not, the coresponding
        row will be shifted and unaligned. */

        if (i<9) {
            cout << "   ";
        } else {
            cout << "  ";
        }
    }

    cout << endl << endl << endl << endl;

    /* Print the rows, and the houses. Each non-revealed house will be background-colored gray (ANSI code 246).
    For each revealed house, the background will be a slightly darker gray (ANSI code 235), and the foreground
    ANSI color codes will be as follows:

    0: No color     1: 39
    2: 118          3: 220
    4: 203          5: 160
    6: 213          7: 106
    8: 126
            
    Flagged houses will hold the symbol "?" with backgroud ANSI code 214 and foreground ANSI code 232.
    Bombs will be background-colored 196 and foreground-colored 232 with symbol "@". */

    for (int i=1; i<=GRID_SIZE_ROW; ++i) {
        cout << i << "\t";

        for (int j=1; j<=GRID_SIZE_COL; ++j) {
            if (playersTable[i-1][j-1]==0) {    // If the house isn't yet revealed...
                cout << "\033[48;5;246m ";
            } else if (playersTable[i-1][j-1]==-1) {    // If the house is flagged...
                cout << "\033[48;5;214m\033[38;5;232m?";
            } else if (playersTable[i-1][j-1]==1) {     // If the house is revealed...

                cout << "\033[48;5;235m";   // Revealed houses background color (except for bombs).

                switch (realTable[i-1][j-1]) {
                    case -1:
                        cout << "\033[48;5;196m\033[38;5;232m@";
                        break;
                    case 0:
                        cout << " ";
                        break;
                    case 1:
                        cout << "\033[38;5;39m1";
                        break;
                    case 2:
                        cout << "\033[38;5;118m2";
                        break;
                    case 3:
                        cout << "\033[38;5;220m3";
                        break;
                    case 4:
                        cout << "\033[38;5;203m4";
                        break;
                    case 5:
                        cout << "\033[38;5;160m5";
                        break;
                    case 6:
                        cout << "\033[38;5;213m6";
                        break;
                    case 7:
                        cout << "\033[38;5;106m7";
                        break;
                    case 8:
                        cout << "\033[38;5;126m8";
                }
            }

            cout << "\033[0m";      // Change color back to default.
                
            // Space into the next house.

            cout << "   ";
        }

        // Go to the next row.

        cout << endl << endl;
    }

    // Print a long line, the size of the displayed table.

    for (int i=0; i<GRID_SIZE_ROW*4+6; ++i) {
    cout << "_";
    }
}


void printTutorial() {
    /* This function prints the tutorial on how to play this game. */

    system("CLS");
    cout << "\033[38;5;160m";

    const string bullying=
    "Y o u  r e a l l y  d o n ' t  k n o w  h o w  t o  p l a y  M i n e  S w e e p e r  i n  2 0 2 3 ?";

    const int sizeOfBullying=99;


    for (int i=0; i<sizeOfBullying; ++i) {
        cout << bullying[i];
        this_thread::sleep_for(chrono::milliseconds(30));   // Another sleep function was used because we needed a shorter sleep time than sleep().
    }

    sleep(3);
    cout << endl << endl << "\033[0mSigh. Press any key to continue.";

    getch();

    mainMenuBegin();

}
