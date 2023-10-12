#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n = 0,k = 0,res = 0,i = 0;
    scanf("%d%d",&n,&k);
    for(;i < k;i++){
        int tmp = 0;
        scanf("%d",&tmp);
        if(i == 0){
            res = tmp;
        }
        else{
            res = tmp < res ? tmp : res;
        }
    }
    for(;i < n;i++){
        int tmp = 0;
        scanf("%d",&tmp);
        res = tmp > res ? tmp : res;
    }
    cout << res << endl;
    return 0;
}