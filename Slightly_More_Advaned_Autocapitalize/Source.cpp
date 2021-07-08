#include <sstream>
#include <string>
#include <iostream>

using namespace std;

string AutoCapitalize(string inputString)
{
	string reconstituted_Input;
	bool afterDelineator = 0;
	char temp;

	reconstituted_Input = toupper(inputString[0]);	//uvijek prvo slovo povecaj, pokazuje tocan broj slova i ne ukljucuje tocku

	for (int i = 1; i <= inputString.length(); i++)
	{
		if (afterDelineator)
		{
			inputString[i] = toupper(inputString[i]);
			afterDelineator = false;
		}

		if (inputString[i] == '.')
		{
			inputString[i + 1] = toupper(inputString[i + 1]);
			//reconstituted_Input += inputString[i+1];
			afterDelineator++;
			reconstituted_Input.append(".");
		}

		else
		{
			reconstituted_Input += inputString[i];
		}

	}

	return reconstituted_Input;

}


int main()
{
	string input;
	cout << "input: " << endl;
	getline(cin, input);

	string output = AutoCapitalize(input);

	cout << output;
	return 0;
}