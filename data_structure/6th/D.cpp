#include <iostream>
using namespace std;

int main(){
    int n = 0,m = 0;
    int (*all)[1000] = new int[1000][1000];
    int res[1000] = {0};
    //int none[1000] = {1};
    cin >> m >> n;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin >> all[i][j];
        }
    }
    int pos_res = 0;
    for(int i = 0;i < m;i++){
        int min = all[i][0],pos_min = 0;
        for(int j = 1;j < n;j++){
            if(all[i][j] < min){
                min = all[i][j];
                pos_min = j;
            }
        }
        int flag = 1;
        for(int k = 0;k < m;k++){
            if(all[k][pos_min] > min){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            res[pos_res++] = min;
        }
    }
    if(pos_res == 0){
        cout << -1;
    }
    else{
        for(int i = 0;i < pos_res;i++){
            if(pos_res-i > 1){
                cout << res[i] << ' ';
            }
            else{
                cout << res[i];
            }
        }
    }
    
    return 0;
}