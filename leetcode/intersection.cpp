#include <iostream>
#include <vector>

void intersection(std::vector<int> a, std::vector<int> b)
{
    //vector<int> 
    for(std::vector<int>::iterator itx = a.begin(); itx != a.end(); itx++) {
        std::cout << *itx << "\t";
        // for(vector<int>::iterator ity = b.begin(); ity != b.end(); ity++) {
        //     if(*itx == *ity) {
        //         cout << *itx << "\t";
        //     }
        // }
        // cout << endl;
    }
}

int main()
{
    int arrA[4] = {1, 2, 2, 4};
    std::vector<int> a(&arrA[0], &arrA[0] + 4);
    int arrB[2] = {2, 2};
    std::vector<int> b(&arrB[0], &arrB[0] + 2);

    intersection(a, b);
    return 0;
}
