#include "bowling_stats.h"
#include <stdio.h>

int frejmovi[10];
int poeni[21];
static int skorUkupan;
static int brBacanja;

int skor()
{
	int i; 
	int j = 0;
	int bonus;
	for (i = 0; i < BROJ_FREJMOVA; i++)
	{
		if (poeni[j] == 10)                    // strike
		{
			if (poeni[j+2] == 10)
			skorUkupan += (10 + poeni[j+2] + poeni[j+4]);
			else
			skorUkupan += (10 + poeni[j+2] + poeni[j+3]);
		}
		else if (poeni[j] + poeni[j+1] == 10)  // spare
		skorUkupan += (10 + poeni[j+2]);
		else
		skorUkupan += (poeni[j] + poeni[j+1]);

		j += 2;
	}
	skorUkupan += poeni[MAX_BROJ_BACANJA-1];   // zadnji okvir ima 3 bacanja
	return skorUkupan;
}

void srusi(int x)
{
	if (brBacanja == MAX_BROJ_BACANJA)
	inicijalizacija();
	
	poeni[brBacanja++] = x;
	if (x == 10)
	{
		poeni[brBacanja++] = 0;  // ako je strike ima samo jedno bacanje u okviru	
	}
}


void inicijalizacija()
{
  int i,j;

  for(i = 0; i < BROJ_FREJMOVA; i++)
  {
      frejmovi[i] = 0;
  }

  for(j = 0; j < MAX_BROJ_BACANJA; j++)
  {
      poeni[j] = 0;
  }

  skorUkupan = 0;
  brBacanja = 0;

}
