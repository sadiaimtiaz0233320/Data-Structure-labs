#include <iostream>
using namespace std;
int main (){
	int arr[3]={10 ,20 , 30};
	int i = 1;
	int newValue = 50;
	arr[i]= newValue;
	for(i=0;i < 3;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
	
}
