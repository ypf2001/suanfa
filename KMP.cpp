#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE  255	
typedef struct {
	char ch[MAXSIZE + 1];
	int length;
}SString;
;

SString* init_String(SString* s)
{
	s = (SString*)malloc(sizeof(SString));
	//s->ch = (char*)malloc(sizeof(char)*MAXSIZE);

	s->length = 0;
	return s;
}
void insertString(SString* s, char val) {
	s->length++;
	s->ch[s->length - 1] = val;

};
void get_next(SString *s,int* next) {
	next[0] =0;
	int i = 1;
	int z = 0;
	for (z = 1; z < s->length;z++) {
		int x = 0 ,j=0;
		int  m = (int)(z + 1) / 2;
		if ((z+1)%2 ==0) {
			j = 0;
			while (m<z+1) {
				if (s->ch[m]==s->ch[x]) {
					j++;
					x++;
					m++;
				}
				else {
					j = 0;
					x = 0;
					m++;
				}

			}
			next[z] = j;
		}
		else {
			j = 0;
			m  ++;
			while (m<z+1) {
				if (s->ch[m] == s->ch[x]) {
					j++;
					x++;
					m++;
				}
				else {
					j = 0;
					x = 0;
					m++;
				}
			}
			next[z] = j;
		}
	}
}

int KMP(SString* s, SString* t,int* next) {
	int i =0, j = 0;
	while (s->ch[i]==t->ch[j]) {
		
	}
	return 0;
}
	

int main() {

	SString* s = NULL;
	SString* t = NULL;
	s = init_String(s);
	t = init_String(t);
	//cacaaaaacbaaa
	//cbaaa
	insertString(s, 'c');
	insertString(s, 'a');
	insertString(s, 'c');
	insertString(s, 'a');
	insertString(s, 'a');
	insertString(s, 'a');
	insertString(s, 'a');
	insertString(s, 'a');
	insertString(s, 'c');
	insertString(s, 'b');
	insertString(s, 'a');
	insertString(s, 'a');
	insertString(s, 'c');
	insertString(s, 'b');
	insertString(s, 'a');
	insertString(s, 'a');
	insertString(s, 'a');
	//cbaaacba
	insertString(t, 'c');
	insertString(t, 'b');
	insertString(t, 'a');
	insertString(t, 'a');
	insertString(t, 'c');
	insertString(t, 'b');
	insertString(t, 'a');
	int*next = (int *)malloc(sizeof(int));
	 get_next(t, next);
	//printf("idx为：%d", KMP(s, t));
	int i = 0;
	for (i = 0; i < t->length;i++) {
		printf("当前值为：%d", next[i]);
	}
	return 0;
}