#include<stdio.h>
#include<stdio.h>
#include<math.h>
#define MAX 20

typedef struct xy {
	int x, y, visit = 0;
}XY;

XY point[MAX];
int N, temp[MAX], min[MAX];
double low = 0, cmp = 0;

double dis(int a1, int a2, int b1, int b2)
{
	return sqrt((a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1));
}

void tsp(int start, int count)
{
	point[start].visit = 1;
	temp[count] = start;
	if (count + 1 == N) {
		for (int k = 0; k < N; k++) {
			if(k != N - 1)
				cmp += dis(point[temp[k]].x, point[temp[k + 1]].x, point[temp[k]].y, point[temp[k + 1]].y);
			else
				cmp += dis(point[temp[k]].x, point[temp[0]].x, point[temp[k]].y, point[temp[0]].y);
		}
		if (low == 0)
			low = cmp;
		if (low > cmp) {
			low = cmp;
			for (int j = 0; j < N; j++)
				min[j] = temp[j];
		}
		cmp = 0;
	}
	for (int i = 0; i < N; i++) {
		if (point[i].visit == 1)
			continue;
		tsp(i, count + 1);
	}
	point[start].visit = 0;
}

int main()
{
	FILE *in;
	char fname[][30] = { "input0.txt", "input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt" };

	for (int i = 0; i < 7; i++) {
		in = fopen(fname[i], "r");
		fscanf(in, "%d", &N);
		for (int j = 0; j < N; j++) {
			fscanf(in, "%d", &point[j].x);
			fscanf(in, "%d", &point[j].y);
		}
		for(int k = 0; k < N; k++)
			tsp(k, 0);
		printf("<%s>[ ", fname[i]);
		for (int l = 0; l < N; l++)
			printf("%d ", min[l]);
		printf("]: %.13lf\n", low);
		low = 0;
	}
}