//minesweepers competitive mode by AmirReza Ramesh
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

//variables
const int SIZE = 16; //size of board
const int MINES = 40; // number of bombs
string player1, player2; // string for names of players
int scores[2] = {0, 0}; // scores of each player
int currentPlayer = 0; // during the game determines the current player
char currentCell[SIZE][SIZE]; // the cell being focused on in loops for revealing or flagging and...
bool alreadyRevealed[SIZE][SIZE];// to show if a cell is already revealed
bool alreadyFlagged [SIZE][SIZE]; // to show if a cell is already flagged

//functions
void rules(); // states the rules
void documents(); //explaining the idea of project
int menu(); // the menu with options of : start, rules , document and exit
void createBoard();// creating the board and placing mines
void openCell(int, int); // revealing a cell and its neighbor cells if needed
void putFlag(int, int);// flagging a cell considered to contain bomb
bool gameEnd();//checking if all the cells are either revealed or flagged to end the game
void gameStart();//main function of printing the board and making the turns

int main() {
    bool start = menu();
    if (start){
        cout << "pls enter your names: \n";
        cout << "player1 : ";
        cin >> player1;
        cout << "player2 : ";
        cin >> player2;
        system("cls");
        createBoard();

        while (true) {
            gameStart();
    }}
    else{
        cout << "good choice^^ see ya later";
    }
    return 0;
}

void rules(){
   system("cls");

    cout <<"                     THE RULES: \n ";
    cout << "===================================================\n \n";
    cout << "The game is very simple. lets review the rules step by step \n \n";
    cout << "1.There are 2 kinds of cells. some include bombs and some are safe \n \n";
    cout << "2.Players take turns and choose to either open a cell they consider safe \n";
    cout << "or put a flag as defusion of a cell they believe it contains a bomb \n\n";
    cout << "3.After opening a safe cell, it shows how many bombs are around it \n\n";
    cout << "4.Input for revealing a cell : i j r , input for flagging : i j f \n ";
    cout << "opening safe cell = 5 pts   defusing a bomb / flaging = 10 pts  \n";
    cout << " defusing a safe cell = 0 pts  Exploding = -10 pts and \n";
    cout << "5.The goal is to have more points than the opponent \n";
    cout << "at the end of the match which is when all the bombs are found \n";
    cout << "or when a player hits the bomb \n \n";
    cout << "6.Note that the board is 16 * 16 and has 40 bombs so be CAREFULL! \n \n";
    cout << "ENJOY! \n";

    cout<< "1.start the game \n";
    cout << "3.see documents \n";
    cout << "4.exit and think about your future \n\n";

    cout << "enter 1, 3 or 4 to continue \n";

}

void documents(){
   system("cls");


    cout << "              about the PROJECT \n";
    cout << "==================================================== \n \n";

    cout <<"Hey there!this project is programmed by me, the one and only Amir Ramesh XD \n\n";
    cout <<"this project is coded for my cpp course held by t.me/sbu_robotic_club \n\n";
    cout << "Its only fair to say I stole the idea of competitive minesweepers from plato app \n";
    cout << "and I'm proud of this daylight robbery ^^ \n\n";
    cout << "The game is an online competitive mode where\n";
    cout << "you match with random people and play live \n\n";
    cout << "Originally the game doesn't contain separate turns and\n";
    cout << "both players make their moves in a limited time \n\n";
    cout << "and the cool part would be the speed bonus\n";
    cout <<"which was not possible due to limitations of project\n\n";
    cout <<"thank you and I hope you enjoy the game <3 \n\n";

    cout <<"1.start the game \n";
    cout <<"3.see documents \n";
    cout <<"4.exit and do something more useful \n";


    cout << "enter 1, 2 or 4 to continue \n";

}

int menu(){

    int menu;
    cout<<" welcome to the minesweepers' competitive mode \n \n ";
    cout<< "=========================================== \n \n";
    cout<< "1.start the game \n";
    cout<< "2.learn the rules(recommended if you're new to two-player-minesweepers) \n";
    cout<< "3.see the documents \n";
    cout<< "4.exit and go study for lessons \n";

    do {
    cin >> menu;

    switch(menu)
    {
    case 1 :
        {
            return 1;
        }
    case 2 :
        {
             rules();
            break;
        }
    case 3:
        {
           documents();
            break;

        }
    case 4:
        {
            return 0;
        }
    default :
        {
            cout << "enter a valid number shown in menu above \n";
        }
    }
    } while (menu != 4 || menu != 1);

    return 0;

}

void createBoard() {
    srand(time(0));

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            currentCell[i][j] = ' ';
            alreadyRevealed[i][j] = false;
            alreadyFlagged[i][j] = false;
        }
    }

    //placing mines on the board using rand function
    for (int m = 0; m < MINES; ++m) {
        int row, col;
        do {
            row = rand() % SIZE;
            col = rand() % SIZE;
        } while (currentCell[row][col] == '*');

        currentCell[row][col] = '*';
    }

    // re-checking other cells to update the count
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (currentCell[i][j] == '*') {
                continue;
            }

            int counter = 0;

            // Check all eight neighboring cells
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    int newRow = i + x;
                    int newCol = j + y;

                    if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE && currentCell[newRow][newCol] == '*') {
                        ++counter;
                    }
                }
            }

            // Update the cell with mine count
            if (counter > 0) {
                currentCell[i][j] = counter + '0';
            }
        }
    }
}

void openCell(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || alreadyRevealed[row][col] || alreadyFlagged[row][col]) {
        return;
    }

    alreadyRevealed[row][col] = true;

    if (currentCell[row][col] == ' ') {
        // Auto-reveal neighboring cells if the selected cell is empty
        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                openCell(row + x, col + y);
            }
        }
    }
}

void putFlag(int row, int col) {

        alreadyFlagged[row][col] = !alreadyFlagged[row][col];
}

bool gameEnd() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (currentCell[i][j] != '*' && (!alreadyRevealed[i][j] || alreadyFlagged[i][j])) {
                return false;
            }
        }
    }
    return true;
}

void gameStart() {
    system("cls");
    cout << "   ";
    for (int i = 0; i < SIZE; ++i) {
        //for numbers less than 10 since they have one less digit i considered more space so board is well shaped
        cout << (i < 10 ? " " : "") << i << " ";
    }
    cout << "\n";

    for (int i = 0; i < SIZE; ++i) {
        cout << (i < 10 ? " " : "") << i << " ";

        for (int j = 0; j < SIZE; ++j) {
            if (alreadyFlagged[i][j]) {
                cout << " F ";
            } else if (alreadyRevealed[i][j]) {
                if (currentCell[i][j] == '*') {
                    cout << " * ";
                } else {
                    cout << " " << currentCell[i][j] << " ";
                }
            } else {
                cout << " - ";
            }
        }
        cout << "\n";
    }

    cout << player1<< "'s score: " << scores[0] << "\n";
    cout << player2 << "'s score: " << scores[1] << "\n";
    int row, col;
    char action;
    cout << "input format: 'row'  'col'  'r'or'f' \n";
    if(currentPlayer == 0)
        cout << player1 <<"'s turn: ";
    else
        cout << player2 << "'s turn: ";

    //cin and checking the invalid input
    while (!(cin >> row >> col >> action) || row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        cin.clear(); // Clear the error flag
        while (cin.get() != '\n'); // Discard invalid input
        cout << "pls enter a valid input considering the mentioned format:  ";
    }

    if (action == 'R' || action == 'r') {
        if (currentCell[row][col] == '*') {
            cout << "game over! player " << currentPlayer + 1 << " opened a cell with bomb.\n";
            scores[currentPlayer] -= 10;
            cout << player1 << "'s final score: " << scores[0] << "\n";
            cout << player2 << "'s final score: " << scores[1] << "\n";

            if (scores[0] > scores[1])
                cout << player1 << " wins!";
            else if ( scores[0] == scores[1])
                cout << "its a draw... you both win!";
            else
                cout << player2 << " wins!";
            exit(0);
        }

        openCell(row, col);

        if (gameEnd()) {
            //when all cells are revealed, flagged(no empty cells left) the game is finished with both players surviving
            cout << "Congratulations! Both players survived!\n";
                    cout << player1 << "'s final score: " << scores[0] << "\n";
            cout << player2 << "'s final score: " << scores[1] << "\n";

            if (scores[0] > scores[1])
                cout << player1 << " wins!";
            else if ( scores[0] == scores[1])
                cout << "its a draw... you both win!";
            else
                cout << player2 << " wins!";
            exit(0);
        }

        scores[currentPlayer] += 5;
    } else if (action == 'F' || action == 'f') {
        putFlag(row, col);

        if (currentCell[row][col] == '*' && alreadyFlagged[row][col]) {
            scores[currentPlayer] += 10;
        }
    } else {
        cout << "wrong input. try again! \n";
        exit(0);
    }

    // Switching the player
    currentPlayer = 1 - currentPlayer;
}
