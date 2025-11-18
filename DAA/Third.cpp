#include<iostream>
using namespace std;
int fact(int n) {

    if(n==1) return 1;

    return n * fact(n-1);

}
int main() {
    int num;
    cin >> num;
    int result = fact(5);
    cout << "Factorial of " << num << " is " << fact(5) << endl;
    return 0;
}