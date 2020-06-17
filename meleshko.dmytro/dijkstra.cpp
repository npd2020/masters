#include <iostream>
#include <string.h>

#define MAX 110
#define INF 0x3F3F3F3F

int a, b, n, m, j, w, Min, mas[MAX][MAX], used[MAX], d[MAX], cost[MAX];

void reCalc(int i, int j){
	if (d[i] + mas[i][j] < d[j]) d[j] = d[i] + mas[i][j];
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);

	memset(mas, 0x3F, sizeof mas);
	memset(used, 0, sizeof used);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		scanf("%d %d", &a, &b);
		mas[a][b] = cost[a];
		mas[b][a] = cost[b];
	}

	memset(d, 0x3F, sizeof d);
	d[1] = 0;

	for (int i = 1; i < n; i++){
		Min = INF; w = -1;
		for (j = 1; j <= n; j++)
			if (!used[j] && d[j] < Min){
				Min = d[j];
				w = j;
			}
		if (w < 0) break;
		for (j = 1; j <= n; j++)
			if (!used[j]) reCalc(w, j);
		used[w] = 1;
	}

	if (d[n] == INF) printf("-1\n");
	else printf("%d\n", d[n]);
	return 0;
}
