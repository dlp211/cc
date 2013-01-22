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
#include <vector>
using std::vector;

void merge(vector<int> &, vector<int> &, unsigned, unsigned, unsigned);
void sort(vector<int> &, vector<int> &, unsigned, unsigned);
void sort(vector<int> &, unsigned, unsigned);

void sort(vector<int>::iterator, vector<int>::iterator);
void merge(vector<int>::iterator, vector<int>::iterator, vector<int>::iterator);

int main(int argc, char **argv)
{
	vector<int> arr {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	sort(arr.begin(), arr.end() - 1);

	for (const auto i : arr) //type: const int
		cout << i << " ";
	cout << endl;

	arr = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	sort(arr, 0, 19);

	for (const auto i : arr) //type: const int
		cout << i << " ";
	cout << endl;


	return 0;
}

void sort(vector<int>::iterator begin, vector<int>::iterator end)
{
	if (begin < end) {
		vector<int>::iterator middle = (end - begin) / 2 + begin;
		sort(begin, middle);
		sort(middle + 1, end);
		merge(begin, middle + 1, end);
	}
}

void merge(vector<int>::iterator begin, vector<int>::iterator middle, vector<int>::iterator end)
{
	vector<int> l_vec (begin, middle);
	vector<int> r_vec (middle, end + 1);
	vector<int>::iterator l_iter (l_vec.begin());
	vector<int>::iterator l_iter_e (l_vec.end());
	vector<int>::iterator r_iter (r_vec.begin());
	vector<int>::iterator r_iter_e (r_vec.end());

	while (l_iter != l_iter_e && r_iter != r_iter_e) {
		if (*l_iter < *r_iter)
			*begin++ = *l_iter++;
		else
			*begin++ = *r_iter++;
	}

	while (l_iter != l_iter_e)
		*begin++ = *l_iter++;

	while(r_iter != r_iter_e)
		*begin++ = *r_iter++; 

}

void sort(vector<int> &arr, unsigned start, unsigned end)
{
	vector<int> workspace(arr.size());
	sort(arr, workspace, start, end);
}

void sort(vector<int> &arr, vector<int> &workspace, unsigned start, unsigned end)
{
    if (start < end) {
        unsigned middle = (end - start) / 2 + start;
        sort(arr, workspace, start, middle);
        sort(arr, workspace, middle+1, end);
        merge(arr, workspace, start, middle+1, end);
    }
}

void merge(vector<int> &arr, vector<int> &workspace, unsigned start, unsigned middle, unsigned end)
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
