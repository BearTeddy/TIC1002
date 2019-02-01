#include <cstdio>
#include <iostream>

using namespace std;

void print_solid_slanted_pyramid( int height )
{
	for (int i=1;i<=height;i++){
		for(int j=0; j<i; j++){
		cout << "#";
		}
		cout<<endl;
	}
}

void print_solid_symmetric_pyramid( int height )
{
	int count=1;
	for (int i=0;i<height;i++){
		for(int j=height+i;j>0;j--){
			if(j<=count){
				cout<<"#";
			}
			else
			{
				cout<<" ";
			}
			
		}
		count+=2;
		cout<<endl;
	}
}

void print_hollow_symmetric_pyramid( 
              int height, char outer, char inner )
{
		int count=1;
	for (int i=0;i<height;i++){
		for(int j=height+i;j>0;j--){
			if(j<=count){
				if(j!=count && j!=1 && i!=height-1){
					cout << inner;
				}
				else
				{
					cout<< outer;
				}
			}
			else
			{
				cout<<" ";
			}
			
		}
		count+=2;
		cout<<endl;
	}
}



int main()
{
	//Comment / modify the following statements to test
	//You can attempt the parts independently

	//print_solid_slanted_pyramid(4);

	//print_solid_symmetric_pyramid(4);

	//print_hollow_symmetric_pyramid( 4, '#', '$');
	
	int input;
	cin >> input;
	//print_solid_slanted_pyramid(input);
	print_solid_symmetric_pyramid(input);
	return 0;
}
