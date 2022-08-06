#include<vector>
using namespace std;



//二分法查找指定数在数组中最左侧的位置，数组是有序的，并返回index，不存在则返回-1

//通过调整左右边界，不断去逼近指定数值，如果存在，最终index就指向最左侧的，不存在，则指向最左侧大于它的一个数，

class solution{
public:

    int find(vector<int> &arr, int &target){
        int length = arr.size();
        int left = 0;
        int right = length - 1;
        int index = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] >= target){
                index = mid;
                right = mid - 1;
            }else if(arr[mid] < target){
                left = mid + 1;
            }
        }
        if((index == -1) || (arr[index] != target)){ //没找到指定数，分为三种情况，第一种，所有数都比target小，第二种，找了一圈，target在两个逼近的数中间，第三种数组为0；
            return -1;
        }else{
            return index;
        }

    }





};