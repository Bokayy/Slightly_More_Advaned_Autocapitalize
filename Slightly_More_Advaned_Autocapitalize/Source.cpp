#include <sstream>
#include <string>
#include <iostream>

using namespace std;

string AutoCapitalize(string inputString)
{
	string reconstituted_Input;
	bool capitalize = 0;
	bool capitalized = false;
	bool decapitated = false;

	reconstituted_Input += toupper(inputString[0]);//uvijek prvo slovo povecaj, pokazuje tocan broj slova i ne ukljucuje tocku

	for (int i = 1; i < inputString.length(); i++)
	{
		if ( inputString[i] == '.')
		{
				capitalize = true;
		}

		if (capitalize == true)		//if the character in front of a period is "space", the check the character after that, if that character is an already capitalized letter, remove the capitalize command, do this 4 times
		{
			if (inputString[i] < 91 && inputString[i] > 64)
			{
				capitalized = true;
			}
		}

		if (capitalize == true && capitalized == false)
		{
			switch (inputString[i])
			{
			case (97):	//povećaj sa malog slova na veliko
			case (98):
			case (99):
			case (100):
			case (101):
			case (102):
			case (103):
			case (104):
			case (105):
			case (106):
			case (107):
			case (108):
			case (109):
			case (110):
			case (111):
			case (112):
			case (113):
			case (114):
			case (115):
			case (116):
			case (117):
			case (118):
			case (119):
			case (120):
			case (121):
			case (122):
				inputString[i] = toupper(inputString[i]);
				capitalize = false;
				capitalized = true; //rjesava error gdje smanji slovo nakon sto smo ga mi namjerno povecali
			}

		}

		if ((capitalize == false) && (capitalized == false)) //kada capitalize nije na true	i kada nije malo slovo
		{

			switch (inputString[i])
			{
			case (65):	//veliko slovo na malo
			case (66):
			case (67):
			case (68):
			case (69):
			case (70):
			case (71):
			case (72):
			case (73):
			case (74):
			case (75):
			case (76):
			case (77):
			case (78):
			case (79):
			case (80):
			case (81):
			case (82):
			case (83):
			case (84):
			case (85):
			case (86):
			case (87):
			case (88):
			case (89):
			case (90):
				inputString[i] = tolower(inputString[i]);
				decapitated = true;
			}
		}

		if (capitalize == true && capitalized == true)
		{
			capitalize = false;
		}

		capitalized = false;
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