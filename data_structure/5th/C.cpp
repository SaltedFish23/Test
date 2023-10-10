#include <iostream>
using namespace std;

int main(){
	int num = 0,res = 0;
	cin >> num;
	int city[50][50] = {0};
	int x_max[50] = {0};
	int y_max[50] = {0};
	for(int i = 0;i < num;i++){
		for(int j = 0;j < num;j++){
			cin >> city[i][j];
			x_max[i] = city[i][j] > x_max[i] ? city[i][j] : x_max[i];
			y_max[j] = city[i][j] > y_max[j] ? city[i][j] : y_max[j];
		}
	}
	for(int i = 0;i < num;i++){
		for(int j = 0;j < num;j++){
			int min = x_max[i] < y_max[j] ? x_max[i] : y_max[j];
			res += min-city[i][j];
		}
	}
	cout << res << endl;
	return 0;
}