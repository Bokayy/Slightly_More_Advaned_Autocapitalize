#include <sstream>
#include <string>
#include <iostream>

using namespace std;

string AutoCapitalize(string inputString)
{
	string reconstituted_Input;
	bool capitalize = 0;

	reconstituted_Input += toupper(inputString[0]);

	for (int i = 1; i < inputString.length(); i++)
	{
		if (inputString[i] == '.')
		{
			capitalize = true;
		}

		if (capitalize)
		{
			switch (inputString[i])
			{

			case(97):	//mala slova
			case(98):
			case(99):
			case(100):
			case(101):
			case(102):
			case(103):
			case(104):
			case(105):
			case(106):
			case(107):
			case(108):
			case(109):
			case(110):
			case(111):
			case(112):
			case(113):
			case(114):
			case(115):
			case(116):
			case(117):
			case(118):
			case(119):
			case(120):
			case(121):
			case(122):
				inputString[i] = toupper(inputString[i]);
				capitalize = false;
			}
		}

		else 
		{
			switch (inputString[i]) {

			case(65):	//velika slova
			case(66):
			case(67):
			case(68):
			case(69):
			case(70):
			case(71):
			case(72):
			case(73):
			case(74):
			case(75):
			case(76):
			case(77):
			case(78):
			case(79):
			case(80):
			case(82):
			case(83):
			case(84):
			case(85):
			case(86):
			case(87):
			case(88):
			case(89):
			case(90):
				inputString[i] = tolower(inputString[i]);
			}
		}
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