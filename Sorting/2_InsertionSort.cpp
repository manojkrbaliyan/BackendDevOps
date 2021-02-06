#include <iostream>
#include <vector>

using namespace std;

std::vector<int> insertionSort(vector<int> &vec)
{
	for(int i=1;i<vec.size();++i)
	{
		int j=i;
		while(j > 0 && vec[j-1] > vec[j])
		{
			swap(vec[j-1],vec[j]);
			j-=1;
		}
	}
	return vec;
}


int main()
{

    vector<int> result{8,5,2,9,5,6,3};
    vector<int> res=insertionSort(result);
    for(auto const &elem:res)
    cout << elem << " ";
    cout << endl;
    return 0;
}
