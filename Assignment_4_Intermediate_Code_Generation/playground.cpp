#include<bits/stdc++.h>
using namespace std;

// A Method that returns multiple values using
// tuple in C++.

// A Method returns a pair of values using pair
std::pair<int*, string> foo1(int num)
{
	int arr[3]= {1, 2, 3};
	cout<< arr[0]<< endl;
	// Packing two values to return a pair
	return std::make_pair(arr, "a");			
}

int main()
{
	int a,b;
	char cc;
	
	
	// Storing returned values in a pair
	pair<int*, string> p = foo1(5);
	
	cout << "Values returned by Pair: ";
	cout << (p.first)[0] << " " << p.second;
	return 0;
}
