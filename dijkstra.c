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
/*��Դ�ڵ㵽�����ڵ��cost��
 * һ��ʼ��ʼ��Ϊadj_matrix
 * �е�һ��,�����Խڵ���Ϊ
 * 1Ϊ��*/
int dis[100];
/*node x���ڵĽڵ��У�ÿ��һ���ڵ㱻ѡΪcost��С�ڵ㣬�ͱ��Ϊ1*/
int book[100];
/*�ҵ���ǰx ������ɴ�ڵ���cost��С�Ľڵ�u�� O(n)*/
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
 * @param x:��Դ�ڵ�x�������ڵ�����·��cost
 * */
void Dijkstra(int adj_matrix[100][100], int x){
	/*init array dis*/
	int i;
	for(i=1; i<=n; i++)
		dis[i] = adj_matrix[x][i];

	/*ÿ�ζ�ѡ��ǰ��x node cost��С���Ǹ�node*/
	for(i=1; i<=n; i++){
		if(i==x)
			continue;
		/*�ҵ���ǰx ������ɴ�ڵ���cost��С�Ľڵ�u�� O(n)*/
		int u = min(dis);

		/*����dis������xͨ��u��ת������node
		 * �Ƿ��ܵõ����õ�cost, O(n)*/
		for(i=1; i<=n; i++){
			//i == u ,�Ѿ�����̣����ñ���,u->i���ɴ�Ҳ����������ȥ
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
