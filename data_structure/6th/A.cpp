#include <iostream>
using namespace std;

int main(){
    int num = 0;
    cin >> num;
    int *all = new int[num];
    int *res = new int[num];
    int *test = new int[2*num];
    for(int i = 0;i < num;i++){
        cin >> all[i];
    }
    for(int i = 0;i < 2*num;i++){
        test[i] = i;
    }
    /**int min = all[2*num]-1;
    for(int i = 0;i < num;i++){
        all[i] = min;
    }**/
    for(int i = 0,tag = 0,pos_all = 0,pos_end = num;pos_all < num;i++){
        if(tag == 0){
            res[test[i]] = all[pos_all++];
            tag = 1;
        }
        else if(tag == 1){
            test[pos_end++] = test[i];
            tag = 0;
        }
    }
    for(int i = 0;i < num;i++){
        if(i < num-1){
            cout << res[i] << ' ';
        }
        else{
            cout << res[i];
        }
    }
    return 0;
}