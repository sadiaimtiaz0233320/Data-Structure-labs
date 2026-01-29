#include<iostream>
using namespace std;
int main(){
	int arr[6]={1,2,6,8,4,0};
	int num;
	cout<<"Enter number to search"<<endl;
	cin>>num;
	for(int i=0; i<6; i++){
		if (arr[i] == num){
			cout<<"Found at index "<< i << endl ;
		}
	
	else{
	
	cout<<"Not Found";
}
	return 0;
	}
}
	

