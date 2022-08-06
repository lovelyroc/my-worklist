#include <iostream>
#include <vector>
using namespace std;

//通过二分查找指定数是否在数组中，并返回index，不在的话，index = -1；
class solution{
public:

    int find(vector<int> &arr, int target){
        int length = arr.size();
        int index = -1;
        if(length == 0){
            return index;
        }
        int left = 0;
        int right = length - 1;
        //二分过程中，要不断调整左右边界
        while(left <= right){  //要小于等于，不然最后当left == right的时候，会少一个arr[left]的比较
            int mid = left + (right - left) / 2;   //防止越界
            if(arr[mid] == target){
                index = mid;
                return index; //可以省掉赋值，直接return mid;
            }else if(arr[mid] > target){
                right = mid - 1;
            }else if(arr[mid] < target){
                left = mid + 1;
            }
        }
        return index;
    }


};