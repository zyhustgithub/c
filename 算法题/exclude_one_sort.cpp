#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindNum(vector<int> &vecInt)
{
    int vecSize = vecInt.size();
    if (vecSize < 3) {
        return -1;
    }

    int left = 0;
    int right = vecSize - 1;

    while (left < (vecSize - 1)) {
        if (vecInt[left] != vecInt[left + 1]) {
            break;
        }
        ++left;
    }
    if (left >= (vecSize - 2)) {
        return -1;
    }

    while (right > left + 1) {
        if (vecInt[right - 1] != vecInt[right]) {
            break;
        }
        --right;
    }

    if (right == (left + 1)) {
        return -1;
    }

    bool leftState = (vecInt[left] < vecInt[left + 1]);
    bool rightState = (vecInt[right - 1] < vecInt[right]);

    if (leftState != rightState) {
        if 
    }

    while ((left < vecSize - 1) && (left < right)) {
        if (vecInt[left - 1] == vecInt[left]) {
            ++left;
        } else {
            if ((vecInt[left - 1] < vecInt[left]) != leftState) {
                break;
            }
        }
    }
}