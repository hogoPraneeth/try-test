//
//  tmp.cpp
//  try&test
//
//  Created by Praneeth Patil on 10/15/17.
//  Copyright © 2017 Praneeth Patil. All rights reserved.
//
#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& nums, int target) {
    if (!nums.size()) return -1;
    int low = 0;
    int high = nums.size() -1;
    while (high < low) {
        int mid = (high + low)/2;
        if (nums[mid] == target) {
            return mid;
        }
        if (target < nums[mid]) {
            if ((target < nums[low])) {
                low = mid;
                continue;
            } else {
                high = mid;
                continue;
            }
        } else {
            if (target > nums[low]) {
                high = mid;
                continue;
            } else {
                low = mid;
                continue;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> v = {1};
    cout << "here\n";
    search(v, 0);
    cout << "here\n";
    return 0;
}
