#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 26

struct problem {
  char *q;             /* question */
  char *a;             /* answer */
};

struct problem problems[] = {{"Who was the first president?",
			      "Washington"},
			     {"What is the capital of Pennsylvania?",
			      "Harrisburg"},
			     {"Who was the last president of the Soviet Union?",
			      "Gorbachev"},
			     {"What is the largest ocean?",
			      "Pacific"},
			     {"Who was the Wizard of Menlo Park?",
			      "Edison"},
			     {"For whom did Vinny Testaverde play when he won the Heisman?",
			      "University of Miami"},
			     {"What sort of figure has 12 sides?",
			      "dodecagon"},
			     {"Around which island does most of the movie Jaws take place?",
			      "Amity"},
			     {"In what country was the 2014 World Cup held?", 
			      "Brazil"},
			     {"In what country will the 2016 Summer Olympics be held?", 
			      "Brazil"},
			     {"With what musical instrument is Nicolo Paganinni most closely associated?",
			      "Violin"},
			     {"Who lives in a pineapple under the sea?",
			      "Spongebob"},
			     {"What frozen waffle brand was named for one of its ingredients?",
			      "Eggo"},
			     {"Who directed the movie Young Frankenstein?",
			      "Mel Brooks"},
			     {"In what city did Ned Stark meet his fate?",
			      "King's Landing"},
			     {"Where does Grunkle Stan live?",
			      "Gravity Falls"},
			     {"The currency of which country is nicknamed the Loonie?",
			      "Canada"},
			     {"What car company produced the Aspire?",
			      "Ford"},
			     {"What brand of hot dog is advertised to answer to a 'higher authority'?",
			      "Hebrew National"},
			     {"What's the name of the Arrested Development character who explained drinking an entire bottle of vodka with, \"It's vodka. It goes bad once you open it.\"?",
			      "Lindsay"},
			     {"What's Hermione's cat's name?",
			      "Crookshanks"},
			     {"What is the name of Hamlet's deceased court jester?",
			      "Yorick"},
			     {"Who wrote the Goldberg Variations?",
			      "Bach"},
			     {"Which US state borders exactly one other US state?",
			      "Maine"},
			     {"Who sang It's Not Easy Being Green?",
			      "Kermit"},
			     {"In what city did Laverne and Shirley live?",
			      "Milwaukee"}};

void winner();
void loser(int);
int play_game(struct problem*);
int get_random_choice();
void print_welcome();
void be_superficially_friendly();


int main(void)
{
  int rchoice;

  rchoice = get_random_choice(NUM_QUESTIONS);
  print_welcome();
  be_superficially_friendly();
  if (play_game(&problems[rchoice]))
    winner();
  else
    loser(rchoice);

  return 0;
}

int play_game(struct problem *p)
{
  char guess[24];

  printf("The next question is:\n");
  printf("%s ", p->q);
  gets(guess);
  return !strcasecmp(p->a,guess);
}

int get_random_choice(int x)
{
  int r;
  srand((unsigned int)time((time_t *)NULL));
  r = rand();
  return r%x;
}

void winner()
{
  printf("You've won a million dollars.\n");
  exit(0);
}

void loser(int p)
{
  printf("\nYou've lost.  The right answer was '%s'.  Thanks for playing.\n",
	 problems[p].a);
  exit(1);
}

void be_superficially_friendly() {
  char name[32];

  printf("What's your name ? "); 
  gets(name); 
  printf("Hi, %s.  Get ready to play.\n", name);
}

void print_welcome()
{
  printf("|----------------------------------------------------------|\n");
  printf("| Welcome to 2107 Trivia.                                  |\n");
  printf("| Please do not give your answer in the form of a question |\n");
  printf("|----------------------------------------------------------|\n");
}
