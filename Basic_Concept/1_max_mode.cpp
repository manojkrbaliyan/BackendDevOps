#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
// T(n) = O(n^2)
int maxMode_1(std::vector<int> &v)
{
	int maxmode=numeric_limits<int>::min();
	for(int i=0;i<v.size();++i)
	{
		for(int j=0;j<v.size();++j)
		{
			if(maxmode<v[i]%v[j])
				maxmode=v[i]%v[j];
		}
	}
	return maxmode;
}
// // T(n) = O(nlogn) ; sort the array and return the second largest 
int maxMode_2(std::vector<int> &v)
{
	sort(v.begin(),v.end());
	for(auto const elem:v)
		cout << elem << " ";
	cout << endl; 
	//auto ret=v.end()-2;
	return v[v.size()-2];
}
// // T(n) = O(n)
int maxMode_3(std::vector<int> &v)
{
	int first=numeric_limits<int>::min();
	int second=numeric_limits<int>::min();
	for(int i=0;i<v.size();++i)
	{
		if(first < v[i])
		{
			second=first;
			first=v[i];
		}
		else if(second < v[i] && v[i]!=first)
		{
			second=v[i];
		}

	}
	if(second!=numeric_limits<int>::min())
		return second;
	return 0;
}

int main()
{
	std::vector<int> v{1,2,6,4,44,3};
	cout << maxMode_1(v) << endl;
	cout << maxMode_2(v) << endl;
	cout << maxMode_3(v) << endl;
	return 0;
}
