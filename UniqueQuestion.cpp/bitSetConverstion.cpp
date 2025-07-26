#include<bits/stdc++.h>
using namespace std;
int main() {
    int positive_num = 5;
    int negative_num = -5;
    int zero_num = 0;

    cout << "The binary form of " << positive_num << " is : "
         << bitset<32>(positive_num) << endl;

    cout << "The binary form of " << negative_num << " is : "
         << bitset<32>(negative_num) << endl;

    cout << "The binary form of " << zero_num << " is : "
         << bitset<32>(zero_num) << endl;

    return 0;
}