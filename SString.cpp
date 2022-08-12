#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE  255	
typedef struct {
	char ch[MAXSIZE+1];
	int length;
}SString;

SString* init_String (SString * s)
{
	s = (SString*)malloc(sizeof(SString));
	//s->ch = (char*)malloc(sizeof(char)*MAXSIZE);

	s->length = 0;
	return s;
}
void insertString(SString * s,char val) {
	s->length++;
	s->ch[s->length - 1] = val;
	
};

int BF(SString* s,SString* t ) {
	int i=1, j=1;
	int temp = 1;
	while (i < s->length&&j<t->length) {
		if (s->ch[i-1] == t->ch[j-1]) {
			i++;
			j++;
			temp++;
			if (temp ==t->length) {
				return i-j;
			}
		}
		else {
			if (temp >1) {
				temp = 1;
				i = i - temp+1;
				j = 1;
			}
			else {
				i++;
				j = 1;
			}
		}
	}
	return 0;
}


int main() {

	SString* s = NULL;
	SString* t = NULL;
	s =  init_String(s);
	t =  init_String(t);
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
	insertString(s, 'a');
	insertString(t, 'c');
	insertString(t, 'b');
	insertString(t, 'a');
	insertString(t, 'a');
	insertString(t, 'a');
	printf("idxÎª£º%d", BF(s, t));

	return 0;
}