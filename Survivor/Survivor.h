#include <stdio.h>
#include <string.h>

typedef struct Survivor
{
  char *name;
  int wounds;
  int actions;
  char *inventory[5];
  char *inHand[2];
} Survivor;

struct Survivor createNewSurvivor(char *);
void woundSurvivor(struct Survivor*);
int isSurvivorAlive(struct Survivor*);
void pickUpItem(char *, struct Survivor*);
char * selectItemFromInventory(char *, struct Survivor*);
void equipItem(char *, struct Survivor*);
