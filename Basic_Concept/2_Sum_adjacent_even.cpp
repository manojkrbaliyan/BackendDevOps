#include <iostream>
#include <vector>
using namespace std;
/*
	return the minimum Numbers of element to be remobve from an Array 
	So that sum of all adjacent number remain even
	// Sum may remain only in 2 condition 
	// 1. either both the numbers are even 
	// 2. Either boths the number are odd 
	// So count the even and odd number and removes the minimum one 

*/
int solve(std::vector<int> &vec)
{
	int counteven, countodd;
	counteven=countodd=0;
	for(auto const elem:vec)
	{
		if(elem%2==0)
		{
			counteven++;
		}
		else if(elem%2!=0)
		{
			countodd++;
		}
	}
	return min(countodd,counteven);

	
}

int main()
{	
	vector<int> vec{1, 2, 3, 4, 5};
	cout << "minimum number of element to be removed " << solve(vec) << endl;
	vector<int> vec1{5, 17, 100, 11};
	cout << "minimum number of element to be removed " << solve(vec1) << endl;
	vector<int> vec2{ 1, 2, 3, 7, 9};
	cout << "minimum number of element to be removed " << solve(vec2) << endl;
	return 0;
}
