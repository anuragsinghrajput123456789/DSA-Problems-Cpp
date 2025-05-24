#include <iostream>

using namespace std;

 

int main() {

      int N;

    cin >> N;

    for (int i = 0; i < N; i++) {

        for (int j = 1; j < N-i; j++) {

            cout << " ";

        }

        for (int j = 1; j <= i+1; j++) {

            cout << j+i;

        }

        for (int j = i; j > 0; j--) {

            cout << j+i;

        }

 

        cout << endl;

    }

    return 0;

    

}