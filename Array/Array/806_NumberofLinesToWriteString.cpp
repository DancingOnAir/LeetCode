#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> numberOfLines(vector<int>& widths, string S) {
	vector<int> result;

	int MAX_LENGTH = 100;
	int asc_start_pos = 97;
	int numOfCharsPerLine = 0;
	int numOfLines = 1;
	int endPosOfString = 0;

	for (int i = 0; i < S.size(); ++i)
	{
		numOfCharsPerLine += widths[S.at(i) - asc_start_pos];
		if (numOfCharsPerLine > MAX_LENGTH)
		{
			numOfCharsPerLine = widths[S.at(i) - asc_start_pos];
			++numOfLines;
		}
	}
	endPosOfString = numOfCharsPerLine;
	result.push_back(numOfLines);
	result.push_back(endPosOfString);

	return result;
}

void show(vector<int> widths)
{
	for (auto iter = widths.cbegin(); iter != widths.cend(); ++iter)
		cout << *iter << endl;
}

int main(void)
{
	vector<int> widths = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	string S = "bbbcccdddaaa";
	string S2 = "abcdefghijklmnopqrstuvwxyz";

	vector<int> result = numberOfLines(widths, S2);
	show(result);

	system("pause");
	return 0;
}