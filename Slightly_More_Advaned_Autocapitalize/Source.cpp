#include <sstream>
#include <string>
#include <iostream>

using namespace std;

string AutoCapitalize(string inputString)
{
	string reconstituted_Input;
	bool capitalize_next_letter = 0;
	bool dont_capitalize = false;
	bool decapitated = false;

	reconstituted_Input += toupper(inputString[0]);//uvijek prvo slovo povecaj, pokazuje tocan broj slova i ne ukljucuje tocku

	for (int i = 1; i < inputString.length(); i++)
	{
		if ( inputString[i] == '.')
		{
				capitalize_next_letter = true;
		}

		if (capitalize_next_letter == true)		//if the character in front of a period is "space", the check the character after that, if that character is an already capitalized letter, remove the capitalize command, do this 4 times
		{
			if(isupper(inputString[i]))
			{
				dont_capitalize = true;
			}
		}

		if (capitalize_next_letter == true && dont_capitalize == false)
		{
			if (islower(inputString[i])) //Malo slovo u Veliko
			{
				inputString[i] = toupper(inputString[i]);
				capitalize_next_letter = false;
				dont_capitalize = true; //rjesava error gdje smanji sljedeće slovo nakon što smo povećali traženo slovo
			}
		}

		if ((capitalize_next_letter == false) && (dont_capitalize == false)) //kada capitalize nije na true	i kada nije malo slovo
		{
			if (isupper(inputString[i])) //Veliko slovo u malo
			{
				inputString[i] = tolower(inputString[i]);
			}
		}

		if (capitalize_next_letter == true && dont_capitalize == true)
		{
			capitalize_next_letter = false;
		}

		dont_capitalize = false;
		reconstituted_Input += inputString[i];
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