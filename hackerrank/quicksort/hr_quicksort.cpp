
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void print_vector(vector<int> v){
    if (v.size()) {
        for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
            cout<<*it<<" ";
        }
    }
}

void quickSort(vector <int>  ar, int ar_size) {
    vector<int> lt;
    vector<int> gt;
    vector<int> sorted_ar;
    int p = 0;

    //partition into pivot, lt, rt
    if (ar_size)
        p = ar[0];
    if (ar_size > 1){
        for (int i = 1; i < ar_size; i++){
            if (ar[i] < p ){
                lt.push_back(ar[i]);
            } else {
                gt.push_back(ar[i]);
            }
        }
        quickSort(lt, lt.size());
        quickSort(gt, gt.size());
    }
    
    if (lt.size())
        sorted_ar.push_back(lt[0]);
    else {
        sorted_ar.push_back(p);
        if (gt.size())
            sorted_ar.push_back(gt[0]);
    }
    print_vector(sorted_ar);

    //recursively call quickSort
    //if ar_size == 1
        //print lt, p, gt

}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
   /* input:
    *
    * 7
      5 8 1 3 7 9 2  
    */
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

quickSort(_ar, _ar_size);
   
   return 0;
}

