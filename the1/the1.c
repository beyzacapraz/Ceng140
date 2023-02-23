#include <stdio.h>
#define W_INDEX 0
#define H_INDEX 1
#define T_INDEX 2
#define P_INDEX 3
#define S_INDEX 4
#define A_INDEX 5
#define N_INDEX 6
int final_array[100000] = {0};
int main() {
    int wall_length,tribe_number;
    int width,height,time,left_position,speed,attack_interval,num_attack;
    int i,j,k,l,m;
    scanf(" %d", &wall_length);
    scanf(" %d", &tribe_number);
    for(i=0;i<=wall_length;++i){
        final_array[i] = 1;
    }
    for(j=0;j<tribe_number;++j){
        scanf(" %d %d %d %d %d %d %d", &width, &height, &time, &left_position, &speed, &attack_interval, &num_attack);
        for(k=0;k<num_attack;++k){
            if(left_position <= wall_length){
                for(l=left_position;l<left_position+width;++l){
                    if(0<=l && l<=wall_length &&height>final_array[l]){
                        final_array[l]=height;
                    }
                }
            }
            left_position += speed*attack_interval;
        }
    }
    for(m=0;m<wall_length;++m){
        printf("%d ",final_array[m]);
    }
    printf("%d\n",final_array[wall_length]);
    
    return 0;
}