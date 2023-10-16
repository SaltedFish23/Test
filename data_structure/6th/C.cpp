#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n = 0,k = 0,res = 0,i = 0;
    scanf("%d%d",&n,&k);
    int *kth = new int[k];
    for(;i < k;i++){
        int tmp = 0;
        kth[i] = tmp;
        if(kth[0] > tmp){
            kth[i] = kth[0];
            kth[0] = tmp;
        }
    }
    for(;i < n;i++){
        int tmp = 0;
        scanf("%d",&tmp);
        if(tmp > kth[0]){
            int min = kth[1],pos_min = 1;
            for(int j = 2;j < k;j++){
                if(kth[j] < min){
                    min = kth[j];
                    pos_min = j;
                }
            }
            kth[pos_min] = tmp;
            kth[0] = min;
        }
    }
    cout << kth[0] << endl;
    return 0;
}