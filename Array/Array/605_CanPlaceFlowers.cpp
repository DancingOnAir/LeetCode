#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    vector<int> flagList;
    int i = 0;
    for (auto val : flowerbed)
    {
    	if (val == 1)
    		flagList.push_back(i);
    
    	++i;
    }
    
    int sum = 0;
    	
    if(flagList.size() > 0)
    {
    	for(int j = 0; j < flagList.size(); ++j)
    	{
    	    if(0 != flagList.at(j) && 0 == j)
    	    {
    	        sum += flagList.at(j) / 2;
    	    }
    	        
    	    if(flowerbed.size() - 1 != flagList.at(j) && flagList.size() - 1 == j)
    	    {
    	        sum += (flowerbed.size() - 1 - flagList.at(j)) / 2;
    	    }
    	        
    	    if(j > 0)
    	    {
    	        sum += (flagList.at(j) - flagList.at(j - 1) - 2) / 2;
    	    }
    	}
    	    
    }else
    {
    	if(0 == flowerbed.size()%2)
    	{
    	    sum = flowerbed.size()/2;
    	}else
    	{
    	    sum = flowerbed.size()/2 + 1;
    	}
    }
    	
    
    if (sum == n)
    	return true;
    
    return false;
}

int main()
{
	vector<int> vec = {1, 0, 0, 0, 1};
	int n = 1;

	if (canPlaceFlowers(vec, 1))
		cout << "True" << endl;

	cout << "False" << endl;

	system("pause");
	return 0;
}