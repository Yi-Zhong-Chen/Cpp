///uva 100 3n+1


#include<stdio.h>
#define max(num1, num2)((num1) > (num2) ? num1 : num2)
int judge(int num){
    int cnt=0;
    while(num!=1){
        if(num%2){
            num*=3;
            num+=1;
        }
        else{
            num/=2;
        }
        cnt+=1;
    }
    return cnt+1;
}
int main()
{
    int lower;
    int upper;
    int result;
    int i;
    while(scanf("%d %d", &lower, &upper) == 2){
        int l = lower;
        int u = upper;
        if(l>u){
            int temp = l;
            l = u;
            u = temp;
        }
        result = judge(l);
        for(i=l+1;i<=u;i++){
            result = max(result, judge(i));
        }
        printf("%d %d %d\n", lower, upper, result);    
    }
 
    return 0;
}