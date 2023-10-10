#include <iostream>
using namespace std;

int main(){
	int nums[100000] = {0};
	int len = 0;
	int num = 0;
	while(cin >> nums[len++]){
		if(cin.get() == '\n') break;
	}
	for(int i = 0;i < len;i++){
		int flag = 0;
		for(int j = i;j < len;j++){
			if(nums[j] > nums[i]){
				cout << j-i << " ";
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			cout << 0 << " ";
		}
	}
	return 0;
}