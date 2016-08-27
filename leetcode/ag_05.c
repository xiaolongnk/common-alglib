#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    char ts[2005];
    memset(ts,0,sizeof(ts));
    ts[0] = '#';
    int cnt = 1;
    for(int i = 0; i < strlen(s); i++){
        ts[cnt++] = s[i];
        ts[cnt++] = '#';
    }
    int lents = strlen(ts);
    int max = 1;
    int pos = 0;
    for(int i = 0; i <lents; i++){
        int currentMax = 1;
        for(int j = 0 ; j < i ; j++){
            int l = i - j - 1;
            int r = i + j + 1;
            if(l < 0 || r >= lents){
                break;
            }
            if( ts[l] == ts[r]){
                currentMax+=2;
            }else {
                break;
            }
        }
        currentMax = (currentMax - 1) / 2;
        if (currentMax >= max){
            max = currentMax;
            pos = i;
        }
    }
    s = (char *)malloc(2005*sizeof(char));
    memset(s , 0 ,sizeof(s));
    cnt = 0;
    for(int i = pos - max + 1; i<pos + max ; i++){
        if(ts[i]!='#') s[cnt++] = ts[i];
    }
    s[cnt]='\0';
    return s;
}

int main()
{
    char str[1000];
    while(scanf("%s",str)!=EOF){
        char * ans = longestPalindrome(str);
        printf("%s\n",ans);
    }
    return 0;   
}
