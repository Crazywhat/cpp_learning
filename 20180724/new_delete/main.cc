 ///
 /// @file    main.cc
 //
 
#include <iostream>
using namespace std;

int main(){

	int *p=new int(34);
	int *ph=new int[10]();

	cout<<*p<<endl;

	for(int i=0;i!=10;++i){
		cout<<ph[i]<<" ";
	}
	cout<<endl;



	delete p;
	delete [] ph;
	
	return 0;
}
