#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

#define TAILLE 100
int plateau[TAILLE][TAILLE];
int direction = 0;
int x = TAILLE/2;
int y = TAILLE/2;

void iteration()
{
	switch(direction)
	{
		case 0:
			direction += plateau[x][y];
			plateau[x][y] *= -1;
			x += plateau[x][y];
			break;
		case 1:
			direction += plateau[x][y];
			plateau[x][y] *= -1;
			y -= plateau[x][y];
			break;
		case 2:
			direction += plateau[x][y];
			plateau[x][y] *= -1;
			x -= plateau[x][y];
			break;
		case 3:
			direction += plateau[x][y];
			plateau[x][y] *= -1;
			y += plateau[x][y];
			break;
	}
	direction = (direction + 4) % 4;
	x = (x + TAILLE) % TAILLE;
	y = (y + TAILLE) % TAILLE;
}

void affiche()
{
	static int s = 0;
	printf("\n");
	for (int i = 0; i < TAILLE; i++)
	{
		for (int ii = 0; ii < TAILLE; ii++)
			printf((i==x && ii==y)?"O":(plateau[i][ii]==-1?"X":" "));
		printf("\n");
	}
	s+=32;
	printf("step : %d\n", s);

}

int main(int argc, char **argv)
{
	srand(time(NULL));
	
	for (int i = 0; i < TAILLE; i++)
		for (int ii = 0; ii < TAILLE; ii++)
			plateau[i][ii] = 1;
	/*for (int i = TAILLE/2 - TAILLE/10; i < TAILLE/2 + TAILLE/10; i++)
		for (int ii = TAILLE/2 - TAILLE/10; ii < TAILLE/2 + TAILLE/10; ii++)
			plateau[i][ii] = rand() <= RAND_MAX/2 ? 1 : -1;*/
	for (;;)
	{
		for (int i = 0; i < 32; i++)
		iteration();
		affiche();
		usleep(100000);
	}
	return 0;
}
