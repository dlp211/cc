/******************************************************************************
 *    FILE: LargestSubArray.cc                                                           *
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
 * A demonstration of a linear time sub-array algorithm      *
 *************************************************************/

#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;

vector<int> largestSubArray(const vector<int> &vec)
{
	if (vec.empty())
		return {};
	decltype(vec.size()) j = 0; //vector<int>::size_type
	int sum = vec[j];
	auto beg = j;
	auto end = j;
	while (vec[j] < 0 && ++j < vec.size()) { //this finds the first positive or
		if (sum < vec[j]) {				   //the negative closest to 0
			sum = vec[j];
			beg = j;
			end = j;
		}
	}

	while(j++ < vec.size()) {
		if (vec[j] > 0) {
			auto i = j;
			int partialSum = vec[i];
			while (--i > end + 1) {
				partialSum += vec[i];
				if (partialSum > sum) {
					beg = i;
					end = j;
					break;
				} else {
					--i;
				}
			}
			if(i == end + 1 && partialSum > 0) {
				sum += partialSum;
				end = j;
			}
		}
	}
	//+1 b/c iterator initiation is left inclusive
	return {vec.begin() + beg, vec.begin() + end + 1};

}

int main()
{
	//vector<int> vec {13,-3,-25,20,-3,-16,-23,18,20,7,12,-5,-22,15,-4,7};
	//vector<int> vec {-12, 0, -10};
	//vector<int> vec {-12, -11, -10, -9, -10};
	//vector<int> vec {5};
	//vector<int> vec {};
	vector<int> vec {12, 13, 15, 17, 18};
	//largest subarray is [7,10]
	vector<int> subvec(largestSubArray(vec));

	for (const auto i: subvec)
		cout << i << " ";
	cout << endl;

	return 0;
}
