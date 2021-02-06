#include <iostream>
#include <vector>

using namespace std;

std::vector<int> BubbleSort(vector<int> &vec)
{
	int counter =0; 
	bool isSorted=false;
	while(!isSorted)
	{
		for(int i=0;i<vec.size()-1-counter;++i)
		{
			isSorted=true;
			if(vec[i] > vec[i+1])
			{
				swap(vec[i],vec[i+1]);
				isSorted=false;
			}
		}
	    counter +=1;
	}
	return vec;
}


int main()
{

    vector<int> result{8,5,2,9,5,6,3};
    vector<int> res=BubbleSort(result);
    for(auto const &elem:res)
    cout << elem << " ";
    cout << endl;
    return 0;
}
