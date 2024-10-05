#include "StringData.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int linear_search(vector<string> container, std::string element) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

int binary_search(vector<string> container, std::string element) {
    int left = 0;
    int middle = container.size() / 2;
    int right = container.size() - 1;

     while (!(left == middle && middle == right - 1)) {
        if (element != container[middle]) {
            if (element < container[middle]) {
                right = middle;
                middle = right / 2;
                if (middle - left == 0 && element == container[middle]) {
                    return middle;
                }
            } else {
                left = middle;
                middle = (right + middle) / 2;
                if (middle + 1 == right && element == container[right]) {
                    return right;
                }
            }
        } else {
            return middle;
        }
     }
    return -1;
}

int main() {
    std::vector<std::string> ds = getStringData();
    long long start_time;
    long long end_time;
    float total_time;
    int index;

    //not_here
    start_time = systemTimeNanoseconds();
    index = linear_search(ds, "not_here");
    end_time = systemTimeNanoseconds();
    total_time = (end_time - start_time) / 1000.0;
    cout << "Linear search for \"not_here\". Time: " << total_time << " seconds. Index: " << index << "\n";

    start_time = systemTimeNanoseconds();
    index = binary_search(ds, "not_here");
    end_time = systemTimeNanoseconds();
    total_time = (end_time - start_time) / 1000.0;
    cout << "Binary search for \"not_here\". Time: " << total_time << " seconds. Index: " << index << "\n\n";

    //mzzzz
    start_time = systemTimeNanoseconds();
    index = linear_search(ds, "mzzzz");
    end_time = systemTimeNanoseconds();
    total_time = (end_time - start_time) / 1000.0;
    cout << "Linear search for \"mzzzz\". Time: " << total_time << " seconds. Index: " << index << "\n";

    start_time = systemTimeNanoseconds();
    index = binary_search(ds, "mzzzz");
    end_time = systemTimeNanoseconds();
    total_time = (end_time - start_time) / 1000.0;
    cout << "Binary search for \"mzzzz\". Time: " << total_time << " seconds. Index: " << index << "\n\n";

    //aaaaa
    start_time = systemTimeNanoseconds();
    index = linear_search(ds, "aaaaa");
    end_time = systemTimeNanoseconds();
    total_time = (end_time - start_time) / 1000.0;
    cout << "Linear search for \"aaaaa\". Time: " << total_time << " seconds. Index: " << index << "\n";

    start_time = systemTimeNanoseconds();
    index = binary_search(ds, "aaaaa");
    end_time = systemTimeNanoseconds();
    total_time = (end_time - start_time) / 1000.0;
    cout << "Binary search for \"aaaaa\". Time: " << total_time << " seconds. Index: " << index << "\n";

    return 0;
}