#include <iostream>
//#include <algorithm>
using namespace std;

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size > nums2Size){      //保证数组1一定最短
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int iMin = 0, iMax = nums1Size, maxLeft = 0, minRight = 0;
    while (iMin <= iMax)
    {
        //i为第一个数组的割，j为第二个数组的割
        int i = (iMin + iMax) / 2;
        int j = (nums1Size + nums2Size + 1) / 2 - i;
        cout << i << " "<< j << endl;
        //max(nums1[i-1], nums2[j-1]) <= min(nums1[i], nums2[j])
        if(j != 0 && i != nums1Size && nums2[j-1] > nums1[i]){      //i需要增大
            iMin = i+1;
        }
        else if(i != 0 && j != nums2Size && nums1[i - 1] > nums2[j] ){ //i需要减小
            iMax = i-1;
        }
        else{   //满足条件    
            if(i == 0){
                maxLeft = nums2[j-1];
            }
            else if(j == 0){
                maxLeft = nums1[i-1];
            }
            else{
                maxLeft = nums1[i-1] > nums2[j-1] ? nums1[i-1] : nums2[j-1];
            }

            if(i == nums1Size && j == nums2Size){
                minRight = 0;
            }
            else if(i == nums1Size){
                minRight = nums2[j];
            }
            else if(j == nums2Size){
                minRight = nums1[i];
            }
            else{
                minRight = nums1[i] > nums2[j] ? nums2[j] : nums1[i];
            }

            if((nums1Size + nums2Size) % 2 == 1){
                return maxLeft;
            }else{
                return (maxLeft + minRight) / 2.0;
            }            
        }
    }
    return 0.0;
}

int main()
{
    int nums1[4] = {2, 3, 5, 6};
    int nums2[4] = {1, 4, 7, 9};
    int nums3[2] = {1, 2};
    int nums4[2] = {-1, 3};
    
    cout << findMedianSortedArrays(nums3, 2, nums4, 2);
}