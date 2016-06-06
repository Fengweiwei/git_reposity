/*
 ============================================================================
 Name        : dijkstra.c
 Author      : fww
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*adjecent_matrix*/
int adj_matrix[100][100];
/*n nodes*/
int n;
/*单源节点到其他节点的cost，
 * 一开始初始化为adj_matrix
 * 中的一行,这里以节点编号为
 * 1为例*/
int dis[100];
/*node x相邻的节点中，每有一个节点被选为cost最小节点，就标记为1*/
int book[100];
/*找到当前x 和其余可达节点中cost最小的节点u， O(n)*/
int min(int x, int dis[]){
	int u, min = INT_MAX;
	int i;
	for(i=1; i<=n; i++){
		if(i==x)
			continue;
		if(book[i]==0&&dis[i]<min){
			u = i;
			min = dis[i];
		}
	}

	book[u] = 1;
	return u;
}
/*
 * @param x:单源节点x到其他节点的最短路径cost
 * */
void Dijkstra(int adj_matrix[100][100], int x){
	/*init array dis*/
	int i;
	for(i=1; i<=n; i++)
		dis[i] = adj_matrix[x][i];

	/*每次都选当前轮x node cost最小的那个node*/
	for(i=1; i<=n; i++){
		if(i==x)
			continue;
		/*找到当前x 和其余可达节点中cost最小的节点u， O(n)*/
		int u = min(dis);

		/*更新dis，看看x通过u中转到其他node
		 * 是否能得到更好的cost, O(n)*/
		for(i=1; i<=n; i++){
			//i == u ,已经是最短，不用比了,u->i不可达也不用再做下去
			if(i==u || i==x||adj_matrix[u][i]==INT_MAX)
				continue;
			int tmp = dis[u]+adj_matrix[u][i];
			if(tmp<dis[i])
				dis[i] = tmp;
		}
	}
	return;
}

int main(void) {
	//this is a git test
	//a rollback test
	return 0;
}
