//-----------*-*-C++-*-*-------------------------------------------
// Recursive algorithm to test equality in a vector

#include <iostream>

using namespace std;
#include <vector>;

bool allEqual(vector<int>&v, int lo, int hi);
bool test = false;

int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(1);
	v.push_back(1);
	bool john = allEqual(v, 0, v.size()-1);
	if (john)
		cout << "They are equal indeed." << endl;
	system("pause");
}	


bool allEqual(vector<int>&v, int lo, int hi)
{
	if (test == false)
	{
		int mid = (lo + hi) / 2;
		test = true;
		bool test2 = allEqual(v, lo, mid - 1);
		bool test3 = allEqual(v, lo, mid - 1);
		if (test2 && test3 && (v[lo] == v[hi]))
			return true;
	}
	while (lo <= hi)
	{
		if (lo == hi)
			return true;
		if (v[lo] != v[hi])
			return false;
		lo++;
	}
}
