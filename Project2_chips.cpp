/* Game of Chips */
//Audrey Clark Lab Time Tue @2pm

#include <iostream>
using namespace std;

int init_game(); 
int ask_move(bool, int);
bool is_move_legal(int, int); 
void declare_winner(bool);


int main() 
{ 
	bool player1turn = true; 
	bool game_over = false;
	
	int chips_in_pile = init_game();
	
	while (game_over == false) 
	{ 
	
		int chips_taken = ask_move(player1turn, chips_in_pile);		
		chips_in_pile = chips_in_pile - chips_taken;
		
		if (chips_in_pile == 0) 
		{ 
			game_over = true; 
			declare_winner(player1turn);
		}
		else 
		{ 
			cout << "There are " << chips_in_pile << " chips left." << endl << endl;
			player1turn = !player1turn; 
		}
	       
	} 
	
	return(0);
}



void declare_winner(bool player1turn)
{ 
  if (player1turn=true)
    {
      cout << "The Game is over. Congrats Player 1 won!" <<endl << endl;
    }
  if (player1turn=false)
    {
      cout << "The Game is over. Congrats Player 2 won!" <<endl  << endl;
    }
/*
  This function takes in the bool value player1turn. If player1turn is true for the last move of the game, player 1 is 
  the winner. If player1turn is false for the last move, player 2 is the winner of the game.
*/
}



bool is_move_legal(int chips_taken, int chips_in_pile) 
  { 
    bool legal;
    double max_take;
    max_take=chips_in_pile/2;
    if (chips_in_pile>2)
      {
        if (chips_taken>0 && chips_taken<=max_take)
	  {
	    legal=true;
	  }
	else
	  {
	    legal=false;
	  }
      }
    
    if (chips_in_pile<=2)
      {
	if (chips_taken==1)
	  {
	    legal=true;
	  }
	else
	  {
	    legal=false;
	  }
      }
    // cout << "Legal is " << legal << endl;
  return legal;
  /*
    This function uses the variables legal and max_take to test if the user-inputed move is legal. Two main if statements
    are to categorize the point in the game. The first if statement is when the chips_in_pile is still large (more than
    2). The second if statement is for the end of the program when the chips_in_pile is less than or equal to 2. The 
    variable max_take tests the chips_taken if it is more than the legal amount (more than half of the chips_in_pile)
    The bool variable, legal, is returned to ask_move to allow the program to continue.
   */
}


int ask_move(bool player1turn, int chips_in_pile)
{ 
  int chips_taken;
  bool legal; //the bool variable describing if the move is legal or not
  if (player1turn==true)
  {
    cout << "There are " << chips_in_pile << " chips in the pile. ";
    cout << "How many chips would Player 1 like to take this turn?" <<endl;
    cin >> chips_taken;
    legal = is_move_legal(chips_taken, chips_in_pile);
    while(legal==false)
      {
	cout << "That is not a legal move. Please take at least one and no more than half the total chips." <<endl;
	cin >> chips_taken;
	legal = is_move_legal(chips_taken, chips_in_pile);
      }
  }
  if (player1turn==false)
  {
    cout << "How many chips would Player 2 like to take this turn?" <<endl;
    cin >> chips_taken;
    legal = is_move_legal(chips_taken, chips_in_pile);
    while(legal==false)
      {
	cout << "That is not a legal move. Please take at least one and no more than half the total chips." <<endl;
	cin >> chips_taken;
	legal = is_move_legal(chips_taken, chips_in_pile);
      }
  }
  return chips_taken;
  /*
    This program uses the variables chips_taken and legal to proceed through the designated player's turn. Two main
    if statements are used to display questions for Player 1 and Player 2. Inside the if statements, chips_in_pile is
    displayed to the user. Then the user is asked how many chips they would like to take this turn. The user input is
    sent to the function is_move_legal and returned in a bool variable describing if the user input is a legal
    move or not. The program will continue to ask for new input as long as the player's move is illegal. Once
    The move is legal, this function send the variable chips_taken back to the main program.
   */
 }



int init_game() 
{ 
  int chips_in_pile=0;
  cout << "How many chips do you want to start with? (2-50 inclusive)" << endl;
  cin >> chips_in_pile;
  while (chips_in_pile>50 || chips_in_pile<2)
    {
      cout<< "Sorry, you must enter a number between 2 and 50 inclusive. Try again." <<endl;
      cin>> chips_in_pile;
    }
    return chips_in_pile;
  /*
    This program asks the user how many chips the game should start with, then takes in a user value. Using while
    statement with compound requirements, the user value to tested to see if it's valid. If the user value is not value
    is not valid, the program will ask for a new value. Once the value is valid, the function will return the variable
    chips_in_pile to the main program
   */ 
}
