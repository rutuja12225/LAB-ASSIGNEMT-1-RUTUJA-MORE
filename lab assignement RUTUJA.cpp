#include<iostream>
using namespace std;
struct student
{
	int rollno;
	string name;
	float sgpa;
};
void bubblesort(student arr[],int n)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4-i;j++)
		{
			if(arr[j].rollno> arr[j+1].rollno)
			{
				student a=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=a;
			}
		}
	}
}
void insertionsort(student arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		student key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j].name>key.name)
		{
			arr[j+1]=arr[j];
			j=j-1;	
		}
		arr[j+1]=key;
	}
}
int partition(student arr[],int low,int high)
{
	float pivot=arr[high].sgpa;
	int i=low-1;
	for(int j=low;j<high;++j)
	{
		if(arr[j].sgpa>pivot)
		{
			++i;
			student temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	student temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return i+1;
}
void quicksort(student arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
void searchSgpa(student arr[],int n,float search)
{
	bool found=false;
	for(int i=0;i<n;i++)
	{
		if(arr[i].sgpa==search)
		{
			if(!found)
			{
				cout<<"student with SGPA::"<<search<<endl;
				found=true;
			}
				cout<<"name:"<<arr[i].name<<endl;
		}
	}
	if(!found)
	{
		cout<<"no students found with SGPA"<<search<<endl;
	}
}
int binarysearch(student arr[],int size,string key)
{
	int start=0;
	int end=size-1;
	int mid=start+(end-start)/2;
	
	while(start<=end)
	{
		if(arr[mid].name==key)
		{
			return mid;
		}
		if(key>arr[mid].name)
		{
			start=mid+1;
    	}
    	else
    	{
    		end=mid-1;
		}
		mid=start+(end-start)/2;
	}
	return-1;
}
int main()
{
	student s[5];
	cout<<"enter the details"<<endl;
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Enter the name of the student"<<endl;
		cin>>s[i].name;
		cout<<"Enter the roll no of student"<<endl;
		cin>>s[i].rollno;
		cout<<"Enter the SGPA of student"<<endl;
		cin>>s[i].sgpa;
		cout<<endl;
	}
	cout<<"details of student are:"<<endl;
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"student no."<<i+i<<endl;
		cout<<"name"<<s[i].name<<endl;
		cout<<"roll no"<<s[i].rollno<<endl;
		cout<<"sgpa"<<s[i].sgpa<<endl;
		cout<<endl;
	}
	//bubble sort 
	bubblesort(s,5);
	cout<<"sorted roll number are::"<<endl;
	cout<<endl;
	for(int j=0;j<5;j++)
	{
		cout<<s[j].rollno<<endl;
	}
	
	//insertion sort
	
	insertionsort(s,5);
	cout<<"sorted names of students are::"<<endl;
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<s[i].name<<endl;
	}
	cout<<endl;
	//quicksort
	quicksort(s,0,4);
	cout<<"Top three students are::"<<endl;
	cout<<endl;
	for(int i=0;i<3;i++)
	{
	 cout<<"name::"<<s[i].name<<",rollno::"<<s[i].rollno<<",sgpa::"<<s[i].sgpa<<endl;
	}
	cout<<endl;
	//search by sgpa
	float search;
	cout<<"Enter SGPA to search::";
	cin>>search;
	cout<<endl;
	
	searchSgpa(s,5,search);
	
	//binary search
	string key;
	cout<<"enter name to search::";
	cin>>key;
	cout<<endl;
	
	insertionsort(s,5);
	int index;
	index=binarysearch(s,5,key);
	
	if(index!=-1)
	{
		cout<<"student found::"<<endl;
		cout<<endl;
		cout<<"name::"<<s[index].name<<endl;
		cout<<"rollno::"<<s[index].rollno<<endl;
		cout<<"sgpa::"<<s[index].sgpa<<endl;	
    }
    else
    {
    	cout<<"student not found::";
	}
	cout<<endl;
	
	return 0;
}
