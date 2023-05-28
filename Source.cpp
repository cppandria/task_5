
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;

void fill_array_with_randoms(int **arr, int rows, int colomn, int min_range, int max_range) {
	int range = max_range - min_range + 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colomn; j++)
		{
			arr[i][j] = rand() % range + min_range;
		}
	}
}
void print_arr(int **arr, int rows, int colomn) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colomn; j++)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool match_criteria(int elem) {

	if (elem % 3 == 0 && elem >0)
		return true;
	
	return false;
}
int get_sum(int **arr, int rows, int colomn) {
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colomn; j++)
		{
			if (match_criteria(arr[i][j]))
				{
					sum+= arr[i][j];
				}
		}
	}
	return sum;
}
int get_count(int **arr, int rows, int colomn) {
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colomn; j++)
		{
			if (match_criteria(arr[i][j]))
			{
				count++;
			}
		}
	}
	return count;
}

void swap_colomn(int **arr, int rows, int column_1, int column_2) {
	for (int i = 0; i < rows; i++) {
		int tmp = arr[i][column_1];
		arr[i][column_1] = arr[i][column_2];
		arr[i][column_2] = tmp;
	}

}

void bubbleSort(int **arr, int rows, int colomn)
{
	int i, j;
	bool swapped;
	for (i = 0; i < colomn - 1; i++) {
		swapped = false;
		for (j = 0; j < colomn - i - 1; j++) {
			if (arr[0][j] < arr[0][j + 1]) {
				swap_colomn(arr, rows, j, j + 1);
				swapped = true;
			}
			if (arr[0][j] == arr[0][j + 1]) {
				//cout << "They are equal" << j << endl;//go to 2 row
				if (arr[1][j] < arr[1][j + 1]) {
					swap_colomn(arr, rows, j, j + 1);
				}
				if (arr[1][j] == arr[1][j + 1]) {
					if (arr[2][j] > arr[2][j + 1]) {
						swap_colomn(arr, rows, j, j + 1);
					}
				}
			}
		}

		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	}
}

void change_matched_elem(int **arr, int rows, int colomn) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colomn; j++)
		{
			if (match_criteria(arr[i][j]))
			{
				arr[i][j] = 0;
			}
		}
	}
 }

int main() {
	int **array;
	array = new int *[9];
	for (int i = 0; i < 9; i++)
		array[i] = new int[6];

	fill_array_with_randoms((int **)array, 9,6,-21,24);
	array[0][3] = 17;
	array[1][5] = 17;
	cout << "Initial matrix: " << endl;
	print_arr(array, 9, 6);

	bubbleSort(array, 9, 6);
	cout << "Sorted matrix: " << endl;
	print_arr(array, 9, 6);

	int sum = get_sum(array, 9, 6);
	int count = get_count(array, 9, 6);


	change_matched_elem(array, 9, 6);
	cout << "Modified matrix: " << endl;
	print_arr(array, 9, 6);
	cout << "Amount of elements =" << count << ", sum =" << sum << endl;

	return 0;
}