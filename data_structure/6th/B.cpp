#include <iostream>
using namespace std;

int main(){
    int n = 0,m = 0;
    int (*map)[102] = new int[102][102];
    cin >> n >> m;
    for(int i = 0;i <= n+1;i++){
        for(int j = 0;j <= m+1;j++){
            if(i >= 1 && i <= n && j >= 1 && j <= m){
                int tmp = 0;
                cin >> tmp;
                if(tmp == 1){
                    map[i][j] = 1;
                }
                else{
                    map[i][j] = 0;
                }
            }
            else{
                map[i][j] = 0;
            }
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(map[i][j] == 1){
                if(map[i-1][j] == 0){
                    res += 1;
                }
                if(map[i+1][j] == 0){
                    res += 1;
                }
                if(map[i][j-1] == 0){
                    res += 1;
                }
                if(map[i][j+1] == 0){
                    res += 1;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}