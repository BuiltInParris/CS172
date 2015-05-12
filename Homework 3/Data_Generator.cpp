//----------------------------------------------------------------------------
//
//  Data_Generator program
//      Type: Program
//
//  This program is designed to create a class skeleton based on user input.
//  Author: Stevie Parris
//  Date: 4/19/2014
//
//  Modified: 
//
//----------------------------------------------------------------------------


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iomanip>

using namespace std;

int main()
{
	ofstream hFile, cppFile;

	string tempConst;

	vector<string> listOperator;
	vector<string> listPVN; // list of private variable names
	vector<string> listPVT; // list of private variable types

	string fileName; // this is also the classname

	//MY H FILE
	//creating creation comments
	cout << "Enter class name: ";
	getline(cin, fileName);
	hFile.open(fileName + ".h");
	cppFile.open(fileName + ".cpp");
	cout << "Enter purpose of class: ";
	getline(cin, tempConst);

	hFile << "//----------------------------------------------------------------------------\n//\n";
	hFile << fixed << setw(80) << "//  " << fileName << " class\n";
	hFile << "//      Header\n//\n";
	hFile << "//  " << tempConst << endl;

	cppFile << "//----------------------------------------------------------------------------\n//\n";
	cppFile << "//  " << fixed << setw(80) << fileName << " class\n";
	cppFile << "//      Implementation\n//\n";
	cppFile << "//  " << tempConst << endl;

	//Prompt user for input to include in the comment header
	cout << "Enter your name: ";
	getline(cin, tempConst);
	hFile << "//  Author: " << tempConst << endl;
	cppFile << "//  Author: " << tempConst << endl;
	cout << "Enter the date: ";
	getline(cin, tempConst);
	hFile << "//  Date: " << tempConst << endl;
	hFile << "//\n" << "//  Modified: \n";
	hFile << "//\n//----------------------------------------------------------------------------\n\n";

	cppFile << "//  Date: " << tempConst << endl;
	cppFile << "//\n" << "//  Modified: \n";
	cppFile << "//\n//----------------------------------------------------------------------------\n\n";

	//get operator information


	cout << "Would you like to use an operator? (y or n)" << endl;
	getline(cin, tempConst);
	while (tempConst != "n")
	{
		cout << "Which operator: ";
		getline(cin, tempConst);
		listOperator.push_back(tempConst);
		cout << "Would you like to use an operator? (y or n)" << endl;
		getline(cin, tempConst);

	}

	//test to see if defined
	hFile << "#ifndef __" << fileName << "__" << endl
		<< "#define __" << fileName << "__" << endl << endl;

	//header .h
	hFile << "#include <string>" << endl;
	hFile << "#include <iostream>" << endl;
	hFile << "#include <vector>" << endl;
	hFile << "#include <fstream>" << endl;
	hFile << "using namespace std;" << endl << endl;
	hFile << "//  Date: " << tempConst << endl;
	hFile << "//\n" << "//  Modified: \n";
	hFile << "//\n//----------------------------------------------------------------------------\n\n";

	//header .cpp
	cppFile << "#include <string>" << endl;
	cppFile << "#include <iostream>" << endl;
	cppFile << "#include <vector>" << endl;
	cppFile << "#include <fstream>" << endl;
	cppFile << "#include \"" << fileName << ".h\"" << endl;
	cppFile << "using namespace std;" << endl << endl;

	//Creating the class
	hFile << "//----------------------------------------------------------------------------\n";
	hFile << "//----------------------------------------------------------------------------\n\n";
	hFile << "class " << fileName << endl;
	hFile << "{" << endl; //declare class
	hFile << "	public:" << endl;
	hFile << "		//------------------------------------------------------\n";
	hFile << "		//----- Constructors -----------------------------------\n";
	hFile << "		//------------------------------------------------------\n\n";
	hFile << "			" << fileName << "();" << endl; // create default constructor

	cppFile << "//------------------------------------------------------\n";
	cppFile << "//----- Constructors -----------------------------------\n";
	cppFile << "//------------------------------------------------------\n\n";
	cppFile << "		" << fileName << "::" << fileName << "() {  }" << endl << endl; // create default constructor


	//obtain private variables to use in class
	cout << "Do you have any private variables? (y or n)" << endl;
	getline(cin, tempConst);

	while (tempConst != "n")
	{
		cout << "What is its type? (ex: int, float, etc.)\n";
		getline(cin, tempConst);
		listPVT.push_back(tempConst);
		cout << "What is its name? (an underscore will be inserted after the name)\n";
		getline(cin, tempConst);
		listPVN.push_back(tempConst);

		cout << "Do you have another variable? (y or n)\n";
		getline(cin, tempConst);
	}

	//get number of private variables
	int numbEntries = listPVN.size();
	//this will hold the list of private variables
	string holder;
	if (numbEntries > 0)
		holder = listPVT[0] + " " + listPVN[0];
	if (numbEntries > 1)
	{
		for (int j = 1; j != numbEntries; j++)
			holder = holder + ", " + listPVT[j] + " " + listPVN[j];
	}

	//Create constructor directly, with all attributes in list form in the .h
	hFile << "			" << fileName << "(" << holder << ");" << endl;

	//create list constructor
	cppFile << "		" << fileName << "::" << fileName << "(" << holder << ")" << endl;
	cppFile << "		{" << endl;
	if (numbEntries > 0)
	{
		for (int j = 0; j != numbEntries; j++)
			cppFile << "			" << listPVN[j] << "_ = " << listPVN[j] << ";" << endl;
	}
	cppFile << "		}" << endl << endl;

	// create copy constructor in the .h file
	hFile << "			" << fileName << "(const " << fileName << " & my" << fileName << ");" << endl << endl;
	cppFile << "		" << fileName << "::" << fileName << "(const " << fileName << " & my" << fileName << ")" << endl; // create in .cpp file
	cppFile << "		{" << endl;
	if (numbEntries > 0)
	{
		for (int j = 0; j != numbEntries; j++)
			cppFile << "			" << listPVN[j] << "_ = my" << fileName << ".get" << listPVN[j] << "();" << endl;
	}
	cppFile << "		}" << endl << endl;

	hFile << "		//------------------------------------------------------\n";
	hFile << "		//------- Destructor -----------------------------------\n";
	hFile << "		//------------------------------------------------------\n\n";
	hFile << "			~" << fileName << "();" << endl << endl; // create destructor
	cppFile << "//------------------------------------------------------\n";
	cppFile << "//------- Destructor -----------------------------------\n";
	cppFile << "//------------------------------------------------------\n\n";
	cppFile << "		" << fileName << "::~" << fileName << "()  { }" << endl << endl; // create destructor

	hFile << "		//------------------------------------------------------\n";
	hFile << "		//------- Inspectors -----------------------------------\n";
	hFile << "		//------------------------------------------------------\n\n";
	cppFile << "//------------------------------------------------------\n";
	cppFile << "//------- Inspectors -----------------------------------\n";
	cppFile << "//------------------------------------------------------\n\n";

	//getter methods, the first loop is the .h the second the .cpp

	if (numbEntries > 0)
	{
		for (int j = 0; j != numbEntries; j++)
		{
			hFile << "			// This method gets the value of " << listPVN[j] << endl;
			hFile << "			" << listPVT[j] << " get" << listPVN[j] << "() const;" << endl << endl;
		}
	}

	if (numbEntries > 0)
	{
		for (int j = 0; j != numbEntries; j++)
		{
			cppFile << "		// This method gets the value of " << listPVN[j] << endl;
			cppFile << "		" << listPVT[j] << " " << fileName << "::get" << listPVN[j] << "() const\n";
			cppFile << "		{" << endl;
			cppFile << "			return " << listPVN[j] << "_;" << endl;
			cppFile << "		}" << endl << endl;
		}
	}
	hFile << "\n		//------------------------------------------------------\n";
	hFile << "		//-------- Mutators ------------------------------------\n";
	hFile << "		//------------------------------------------------------\n\n";

	cppFile << "//------------------------------------------------------\n";
	cppFile << "//-------- Mutators ------------------------------------\n";
	cppFile << "//------------------------------------------------------\n\n";


	//setter methods, the first loop is the .h the second the .cpp
	if (numbEntries > 0)
	{
		for (int j = 0; j != numbEntries; j++)
		{
			hFile << "			// This method sets the value of " << listPVN[j] << " to the value of the parameter." << endl;
			hFile << "			void set" << listPVN[j] << "(" << listPVT[j] << " " << listPVN[j] << ");" << endl << endl;
		}
	}

	if (numbEntries > 0)
	{
		for (int j = 0; j != numbEntries; j++)
		{
			cppFile << "		// This method sets the value of " << listPVN[j] << " to the value of the parameter." << endl;
			cppFile << "		void " << fileName << "::set" << listPVN[j] << "(" << listPVT[j] << " " << listPVN[j] << ")" << endl;
			cppFile << "		{" << endl;
			cppFile << "				" << listPVN[j] << "_ = " << listPVN[j] << ";" << endl;
			cppFile << "		}" << endl << endl;
		}
	}

	hFile << "\n		//------------------------------------------------------\n";
	hFile << "		//-------- Facilitators --------------------------------\n";
	hFile << "		//------------------------------------------------------\n\n";

	cppFile << "\n//------------------------------------------------------\n";
	cppFile << "//-------- Facilitators --------------------------------\n";
	cppFile << "//------------------------------------------------------\n\n";
	// toString() method in the .cpp
	cppFile << "		string " << fileName << "::toString()" << endl;
	cppFile << "		{\n";
	cppFile << "			//---------------------------------------------------------------------\n";
	cppFile << "			//  Fill this code with code that changes your dataType into a string" << endl;
	cppFile << "			//---------------------------------------------------------------------\n";
	cppFile << "			return \"\";" << endl;
	cppFile << "		}\n";

	// output() method .cpp
	cppFile << "//------------------------------------------------------\n\n";
	cppFile << "		void " << fileName << "::" << "output(ostream &out) const\n";
	cppFile << "		{\n";
	cppFile << "			out << toString();\n";
	cppFile << "		}\n";

	// toString() and output method .h
	hFile << "		//------------------------------------------------------\n";
	hFile << "		//return " << fileName << " in string form\n\n";
	hFile << "			string toString();" << endl;
	hFile << "		//------------------------------------------------------\n\n";
	hFile << "		//------------------------------------------------------\n";
	hFile << "		//insert " << fileName << " in output stream\n\n";
	hFile << "			void output(ostream &out) const;\n";
	hFile << "		//------------------------------------------------------\n\n";
	//declare private variables in .h
	hFile << "	private:\n";
	if (numbEntries > 0)
	{
		for (int j = 0; j != numbEntries; j++)
			hFile << "		" << listPVT[j] << " " << listPVN[j] << "_" << ";" << endl;
	}
	hFile << "};" << endl;

	if (listOperator.size() > 0)
	{
		for (int j = 0; j < listOperator.size(); j++)
		{
			if (listOperator[j] == "<<")
			{
				hFile << "ostream& operator" << listOperator[j] << " (ostream & out, const " << fileName << " & myFile);\n\n";
				cppFile << "		ostream& operator" << listOperator[j] << " (ostream & out, const " << fileName << " & myFile)\n";
				cppFile << "		{\n";
				cppFile << "			" << fileName << ".output();\n";
				cppFile << "			return out;\n";
				cppFile << "		}\n";
			}
		}
	}



	hFile << "//----------------------------------------------------------------------------" << endl;
	hFile << "//----------------------------------------------------------------------------" << endl << endl;
	hFile << "#endif";

	ofstream testFile;
	testFile.open(fileName + "Tester.cpp");

	testFile << "#include <iostream>" << endl;
	testFile << "#include <string>" << endl;
	testFile << "#include \"" << fileName << ".h\"" << endl;
	testFile << "using namespace std;" << endl;
	testFile << "int main(void)\n{" << endl;
	testFile << "	" << fileName << "();\n";
	testFile << "}" << endl;


}
