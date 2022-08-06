#include<vector>
using namespace std;

class solution{
public:

    int find(vector<int> &arr, int target){
        int left = 0;
        int right = arr.size() - 1;
        int index = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] <= target){
                index = mid;
                left = mid + 1;
            }else if(arr[mid] > target){
                right = mid - 1;
            }
        }
        if((index >= 0) && (arr[index] == target)){
            return index;
        }else{
            return -1;
        }



    }





};