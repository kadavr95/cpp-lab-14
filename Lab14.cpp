#include <conio.h>//including input/output libraries
#include <iostream.h>
#include <string>//string type part

void StringCheck(string StringInput, bool *Result);//functions prototypes
void SpaceRemoval(string *StringInput);

void main()//main function
{
	string StringInput;//define variables
	bool Result=true;
	cout<<"Enter string\n";//string input
	getline(cin,StringInput);
	SpaceRemoval(&StringInput);//delete all spaces in string
	StringCheck(StringInput, &Result);//check if string is palindrome or not
	if (Result)//output result
		cout<<"\nString is palindrome";
	else
		cout<<"\nString isn't palindrome";
	getch();//wait for user reaction
}

void SpaceRemoval(string *StringInput)//delete all spaces in string
{
	string::size_type SymbolPosition;
	while ((SymbolPosition=(*StringInput).find(" "))!=string::npos)//while space symbol is in string  //string::npos actually is -1
	{
		(*StringInput).erase(SymbolPosition,1);//delete space symbol
	}
}

void StringCheck(string StringInput, bool *Result)//check if string is palindrome or not
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
