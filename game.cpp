#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<ctime>
#include<cstdlib>

void print_page(int x);
int getchoice();
void eval_page_choice(int x, int *curr);
void print_help();
using namespace std;

class cookie{
public :
  
  //default blank constructor
  cookie(){
  }
  
  //function to make a move and update player status according to dice value...
  void move(int dice)
  {
    int val,points,get=0;
    char obj[20];
    ifstream items("items");
    while(get==0)
    {
      items>>val>>obj>>points;
      if(val == dice)
      {get=1;
      }
    }
    items.close();
    cout << "Dice =" << dice << "\tItem is :- "<< obj << "\tPoints are :- "<<points<<"\n\n";
    cout <<"After turn your score is :-";
    score = score+points;
    cout << score;
  }
  
  //it will flag if the player is still in the game or is OUT
  int valid()
  {
    int x;
    if(score<0)
    {
      x=0;
      status=0;
    }
    return x;
  }
  
  //function to check the activity of the player....
  int check_status()
  {
    return status;
  }
  
  //accept name and initialize the player
  void get_name(string x)
  {name=x;
  score=200;
  status=1;
    cout << "Player registered :\tName :- "<< name << "\tScore :- "<< score<<"\n\n";
  }
  
  //print all the values that will be printed before the Dice roll of respective player...
  void print_details()
  {
    cout << "\n\nCurrennt player : Name :- "<<name<<"   and   Score :- "<<score<<"\n\n";
  }
  
  //give name out
  string print_name()
  {
    return name;
  }
  
  //is game still on???
  int win_stat()
  {
  if(score>1000)
  {
    return 0;
  }
  else
  {
    return 1;
  }
  }
  
private :
  //score and name are the private parts of the object players and will be updated through functions
  int score,status;
  string name;
};

int num_player=0;
int game_page(cookie player[]);

int main()
{
  int choice,curr_page;	//curr_page is the page indicator which indicates the current page
 curr_page=0;	//0 indicates that it's the main page
  do
  {
  print_page(curr_page);
  choice=getchoice();
  eval_page_choice(choice,&curr_page);
  }while(choice);
  return 0;
}

//function to print main page of the game...
void print_page(int curr)
{
  if(curr == 0){
    //page is main page and contents are as :- 
  cout << "\n\t\t\tHello Buddies... Welcome to the Game RACE-UP";
  cout << "\n\n\t\tMenu...";
  cout << "\n\n\t1. Start a new game...";  
  cout << "\n\t2. Help and Introduction...";
  cout << "\n\t3. Exit the game...";
  cout << "\n\n\tEnter your choice :- ";
  }
  if(curr==1){
    //page is "Start new game page"
    int temp,res;
    char tmp;
    cout << "\n\n\t\t\tWelcome to the NEW GAME page...";
    cout << "\n\n\tEnter the number of players to play in the game with :- ";
    cin >> num_player;
    cookie player[num_player];
    for(temp=1;temp<=num_player;temp++)
    {
      string names;
      cout << "Enter the name of "<< temp << "th player :- ";
      cin >> names;
      player[temp-1].get_name(names);
    }
    cout << "\n\n\nAll the players registered for the game....";
    cout << "Press 's' or 'S' start with....";
    cin >> tmp;
    res=game_page(player);
    cout << "\n\nThe following player has won the game :- ";
    player[res].print_details();
    main();
  }
}

//function to accept any choice input
int getchoice()
{
  int x;
  cin >> x;
  return x;
}

//function to evaluate mpage choice
void eval_page_choice(int x, int *curr)
{
  if(*curr == 0) 
  {// i.e we are currently on the main page....
  switch(x)
  {
    case 1: 
      cout << "New game option selected!!!";
      *curr =1;
      break;
    case 2:
      cout << "Help and Introductions option selected!!!";
      *curr =2;
      break;
    case 3:
      cout << "Exit option selected...!!!";
      exit(0);
      break;
  }
  if(*curr == 2)
  {
    print_help();
    *curr = 0;
  }
  }
  
  
  cout << "\n\n";
}

//function to roll the dice and fetch any random number between 1 to 6.....
int roll_dice()
{
  int x;
  char tmp;
  cout<< "\n\nEnter 'd' or 'D' to roll the dice";
  cin >> tmp;
   srand(time(0));	//seed a random number generator algorithm
  //we print 25 random numbers as on dice would be from 1 to 6...
  x=1+(rand()%6);
  cout << "Dice rolled.. Dice value is :- "<<x<<"\n\n";
  return x;
}

//actual game code
int game_page(cookie player[])
{
  int temp,game_flag=1;
  cout << "\n\n\t\t\tGame Begins....!!!\n\n";
  while(game_flag!=0 && num_player!=1){
  for(temp=0;temp<num_player;temp++)
  {
    if(player[temp].check_status()!=0)
    {
      player[temp].print_details();
      player[temp].move(roll_dice());
      player[temp].print_details();
      game_flag=player[temp].win_stat();
      if(player[temp].valid() == 0)
      {
	cout << "The Player " << player[temp].print_name() <<" has been declared out...!!!";
	num_player--;
      }
      if(game_flag==0 || num_player==1)
      {break;
      }
        cout << "\n\nSwitching turn...\n\n";
    }
  }
  }
  for(temp=0;temp<num_player;temp++)
  {
    if(player[temp].check_status()==1 && player[temp].valid()==1)
    {
      return temp;
    }
  }
}


void print_help()
{
  char tmp;
  cout << "\t\t###Welcome to the game RACE-UP...\n\n";
  cout << "\t-various of the terms concerned to the game...";
  cout << "\n\nDice :- It's imagined of as the actual dice available.\n\t";
  cout <<"Rolling the dice will give any random number between 1 to 6 and the player will have to accept the respected choice that would come-up";
  cout <<"\n\nTurn :- At one turn each of the player will be given one chance to ROLL the DICE\n\t";
  cout <<"Further the player will be given another chance to ROLL the Dice if the number on the DICE would be 6\n\t";
  cout <<"Three 6 on dice in the row would nullify all the previous dice rolls and the turn will be rotated\n\t";
  cout <<"The turn will be rotated from player to player untill one of the player will emerge victorious";
  cout <<"\n\nPlayer Cookie :- It's just the representative piece of each of the player on the game";
  cout <<"\n\nObjective of the Game :- The primary objective of the game is to reach the score of 1000 by obtaining the points related to the objects that are obtained on the dice ROLLs";
  cout <<"\n\nWinning and Losing conditions :- The player who first will be able to reach the score of 1000 points will be considered as the WINNER and so consequently other players will lose";
  cout <<"\n\tA player will be declared as OUT or LOST if his score will get to be less than 0";
  cout <<"\n\tIf only one player will be left in the game and rest all other players get OUT then the last remaining player will be declared as a WINNER";
  cout <<"\n\n\n\tPress any key to return to the MAIN-MENU...";
  cout << "Enter any character to return to the main menu :- ";
  cin >> tmp;
}