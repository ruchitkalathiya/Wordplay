#include<iostream>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;
int main()
{
    static int score;
    score = 0;

    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
          {"wall", "Do you feel like banging your head against something?"},
          {"glass", "These might help you see the answer" },
          {"bike", "It has two wheels." },
          {"auto", "if machine runs itself."},
          {"jungle", "Where does Mowgli stay ?"}
    };

   //FIRST SCREEN
   cout<<"\nWelcome to the game \"WORDPLAY\" .\n";
   cout<<"\n*********************************************************************\n";
   cout<<"**************    Created By RUCHIT KALATHIYA   *********************";
   cout<<"\n*********************************************************************\n";
   cout<<"\n\* Instruction :";
   cout<<"\n1) Type 'hint' for hint.\n";
   cout<<"\nTO START THE GAME PRESS ANY KEY .";
   getch();

    replay:
       system("cls");
    srand(time(0));
    int choice = (rand() % NUM_WORDS);
    string word = WORDS[choice][WORD];
    string hint = WORDS[choice][HINT];
    int c = word.length();
    char d = '_' ;

    //Main display
    cout<<"\n\* Instruction :";
    cout<<"\n1) Type 'hint' for hint.\n\n\n";
    cout<<"\n\t\tSCORE : "<<score;
    cout<<"\n\t\t** WORDPLAY ** \n";
	cout<<"\n\t\t**************";
    cout<<"\n\t\t--------------\n\n\t\t  ";
      for(int j=0;j<c;j++)
	  {
	     if(j%2==0)
            cout<<word[j]<<" ";
         else
            cout<<d<<" ";
      }
    cout<<"\n\n\t\t--------------";
    cout<<"\n\t\t**************";

    string guess;
    cout <<"\nYour Guess: ";
    cin >> guess;

    //ENTERING THE GAME LOOP
    int chance=5;
    while ((guess != word) && (chance>1))
    {
          if (guess == "hint")
             cout << "HINT :: "<<hint;
          else
              {
                  --chance;
                  cout << "Sorry that is not it...\n\t\t";
                  cout << "<< You have " << chance <<" more guesses >>";
              }

    cout << "\nYour guess: ";
    cin >> guess;
    }
    if(chance==1)
        {
            cout<<"**SORRY  U R LOOSE**\nBETTER LUCK NEXT TIME.";
            cout<<"\nANSWER IS : "<<word;
        }
    else
    {
        char p;
        cout<<"HURRAY!! CORRECT ANSWER!!";
        score+=10;
        input:
        cout<<"\nFor next word PRESS 'Y'\nFor quit the game PRESS 'Q'.\n";
        cin>>p;
    if(p=='Y' || p=='y')
        goto replay;
    else if(p!='Y' && p!='y' && p!='q' && p!='Q')
    {
        cout<<"Wrong input!!! Please try again.";
        goto input;
    }
    else
    {
        cout<<"Your score is "<<score<<".\n";
        cout<<"Thank you for playing.";
        system("pause");
    }
    }

    return 0;
}
