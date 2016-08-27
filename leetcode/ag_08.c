#include <stdio.h>


int myAtoi(char* str) {

#define M_MAX_INT 2147483648
#define N_MAX_INT -2147483648

 	if(str == NULL) return 0;
    int cnt = 0;
    int positive_flag = 1;
    long long ans = 0;
    while(*str != '\0'){
        if(*str == ' '){
            if(cnt) break;
            str++;
            continue;
        }else if(*str >= '0' && *str <='9'){
            ans = ans * 10 + (*str - '0');
            if(ans >= M_MAX_INT ) {
                if(positive_flag){
                    ans = 2147483647;
                }else {
                    ans = N_MAX_INT;
                }
                return ans;
            }
            cnt++;
        } else if(*str == '-'){
            if(cnt) break;
            positive_flag = 0;
            cnt++;
        }else if(*str == '+'){
            if(cnt) break;
            cnt++;
        }else {
            break;
        }
        str++;
    }
    if(positive_flag) return ans;
    else return -1*ans;
}

int main()
{
    char str[100] ="";
    while(gets(str)){
        printf("input is: %s\n",str);
        int ans = myAtoi(str);
        printf("%d\n",ans);
    }
    return 0;
}
