#include<stdio.h>
#include<stdlib.h>
#define size 26
typedef struct {
int weight;
int parent, lch, rch;
}HTNode, * HuffmanTree;
HuffmanTree InitHuffTree(HuffmanTree T) {
	T = (HuffmanTree)malloc(sizeof(HTNode)*size*2);
	return T;
}


int findSmall(char** el,char m) {
	if (!m) {
		int i = 0;
		int j = 0;
		int temp = el[0][0];
		for (int i = 0; i < size-1; i++) {
			if (temp >el[0][i] && el[0][i]!=NULL && el[0][i] != 0){
				temp = el[0][i];
				j = i;
			}
		}
		el[0][j] = NULL;
		return temp;
	}
	else {
		int i = 0;
		int j = 0;
		int temp = m;
		for (int i = 0; i < size-1 ; i++) {

			if (el[0][i]!=NULL && el[0][i] != 0) {
				temp = el[0][i];
				j = i;
				break;
			}
		}
		for (int i = 0; i < size - 1; i++) {

			if (temp > el[0][i] && el[0][i] != NULL && el[0][i] != 0) {
				temp = el[0][i];
				j = i;
			}
		}
		el[0][j] = NULL;
		return temp;
	}
}


int CreateHuffTree(HuffmanTree t , char* el) {
	char** el1; 
	el1 = &el;
	int i = 0;
	int j = 0;
	int k  = 0;
	while (i<size) {
		if (i==0) {
			k++;
			int a = findSmall(el1, NULL);
			int b = findSmall(el1, a);
			t[i].lch = a;
			t[i].rch = b;
			t[size + k-1].weight = a +b;
			t[i].parent = t[size + k-1].weight;
			i = i + 2;
		}
		else {
			int a = findSmall(el1, t[size + i].weight);
			int b = findSmall(el1, t[size + i].weight);
			if (a != NULL&& b != NULL) {
				i = i + 2;
				k++;
				int c = findSmall(el1, a + b);
				t[size + k-1].lch = a;
				t[size + k-1].rch = b;
				t[size + k-1].weight = a + b;
				if (c != NULL) {
					i++;
					k++;
					
					t[size + k-1].lch = t[size + k - 3].weight;
					t[size + k-1].rch = c;
					t[size + k-1].weight = c + t[size + k - 3].weight;
					t[size + k - 3].parent = t[size + k - 1].weight;
					t[size + k - 2].parent = t[size + k - 1].weight;
					k++;
					t[size + k - 1].lch = t[size + k - 3].weight;
					t[size + k - 1].rch = t[size + k - 2].weight;
					t[size + k - 1].weight = t[size + k - 2].weight; + t[size + k - 3].weight;
					t[size + k - 3].parent = t[size + k - 1].weight;
					t[size + k - 2].parent = t[size + k - 1].weight;
				}
				else {
					k++;
					t[size + k -1].lch = t[size + k - 3].weight;
					t[size + k -1].rch = t[size + k-2].weight;
					t[size + k -1].weight = t[size + k - 3].weight+t[size + k - 2].weight;
					t[size + k - 3].parent = t[size + k - 1].weight;
				}
			}
			else if(a != NULL && b == NULL) {
				i++;
				k++;
				t[size + k - 1].lch = t[size + k - 2].weight;
				t[size + k - 1].rch = a;
				t[size + k - 1].weight = t[size + k - 2].weight + a;
				t[size + k - 2].parent = t[size + k - 1].weight;
			
			}else{
				return 0;
			}
		};
	}
	return 1;
}
char* generate() {
	int s = 97;
	char* el = (char*)malloc(sizeof(char)* size);
	for (s = 97; s <= 123;s++) {
		el[s - 97] = (char)s;
	}
	return el;
}
int main() {
	char* el =  generate();
	HuffmanTree T = NULL;

	T =InitHuffTree(T);
	int r =  CreateHuffTree(T,el);
	//printf("%d", r);
	return 0;
}	 
