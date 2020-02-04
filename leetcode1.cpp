#include <iostream>
#include <map>
using namespace std;

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result;
    result = new int[2];
    map<int, int> hashmap;
    for(int i = 0; i < numsSize; i++){
        if(hashmap.count(target - nums[i])){
            result[0] = hashmap[target - nums[i]];
            result[1] = i;
        }
        hashmap[nums[i]] = i;
    }
    return result;
}

int main()
{
    int nums[4] = {2,7,11,15};
    int* r;
    r = new int[2];
    r = twoSum(nums, 4, 13, NULL);
    for(int i = 0; i < 2; i++){
        cout << r[i] << " ";
    }
}