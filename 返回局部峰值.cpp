#include <vector>
using namespace std;


class solution{
public:


    int find(vector<int> &arr, int &b){
        int length = arr.size();
        //当数组只有1个元素的返回
        if(length == 1){
            return 1;
        }
        //第一个元素大于第二个元素的返回
        if(arr[0] > arr[1]){
            return 0;
        }
        //倒数第一个元素大于第二个元素的返回
        if(arr[length - 2] < arr[length - 1]){
            return length - 1;
        }


        int left = 0;
        int right = length - 1;

        while(left < right){ //一定存在峰值，所以不会循环到left==right的时候
            int mid = left + (right - left) / 2;
            //为什么比较mid和mid+1，而不是mid和mid-1，因为left<=mid,right>mid,所以mid-1有可能越界，超过我们规定的[left, right]
            if(arr[mid] > arr[mid + 1]){  
            //为什么等于mid，而不是mid减1，因为mid>mid+1，说明mid是一个可能的极大值点，需要将其囊括在要比较的区间里
                right = mid;
            }else if(arr[mid] < arr[mid + 1]){
            //此处同理，证明mid+1是一个可能的极大值点
                left = mid + 1;
            }
        }
            
            // }else{
            // //此处没有特殊情况了，因为即便mid刚好既大于左，又大于右侧，也会执行上面的第一个if
            //     return mid;
            // }
        //为什么返回right
        //上面的循环，最终的退出条件是left < right，最后只有两个数了，即一个left和一个right
        //上面两个if，无论通过那个终止循环，返回的都是mid和mid+1较大的那个的index
        return right;
    }
    
};