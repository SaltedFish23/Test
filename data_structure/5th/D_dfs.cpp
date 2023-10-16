#include <iostream>
using namespace std;

int main(){
    int n = 0,res = 0,max_x = 0,max_y = 0;
    //int all[10][10][2] = {0}; //[0]为是否有鱼，[1]为是否被吃
    cin >> n;
    int (*path)[3] = new int[n][3];
    int (*all2)[3] = new int[n][3];
    int all[10004][2] = {0};
    for(int i = 0;i < n;i++){
        int tmp_x = 0,tmp_y = 0;
        cin >> tmp_x >> tmp_y;
        //all[tmp_x+1][tmp_y+1][0] = 1;
        //all[tmp_x+1][tmp_y+1][1] = 1;
        //all[tmp_x+1][0][1] += 1;
        //all[0][tmp_y+1][1] += 1;
        all2[i][0] = tmp_x;
        all2[i][1] = tmp_y;
        all[tmp_x][0] += 1;
        all[tmp_y][1] += 1;
        all2[i][2] = 1;
        //max_x = tmp_x > max_x ? tmp_x : max_x;
        //max_y = tmp_y > max_y ? tmp_y : max_y;
    }
    /**for(int i = 0;i < n;i++){
        int res1 = 1;
        path[0][0] = all2[0][0];
        path[0][1] = all2[0][1];
        all[path[0][0]+1][path[0][1]+1][1] = 0;
        all[path[0][0]+1][0][1] --;
        all[0][path[0][1]+1][1] --;
        for(int j = 1;j < n && j > 0;j++){
            int flag = 0;
            if(all[path[j-1][0]+1][0][1] > 0){
                int next_x = path[j-1][0],next_y = 0;
                for(int k = 0;k <= max_y;k++){
                    if(all[next_x+1][k+1][0] == 1 && all[next_x+1][k+1][1] == 1){
                        next_y = k;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    res1 += 1;
                    path[j][0] = next_x;
                    path[j][1] = next_y;
                    all[next_x+1][next_y+1][1] = 0;
                    all[next_x+1][0][1] --;
                    all[0][next_y+1][1] --;
                }
            }
            if(flag == 0 && all[0][path[j-1][1]+1][1] > 0){
                int next_x = 0,next_y = path[j-1][1];
                for(int k = 0;k <= max_x;k++){
                    if(all[k+1][next_y+1][0] == 1 && all[k+1][next_y+1][1] == 1){
                        next_x = k;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    res1 += 1;
                    path[j][0] = next_x;
                    path[j][1] = next_y;
                    all[next_x+1][next_y+1][1] = 0;
                    all[next_x+1][0][1] --;
                    all[0][next_y+1][1] --;
                }
            }
            res = res > res1-1 ? res : res1-1;
            if(flag == 0){
                j--;
                for(;j >= 0;j--){
                    if(all[path[j][0]+1][0][1] > 0 || all[0][path[j][1]+1][1] > 0){
                        flag = 1;
                        j--;
                        break;
                    }
                    res1--;
                }
            }
            if(flag == 0){
                break;
            }
        }
        for(int j = 0;j < n;j++){
            all[all2[j][0]+1][all2[j][1]+1][1] = 1;
            all[all2[j][0]+1][0][1] += 1;
            all[0][all2[j][1]+1][1] += 1;
        }
    }**/
    int now_x = all2[0][0],now_y = all[0][1],branch = 0;
    all2[0][2] = 0;
    path[0][0] = now_x;
    path[0][1] = now_y;
    for(int i = 1;i < n && i >= 0;i++){
        int flag = 0,res1 = 0;
        for(int j = 1;j < n;j++){
            int x = all2[j][0],y = all2[j][1];
            if((all[x][0] > 1 || all[y][1] > 1) && all2[j][2] == 1 && (now_x == x || now_y == y)){
                all2[j][2] = 0;
                res1 += 1;
                all[x][0] -= 1;
                all[y][1] -= 1;
                path[i][0] = x;
                path[i][1] = y;
                path[i][2] = j;
                now_x = x;
                now_y = y;
                flag = 1;
                break;
            }
        }
        res = res > i ? res : i;
        if(flag == 0){
            branch += 1;
            for(i--;i >= 0;i--){
                int x = path[i][0],y = path[i][1];
                if(all[x][0] > 1 || all[x][1] > 1){
                    flag = 1;
                    now_x = x;
                    now_y = y;
                    break;
                }
            }
        }
        if(flag == 0){
            break;
        }
    }
    cout << n-branch-1;
    delete path;
    delete all2;
    return 0;
}