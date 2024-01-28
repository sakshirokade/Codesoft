#include<iostream>
using namespace std;

int main()
{
	double a,b;
	double ans;
	char ch;
	
	cout<<"Enter 1 st number : ";
	cin>>a;
	cout<<"Enter 2 nd number : ";
	cin>>b;
	cout<<"Enter choice operation (+,-,*,/): ";
	cin>>ch;
	
	switch(ch)
	{
		case '+':
			ans = a + b;
			break;
		case '-':
			ans = a - b;
			break;
		case '*':
			ans = a * b;
			break;
		case '/': 
		 		if(b !=0)
				{
				 	ans = a / b;
				} 
				else
				{
					cout<<"Eror , division by zero is not possible !!!";
					return 1;
				} 
				break;
		default :
			cout<<"invalid operation !!!";
			return 1;
			
		    
	}
	cout<<"Result : "<<ans<<endl;
	return 0;
	
}
