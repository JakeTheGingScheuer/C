#include "./Survivor.h"

struct Survivor createNewSurvivor(char * name)
{
  struct Survivor survivor;
  survivor.name = name;
  survivor.wounds = 0;
  survivor.actions = 3;
  return survivor;
}

void woundSurvivor(struct Survivor* survivor)
{
  if(survivor.wounds < 2)
  {
    survivor.wounds++;
  }
}

int isSurvivorAlive(Survivor survivor)
{
  if(survivor.wounds >= 2)
  {
    return 0;
  }
  else return 1;
}

void pickUpItem(char * item, struct Survivor* survivor)
{
  for(int i = 0; i < 5; i++)
  {
      survivor->inventory[i] = item;
      break;
    }
  }
}

char * selectItemFromInventory(char * item, struct Survivor* survivor)
{
  for(int i =0; i < sizeof(survivor->inventory); i++)
  {
    if(!strcmp(survivor->inventory[i], item))
    {
      return survivor->inventory[i];
    }
  }
  return "ITEM NOT IN INVENTORY";
}

void equipItem(char * item, struct Survivor* survivor)
{
  for(int i =0; i < sizeof(survivor->inHand); i++)
  {
    if(survivor->inHand[i] != NULL)
    {
      survivor->inHand[i] = item;
      break;
    }
  }
}
