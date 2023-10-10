#include <iostream>

using namespace std;

int main(){
	int num = 0;
    int all[200005] = {0};
    cin >> num;
    for(int i = 0;i < num;i++){
        int min = 0,max = 0;
        cin >> min >> max;
        for(int j = 2*min;j <= 2*max;j++){
            all[j] = 1;
        }
        /**if(all[min] == 0){
            all[min] = 2;
        }
        if(all[max] == 0){
            all[max] = 2;
        }**/
    }
    int min = -1;
    for(int i = 0;i < 200005;i++){
        if(min == -1 && all[i] == 1){
            min = i/2;
        }
        if(min != -1 && all[i] == 0){
            cout << min << ' ' << (i-1)/2 << endl;
            min = -1;
        }
    }
}
