#include <iostream>
#include<string>
using namespace std;
#include "game.hpp"

string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;

void introduction() {

        cout << "Press [Enter] to begin: ";
        cin.ignore();

        cout << "\n";

        cout << "===========\n";
        cout << "Tic-Tac-Toe\n";
        cout << "===========\n\n";
  
        cout << "Player 1) ✖\n";
        cout << "Player 2) ⊙\n\n";

        cout << "Here's the 3 x 3 grid:\n\n";

        cout << "     |     |      \n";
        cout << "  1  |  2  |  3   \n";
        cout << "_____|_____|_____ \n";
        cout << "     |     |      \n";
        cout << "  4  |  5  |  6   \n";
        cout << "_____|_____|_____ \n";
        cout << "     |     |      \n";
        cout << "  7  |  8  |  9   \n";
        cout << "     |     |      \n\n";

}

bool is_winner() {

  bool winner = false;
  // rows
  if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ") {
    winner = true;
  } else if ((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ") {
    winner = true;
  } else if ((board[6] == board[7]) && (board[6] == board[8]) && board[6] != " ") {
    winner = true;
  } 
  // columns
  else if ((board[0] == board[3]) && (board[0] == board[6]) && board[0] != " ") {
    winner = true;
  } else if ((board[1] == board[4]) && (board[1] == board[7]) && board[1] != " ") {
    winner = true;
  } else if ((board[2] == board[5]) && (board[2] == board[8]) && board[2] != " ") {
    winner = true;
  } // diagonals
  else if ((board[0] == board[4]) && (board[0] == board[8]) && board[0] != " ") {
    winner = true;
  }
  else if ((board[2] == board[4]) && (board[2] == board[6]) && board[2] != " ") {
    winner = true;
  }

  return winner;

}

bool filled_up() {

  bool filled = true;

  for (int i = 0; i < 9; i++) {

    if (board[i] == " ") {

      filled = false;

    }

  }

  return filled;

}
void draw() {

        cout << "     |     |      \n";

        cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

        cout << "_____|_____|_____ \n";
        cout << "     |     |      \n";

        cout << "  "<< board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

        cout << "_____|_____|_____ \n";
        cout << "     |     |      \n";

        cout << "  "<< board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
        cout << "     |     |      \n";

        cout << "\n";
    
}

void set_position() {

        cout << "Player " << player << "'s Turn (Enter 1-9): ";

  while (!(      cin >> position)) {

          cout << "Player " << player << ", please enter a valid number between 1 and 9: ";
          cin.clear();
          cin.ignore();

  }
  
        cout << "\n";

  while (board[position-1] != " ") {

          cout << "Oops, there's already something in that position!\n\n";

          cout << "Player " << player << "'s Turn (Enter 1-9): ";
          cin >> position;

          cout << "\n";
  }

}

void update_board() {

  if (player % 2 == 1) {

    board[position-1] = "✖";

  } else {

    board[position-1] = "⊙";

  }

}

void change_player() {

  if (player == 1) {

    player++;

  } else {
  
    player--;
  
  }

}

void take_turn() {

  while ( !is_winner() && !filled_up() ) {
  
    set_position();

    update_board();

    change_player();

    draw();
  
  }

}

void end_game() {

  if (is_winner()) {
          cout << "There's a winner!\n";
  }
  else if (filled_up()) {
          cout << "There's a tie!\n";
  }

}

int main() {

  introduction();
  
  take_turn();

  end_game();
    
}