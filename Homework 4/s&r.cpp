#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>

using namespace std;

int main(void)
{
	int x = 0;
	while (x != 1)
	{
		cout << "Please enter your filename: ";
		string nameOfFile;
		cin >> nameOfFile;

		string thefile, tmp;

		ifstream input(nameOfFile + ".resx");

		while (getline(input, tmp)) {
			thefile += tmp;
		}

		system("pause");

		thefile = thefile.substr(0, thefile.length() - 7);

	regex e("</data>");   // matches words
	regex f("> *<");
	regex g(".*r>");

	thefile = regex_replace(thefile, f, "><");
	thefile = regex_replace(thefile, e, "</data>\n");
	thefile = regex_replace(thefile, g, "");

	//replace(thefile.begin(), thefile.end(), thefile, "{2, 1000}", "");
	//replace(thefile, "\r\n", "");
	//replace(thefile, "</data>", "</data>\n");
	ofstream myfile;
	myfile.open(nameOfFile + ".resx");
	myfile << thefile;
	myfile.close();
	}
	return 0;
}
