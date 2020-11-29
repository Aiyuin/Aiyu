#include<stdio.h>
#include<iostream>

using namespace std;

#define MaxInt 32767
#define MVNum 100

typedef char VerTexType;
typedef int ArcType;

typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;

void CreateUDN(AMGraph& G);
int LocateVex(AMGraph& G,int v1);
void ShowUDN(AMGraph& G);

int main() {
	AMGraph G;
	CreateUDN(G);
	ShowUDN(G);
	return 0;
}

//寻找顶点的位置
int LocateVex(AMGraph& G, char v) {
	int i = 0;
	while (v != G.vexs[i]) {
		i++;
	}
	return i;
}

//采用邻接矩阵表示法构建无向图
void CreateUDN(AMGraph& G) {	
	cout << "输入顶点数和变数(用空格作为分隔符)：";
	cin >> G.vexnum >> G.arcnum;
	cout << "依此输入顶点的信息(顶点信息是字符,并用空格作为分隔符)：";
	for (int i = 0; i < G.vexnum; ++i)
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; ++i)
		for (int j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = MaxInt;
	for (int k = 0; k < G.arcnum; ++k) {
		char v1, v2;
		int w,i,j;
		cout << "输入第"<<k<<"条边的顶点和权值（eg:v1  v2  w）：";
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
}

//展示邻接矩阵
void ShowUDN(AMGraph& G) {
	cout << "邻接矩阵\n";
	for (int i = 0; i < G.vexnum; ++i) {
		for (int j = 0; j < G.vexnum; j++)
			cout << G.arcs[i][j] << " ";
		cout << "\n";
	}
		
}