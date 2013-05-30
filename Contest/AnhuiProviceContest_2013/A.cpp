#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[105];
int main(){
    while(gets(str)!=NULL){
        int l=strlen(str);
        int left=0,right=-1;
        for(int i=0;i<l;i++){
            if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')){
                if(left>right) left=i,right=i;
                else right=i;
            }
            else{
                //cout<<left<<" "<<right<<endl;
                for(int j=right;j>=left;j--)
                    printf("%c",str[j]);
                printf("%c",str[i]);
                left=0;right=-1;
            }
        }
        for(int i=right;i>=left;i--)
            printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}