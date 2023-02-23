#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

char* curpos;
int logical_recursion(char* c,char* f){
    int left,right,i;char oper;
    if(*curpos == '('){
        curpos++;
        left = logical_recursion(c,f);
        oper = *curpos++;
        right = logical_recursion(c,f);
        curpos++;
        switch(oper){
            case '&': return left && right;break;
            case '|': return left || right;break;
            case '=': return left == right;break;
            case '>': return (!left) || right;break;
        }
    }
    else{
        if(*curpos == '-'){
            curpos++;
            left = (!logical_recursion(c,f));
            
        }
        else{
        for(i=0;;i++){
            if(c[i] == *curpos){
                if(f[i] == 'T') left = 1;
                else left = 0;
                curpos++;
                break;
            }
        }
        }
        return left;
        
    }
}
int logic(char *s,char* c, char* f){
    curpos = s;
    return logical_recursion(c,f);
}
void append_letter(char*s,char* l_arr){
    int i,n=0;
    for(i=0;s[i] !=0;i++){
        if(islower(s[i])){
            l_arr[n++]=s[i];
        }
    }
    
}
int is_in(char n, char* arr){
    int i;
    for(i=0;arr[i] != 0;i++){
        if(arr[i] == n){
            return 0;
        }
    }
    return 1;
}
void insertionSort(char *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void truth_table(char* arr,int* n_arr,int k, int j,int c){
    if(c==k){
        if(arr[k] == 'T') arr[k] = 'F';
        else if(arr[k] == 'F') arr[k] ='T';
    }
    else if(j == pow(2,c-k)* n_arr[k]){
        n_arr[k]++;
        if(arr[k] == 'T') arr[k] = 'F';
        else if (arr[k] == 'F') arr[k] = 'T';
        
        
    }
}
void print_f(char* f_arr,int c){
    int i=0;
    for(;i<=c-1;i++){
        printf("%c ",f_arr[i]);
    }
    printf("%c\n",f_arr[i]);
}
 
int main() {
    int ch,i=1,j,k,letter_number = 0,counter=1;
    char *str;char* final_array;char *copy_array;char *letter_array;
    int  *num_array;
    str = malloc(sizeof(char));
    ch = getchar(); 
    str[0] = (char)ch;
    while((ch = getchar())!= EOF){
        if(ch != ' ' && ch != '\n'){
            if(islower((char)ch)) ++letter_number;
            str =(char*) realloc(str,sizeof(char)*(i+1));
            str[i++] = (char)ch;
        }
    }
    
    str =(char*) realloc(str,sizeof(char)*(i+1));
    str[i] = '\0';
    
    letter_array = (char*) malloc(letter_number*sizeof(char));
    append_letter(str,letter_array);
    final_array = malloc(sizeof(char));
    final_array[0] = letter_array[0];
    for(j=1;j<letter_number;j++){
        if(is_in(letter_array[j],final_array)){
            final_array = (char*) realloc(final_array,sizeof(char)*(counter+1));
            final_array[counter++] = letter_array[j];
        }
    }
    insertionSort(final_array,counter);
    copy_array = malloc(sizeof(char)*counter);
    for(j=0;j<counter;j++){
        copy_array[j] = final_array[j];
    }
    final_array = (char*) realloc(final_array,sizeof(char)*(counter+1));
    final_array[counter] = 'R';
    num_array = malloc(sizeof(int)*counter);
    for(j=0;j<counter;j++){
        num_array[j]=1;
    }
    print_f(final_array,counter);
    for(j=0;j<counter;j++){
        final_array[j] = 'T';
    }
    for(j=1;j<=pow(2,counter);j++){
        if(logic(str,copy_array,final_array)) final_array[counter] = 'T';
        else final_array[counter] = 'F';
        print_f(final_array,counter);
        for(k=0;k<counter;k++){
            truth_table(final_array,num_array,k,j,counter-1);
        }
    }
    
    
    return 0;
    
}

