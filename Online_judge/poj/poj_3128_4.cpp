#include <stdio.h>
#include <string.h>
char s[100];
int tt[100], bj[100];
int main(){
	int i, j, x, t;
	scanf("%d", &t);
	gets(s);
	while(t--) {
		gets(s);
		memset(tt, 0, sizeof(tt));
		for(i = 0; s[i]; ++i) {
			j = i, x = 0; 
			while(bj[s[j] - 'A'] != t) { 
				++x;
				bj[s[j] - 'A'] = t; 
				j = s[j] - 'A';   
			}   
			if(x != 0) tt[x] ^= 1;
		}  
		for(i = 2; i <= 26; i += 2) if(tt[i]) break;
		if(tt[i]) puts("No");  
		else puts("Yes");
	}
	return 0;
}