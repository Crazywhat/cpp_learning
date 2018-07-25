 ///
 /// @file    main.cc
 #include <iostream>
 #include <string>
 #include <cstring>
 #include <stdio.h>
using namespace std;

int main(){



	string s1;	
	char ch='a';
	while(1)
	{
	
		getline(cin,s1);
		
		//s1.erase(s1.begin(),s1.end()-1);

	//	s1.append(5,ch);
	//	s1.append(" , fucking ?");
    //  s1.append("good boy",5);

	//	cout<< s1.insert(3," so fucking good ")<<endl;
	//	s1.insert(s1.begin(),10,'F');

	//	cout<<"capacity :"<<s1.capacity()<<"max_size :"<<s1.max_size()<<endl;
	//	cout<<endl<<s1[50]<<endl;
	//	cout<<endl<<s1.at(50)<<endl;

	//	cout<<(s1<"abc")<<endl;
	
		cout<<s1.compare(0,3,"zabc")<<endl;

	}


	return 0;
}
