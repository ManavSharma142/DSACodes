#include<iostream>
using namespace std;
int fact(int n) {

    if(n==1) return 1;

    return n * fact(n-1);

}
int main() {
    int num = 5;
    int result = fact(5);
    cout << fact(5) << endl;
    return 0;
}