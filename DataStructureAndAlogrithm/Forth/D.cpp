#include <iostream>
//#include <vector>

using namespace std;

int money(int* poi,int k);
int n;
int** bank;
int* len;
int main(){
    int k = 0;
    cin >> n >> k;
    len = (int*)malloc(sizeof(int)*n);
    bank = (int**)malloc(sizeof(int*)*n);
    for(int i = 0;i < n;i++){
        cin >> len[i];
        for(int j = 0;j < len[i];j++){
            cin >> bank[i][j];
        }
    }
    int* poi = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i < n;i++){
        poi[i] = 0;
    }
    cout << money(poi,k) << endl;
    return 0;
}

int money(int* poi,int k){
    if(k == 0){
        delete poi;
        return 0;
    }
    int res = 0;
    for(int i = 0;i < n;i++){
        if(poi[i] < len[i]){
            int* poi1 = (int*)malloc(sizeof(int)*n);
            for(int j = 0;j < n;j++){
                poi1[j] = poi[j];
            }
            int tmp = bank[i][poi1[i]++];
            tmp += money(poi1,k--);
            res = (tmp > res) ? tmp : res;
        }
    }
    delete poi;
    return res;
}