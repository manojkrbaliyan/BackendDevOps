#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
class Myvector
{
	int *m_data;
	int m_length;
public:
	Myvector():m_length(0),m_data(nullptr){}
	Myvector(int len):m_length(len)
	{
		m_data=new int[len];
	}
	Myvector(const Myvector& other)
	{
		m_length=other.m_length;
		m_data=new int[m_length];
	}
	Myvector& operator=(const Myvector& other)
	{
		if(this!=&other)
		{
			m_length=other.m_length;
			*m_data=*(other.m_data);
		}
		return *this;
	}
	int& operator[](int index)
	{
		return m_data[index];
	}
	int getLength()
	{
		return m_length;
	}
	// responsibility of the class 
	void erasedata();
	int myVecSize();
	void reallocate(int);
	void inesertAtBefore(int, int);
	void resize(int newLength);
	void remove(int intdex);
	void insertatBeg(int val);
	void insertatEnd(int val);
};

void Myvector::erasedata()
{
	delete [] m_data;
	m_data=nullptr;
	m_length=0;
}
int Myvector::myVecSize()
{
	return m_length;
}
void Myvector::reallocate(int newLen)
{
	erasedata();
	if(newLen <=0)
		return;
	m_length=newLen;
	m_data=new int[m_length];

}

void Myvector::inesertAtBefore(int element, int index)
{
	assert(index >=0 && index <= m_length);
	int *data=new int[m_length+1];
	for(int i=0;i<index;++i)
	{
		data[i]=m_data[i];
	}
	data[index]=element;
	for(int i=index;i<m_length;++i)
	{
		data[i+1]=m_data[i];
	}

	delete [] m_data;
	m_data=nullptr;
	m_data=data;
	m_length++;

}

void Myvector::resize(int newLen)
{
	if(newLen<=0)
	erasedata();
		return;
	int *data=new int[newLen];
   int elementtocopy=(newLen>m_length)?m_length:newLen;
   for(int i=0;i<elementtocopy;++i)
   {
   		data[i]=m_data[i];
   }
   delete[] m_data;
   m_data=nullptr;
   m_data=data;
   m_length=newLen;
}
void Myvector::remove(int index)
{
	assert(index>=0 && index <=m_length);
	if(m_length==1)
	{
		delete [] m_data;
		m_length=0;
	}
	int *data=new int [m_length-1];
	for(int i=0;i<index;++i)
	{
		data[i]=m_data[i];
	}
	for(int j=index+1;j<m_length;++j)
	{
		data[j-1]=m_data[j];
	}
	delete []m_data;
	m_data=data;
	m_length--;

}
void Myvector::insertatBeg(int val)
{
	inesertAtBefore(val,0);
}
void Myvector::insertatEnd(int val)
{
	inesertAtBefore(val,m_length);
}

int main()
{
	Myvector array(10);
	//fill the value in to array
	for (int i = 0; i < 10; ++i)
	{
		array[i]=i+1;
	}
//Resize to 8 element
	array.resize(8);
//insert element 20 before element with index 5
	array.inesertAtBefore(20,5);
//Remove the Element with index 3;
	array.remove(3);
//Insert 15 at begining 
	array.insertatBeg(30);
//insert 20 at end
	array.insertatEnd(40);
for (int i = 0; i < array.getLength(); ++i)
{
	cout<<array[i]<<" ";
}
	return 0;
}
