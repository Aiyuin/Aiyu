#include<stdio.h> 
#include<string.h>
typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode, * HuffmanTree;
typedef char** HuffmanCode;
void Select(HuffmanTree& HT, int n, int* s1, int* s2);
void CreateHuffmanTree(HuffmanTree& HT, int n);
void ShowHuffmanTree(HuffmanTree& HT, int n);
void CreateHuffmanCode(HuffmanTree& HT, HuffmanCode& HC, int n);
void ShowHuffmanCode(HuffmanCode HC, int n);

int main() {
	int n;
	HuffmanTree HT;
	HuffmanCode HC;
	printf("输入你的n：");
	scanf_s("%d", &n);
	CreateHuffmanTree(HT, n);
	ShowHuffmanTree(HT, n);
	CreateHuffmanCode(HT, HC, n);
	ShowHuffmanCode(HC, n);
	getchar();
	getchar();
	return 0;
}

void Select(HuffmanTree& HT, int n, int* s1, int* s2) {
	int i;
	int j;
	for (i = 1; i <= n; i++) {
		if (HT[i].parent == 0) {
			*s1 = i;
			break;
		}
	}
	for (i = 1; i <= n; i++) {
		if (HT[i].parent == 0 && HT[*s1].weight > HT[i].weight)
			*s1 = i;
	}
	for (j = 1; j <= n; j++) {
		if (HT[j].parent == 0 && j != *s1) {
			*s2 = j;
			break;
		}
	}
	for (j = 1; j <= n; j++) {
		if (HT[j].parent == 0 && HT[*s2].weight > HT[j].weight && j != *s1)
			*s2 = j;
	}
}

void CreateHuffmanTree(HuffmanTree& HT, int n) {
	if (n <= 1) return;
	int m;
	m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++) {
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++) {
		printf("请输入n个结点的权值：");
		scanf_s("%d", &HT[i].weight);
	}
	int s1, s2;
	for (int i = n + 1; i <= m; i++) {
		Select(HT, i - 1, &s1, &s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

void ShowHuffmanTree(HuffmanTree& HT, int n) {
	printf("HuffmanTree\n");
	printf("结点    weight    parent    lchild    rchild\n");
	for (int i = 1; i <= 2 * n - 1; i++) {
		printf("%d    ", i);
		printf("%d    ", HT[i].weight);
		printf("%d    ", HT[i].parent);
		printf("%d    ", HT[i].lchild);
		printf("%d    \n", HT[i].rchild);
	}
}
void CreateHuffmanCode(HuffmanTree& HT, HuffmanCode& HC, int n) {
	HC = new char* [n + 1];
	char* cd;
	cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0) {
			--start;
			if (HT[f].lchild == c) {
				cd[start] = '0';
			}
			
			else {
				cd[start] = '1';
			}
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n-start];
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}
void ShowHuffmanCode(HuffmanCode HC, int n) {
	printf("HuffmanCode\n");
	for (int i = 1; i <= n; i++) {
		printf("%d    ", i);
		printf("%s\n", HC[i]);
	}
}