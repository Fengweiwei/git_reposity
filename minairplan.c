/*
 ============================================================================
 Name        : minairplan.c
 Author      : fww
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*adjecent martix*/
int adj_matrix[100][100];
/*n nodes*/
int n;
/*mark node visited or not(already enqueue or not)*/
int book[100];

/*simple queue*/
typedef struct node{
	int x;
	int step;
}NODE;
NODE Q[100];
int head, tail;

/*当前u结点开始做bfs*/
void bfs_min_transfer(int u, int dst) {
	/*node u enqueue*/
	NODE node;
	node.x = u;
	node.step = 0;
	Q[tail] = node;
	book[tail++] = 1;
	while (head < tail) {
		/*check if head==dst*/
		if(Q[head].x==dst){
			printf("min=%d\n", Q[head].step);
			break;
		}
		/*head's neighbors enqueue*/
		int i;
		for (i = 1; i <= n; i++) {
			/*应该是看当前队列中head节点的neighbors*/
			if (adj_matrix[Q[head].x][i] == 1 && book[i] == 0) {
				book[i] = 1;
				/*enqueue op*/
				node.x = i;
				node.step = Q[head].step+1;
				Q[tail++] = node;
			}
		}
		/*head dequeue*/
		head++;
	}
	return;
}

int main(void) {
	int edges, src, dst;
	/*create adj_matrix*/
	scanf("%d%d%d%d", &n, &edges, &src, &dst);
	int i;
	for(i=0; i<edges; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		adj_matrix[x][y] = 1;
		adj_matrix[y][x] = 1;
	}

	bfs_min_transfer(src, dst);
	return 0;
}
