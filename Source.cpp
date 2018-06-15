#include <iostream>
using namespace std;


int Sum(int Tree[], int index)
{
	int sum = 0;
	index++;
	while (index>0)
	{
		sum += Tree[index];
		index -= index&(-index);

	}
	return sum;

}

void Update(int Tree[], int n, int index, int value)
{
	index++;

	while (index<=n)
	{
		Tree[index] += value;

		index += index&(-index);
	}


}

int *BuildTree(int arr[], int n)
{
	int *Tree = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		Tree[i] = 0;

	}

	for (int i = 0; i < n; i++)
	{
		Update(Tree, n, i, arr[i]);
	}
	return Tree;


}

int main() {
	int arr[] = { 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(arr) / sizeof(int);

	int *Tree = BuildTree(arr, n);



cout << Sum(Tree, 5) << endl;;
	Update(Tree, n, 3, 6);

	cout << Sum(Tree, 5) << endl;
	


	system("pause");
	return 0;
}