#include <conio.h>//including input/output libraries
#include <iostream.h>
#include <string>//string type part

void StringCheck(string StringInput, bool *Result);

void main()//main function
{
	string StringInput;//define variables
	bool Result=true;
	cout<<"Enter string\n";//string input
	cin>>StringInput;
	StringCheck(StringInput, &Result);//check if string is palindrome or not
	if (Result)//output result
		cout<<"\nString is palindrome";
	else
		cout<<"\nString isn't palindrome";
	getch();//wait for user reaction
}

void StringCheck(string StringInput, bool *Result)
{
	int StringLength;
	string StringSymbolFirst,StringSymbolLast;
	StringLength=StringInput.length();//get string length
	StringSymbolFirst=StringInput.substr(0, 1);//get first and last symbols of string
	StringSymbolLast=StringInput.substr(StringLength-1, StringLength-1);
	if (StringSymbolFirst!=StringSymbolLast)//compare last symbols of string
		*Result=false;//if not same stop checking
	else
	{
		if (StringLength>3)//if same and string can be cropped
			StringCheck(StringInput.substr(1, StringLength-2), Result);//recursive call of function for cropped string
	}
}
