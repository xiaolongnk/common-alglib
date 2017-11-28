/****
 * sovle 8 queen problesm.
 * recursive execrise.
 * 2017-05-19 06:53
 */

#include <stdio.h>
#include <string.h>
// #include <malloc.h>

#define N 15

int total_solution = 1;
int pos[N];

int solve_n_queen_problems(int total , int current_line)
{
    if(current_line == total) {
        printf("Solution %d\n",total_solution++);
        for(int i = 0 ; i < total ; ++i) {
            for(int j = 0 ; j < total ; ++j) {
                if(j == pos[i]) printf(" Q ");
                else printf(" * ");
            }
            printf("\n");
        }
    } else {
        for(int col = 0 ; col < total ; ++col ) {
            //check if the [step,i] can be ok to place element.
            int flag = 1;
            for(int line = 0 ; line < current_line; ++line) {
                if(pos[line] == col ||  col - pos[line]  == current_line - line  || 
                        (current_line - line  == pos[line] - col)) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) {
                pos[current_line] = col;
                solve_n_queen_problems(total , current_line+ 1);
                pos[current_line] = -1;
            }
        }
    }
}

int main()
{
    for(int i = 0 ; i < N ; ++i) {
        pos[i] = -1;
    }
    solve_n_queen_problems(8,0);
    return 0;
}

