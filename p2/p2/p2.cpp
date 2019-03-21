#include<stdio.h>
#include<stdio.h>
#include<math.h>
#define MAX 20

typedef struct xy {
	int x, y, visit = 0;	
}XY;

int sum;

void tsp(XY *road, int n, int start)
{
	road[start].visit = 1;
	printf("%d ", start);
	for (int i = 0; i < n; i++) {
		if (road[i].visit == 1)
			continue;
		tsp(road, n, i);
		printf("\n");
	}
}

double dis(int a1, int a2, int b1, int b2)
{
	return sqrt((a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1));
}

int main()
{
	FILE *in;
	XY xy[20];
	char fname[][30] = {"input0.txt", "input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt"};
	int N;

	for (int i = 0; i < 7; i++) {
		in = fopen(fname[i], "r");
		fscanf(in, "%d", &N);
		for (int j = 0; j < N; j++) {
			fscanf(in, "%d", &xy[j].x);
			fscanf(in, "%d", &xy[j].y);
			tsp(xy, N, 0);
		}
	}
}