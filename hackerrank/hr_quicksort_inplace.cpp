/*
 * =====================================================================================
 *
 *       Filename:  hr_quicksort_inplace.cpp
 *
 *    Description:  quicksort implementation in place
 *
 *        Version:  1.0
 *        Created:  01/29/2015 03:21:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Harrison Cavallero 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_vector(vector<int> v){
    if (v.size()) {
        for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

void quickSort(vector<int>& ar, int start, int end){
  if ( end- start < 2){
    return;
  }
    
  //choose pivot, set index
  int p_index = end - 1;

  //set left and right indexes
  int right_start = start;
  int i = start;

  while ( i < end) {
    if ( (ar[i] <= ar[p_index])) {
      if (i > right_start){
        ar[i] = ar[i] - ar[right_start];
        ar[right_start] = ar[i] + ar[right_start];
        ar[i] = ar[right_start] - ar[i];
      }
      right_start++;
    }
    if (i == p_index){
        print_vector(ar);
    }
    
    i++;

  }
    
  //recurse on left and right
  quickSort(ar, start, right_start-1);
  quickSort(ar, right_start, end);

}

int main() {
    vector <int>  _ar;
    int _ar_size;

    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

    quickSort(_ar, 0, _ar.size());

   return 0;

}


