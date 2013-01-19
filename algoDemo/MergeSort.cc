/******************************************************************************
 *    FILE: MergeSort.cc                                                      *
 *    AUTHOR: David L Patrzeba                                                *
 *    E-MAIL: david.patrzeba@gmail.com                                        *                                  *
 *                                                                            *
 *    The MIT Liscense                                                        *
 *    Copyright (c) 2013 David L patrzeba                                     *
 *                                                                            *
 *    Permission is hereby granted, free of charge, to any person obtaining a *
 *    copy of this software and associated documentation files (the           *
 *    "Software"), to deal in the Software without restriction, including     *
 *    without limitation the rights to use, copy, modify, merge, publish,     *
 *    distribute, sublicense, and/or sell copies of the Software, and to      *
 *    permit persons to whom the Software is furnished to do so, subject to   *
 *    the following conditions:                                               *
 *                                                                            *
 *    The above copyright notice and this permission notice shall be included *
 *    in all copies or substantial portions of the Software.                  *
 *                                                                            *
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS *
 *    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF              *
 *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  *
 *    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY    *
 *    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,    *
 *    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE       *
 *    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                  *
 *                                                                            *
 ******************************************************************************/

/*************************************************************
 * Just a simple Merge Sort Demonstration using an int[]     *
 *************************************************************/

#include <iostream>
 using std::endl; using std::cout; using std::begin; using std::end;

void merge(int *arr, int *workspace, unsigned start, unsigned middle, unsigned end);
void sort(int *arr, int *workspace, unsigned start, unsigned end);

void sort(int *arr, unsigned start, unsigned end)
{
	int *workspace = (int *) malloc(sizeof(int) * end - start + 1);
	sort(arr, workspace, start, end);
	free(workspace);
}

void sort(int *arr, int *workspace, unsigned start, unsigned end)
{
    if (start < end) {
        unsigned middle = (end - start) / 2 + start;
        sort(arr, workspace, start, middle);
        sort(arr, workspace, middle+1, end);
        merge(arr, workspace, start, middle+1, end);
    }
}

void merge(int *arr, int *workspace, unsigned start, unsigned middle, unsigned end)
{
	unsigned j = 0;
	unsigned begin1 = start;
	unsigned mid = middle - 1;
	unsigned n = end - start + 1;

	while (begin1 <= mid && middle <= end) {
		if (arr[begin1] < arr[middle])
			workspace[j++] = arr[begin1++];
		else
			workspace[j++] = arr[middle++];
	}

	while(begin1 <= mid)
		workspace[j++] = arr[begin1++];
	while(middle <= end)
		workspace[j++] = arr[middle++];

	for(j = 0; j < n; ++j)
		arr[start + j] = workspace[j];
}

int main(int argc, char **argv)
{
	int arr[20] {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	sort(arr, 0, 19);

	for (const auto i : arr)
		cout << i << " ";
	cout << endl;

	return 0;
}
