/******************************************************************************
 *    FILE: InsertionSort.cc                                                        *
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
 * Just a simple Insertion Sort Demonstration using an int[] *
 *************************************************************/

#include <iostream>
using std::endl; using std::cout;

void sort(int *arr, const unsigned size)
{
	for (unsigned i = 0; i < size; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

int main(int argc, char **argv)
{
	int arr[10] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	sort(arr, end(arr) - begin(arr));
	for(const auto i : arr)
		cout << i << " ";
	cout << endl;

	return 0;
}