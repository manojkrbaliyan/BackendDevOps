#include <iostream>
#include <vector>

using namespace std;
// 1. Select the first element is the smallest element 
// 2. from next onwards index select the element which is min in comparision to the first element 
// 3. if it is so, than swap 
// repeat 1 to 3
std::vector<int> SelectionSort(std::vector<int> &vec)
{
	int currentIndex=0;
	while(currentIndex < vec.size()-1)
	{
		int smallestIndex=currentIndex;
		for(int i=currentIndex+1;i<vec.size();++i)
		{
			if(vec[i] < vec[smallestIndex])
			{
				smallestIndex=i;
			}
		}
		swap(vec[currentIndex],vec[smallestIndex]);
		currentIndex+=1;
	}
	return vec;
}

int main()
{

    vector<int> result{8,5,2,9,5,6,3};
    vector<int> res=SelectionSort(result);
    for(auto const &elem:res)
    cout << elem << " ";
    cout << endl;
    return 0;
}
