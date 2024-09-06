#include <stdio.h>

int sum_digits(int val){
    if (val < 0){
        val = -val;
    }

    int sum = 0;
    while(val > 0){
        sum += val % 10;
        val /= 10;
    }

    return sum;
}

int main(void){
    int odd_sum = 0;
    int odd_cnt = 0;
    int ev_sum = 0;
    int ev_cnt = 0;

    int inp_cnt = 1;
    int inp;
    
    while (1){
        if (inp_cnt == 1){
            printf("Enter the 1st value: ");
        }else if (inp_cnt == 2){
            printf("Enter the 2nd value: ");
        }else if (inp_cnt == 3){
            printf("Enter the 3rd value: ");
        }else{
            printf("Enter the %dth value: ", inp_cnt);
        }

        scanf("%d", &inp);
        if (inp == 0){
            break;
        }

        int sum = sum_digits(inp);

        if (sum%2 == 0){
            ev_sum += inp;
            ev_cnt ++;
        }else{
            odd_sum += inp;
            odd_cnt ++;
        }

        inp_cnt ++;
    }

    if ((odd_sum == 0) && (ev_sum == 0)){
        printf("There is no average to compute.\n");
    }else{
        if (ev_sum != 0){
            float ev_avg = (float)ev_sum / (float)ev_cnt;
            printf("Average of input values whose digits sum up to an even number: %.2f \n", ev_avg);
        }
        if (odd_sum != 0){
            float odd_avg = (float)odd_sum / (float)odd_cnt;
            printf("Average of input values whose digits sum up to an odd number: %.2f \n", odd_avg);
        }
    }
    
    return 0;
}
