#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>


using namespace std;

string convert(int value)
{
	string result = "";

	while (value != 0)
	{
		int remainder = value % -2;
		value = value / -2;

		if (remainder < 0)
		{
			remainder += 2;
			value += 1;
		}

		stringstream ss;
		ss << remainder;
		string aux;
		ss >> aux;
		result = aux + result;
	}

	return result;
}

int main(){

    int n;
    cin >> n;
    if(n == 0)
        cout << 0 << endl;
    else
        cout << convert(n) << endl;
    return 0;
}
