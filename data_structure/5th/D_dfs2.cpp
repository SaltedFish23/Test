#include <iostream>
using namespace std;
int all[10004][3] = {0};
int branch = 0,n = 0,res = 0;
int search(int i);
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> all[i][0] >> all[i][1];
        all[i][2] = 1;
    }
    for(int i = 0;i < n;i++){
        branch += search(i);
    }
    cout << n-branch << endl;
    //cout << res;
    return 0;
}
int search(int i){
    if(all[i][2] == 0){
        return 0;
    }
    //if(m == -1){
        int x = all[i][0],y = all[i][1],flag = 0;
            all[i][2] = 0;
            for(int j = 0;j < n;j++){
                int x1 = all[j][0],y1 = all[j][1];
                if(all[j][2] == 1 && (x1 == x || y1 == y)){
                    flag = 1;
                    //res += 1;
                    search(j);
                }
            }
    //}
    /**else{
        int x0 = all[m][0],y0 = all[m][1],x = all[i][0],y = all[i][1],flag = 0;
        if(x0 != x && y0 != y){
            return 0;
        }
        all[i][2] = 0;
        for(int j = 0;j < n;j++){
            int x1 = all[j][0],y1 = all[j][1];
            if(all[j][2]==1&&(x1==x||y1==y)){

            }
        }
    }**/
    return 1;
    /**if(flag == 0){
        branch += 1;
    }**/
}