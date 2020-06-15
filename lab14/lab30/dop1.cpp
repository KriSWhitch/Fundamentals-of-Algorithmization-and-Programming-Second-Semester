//#include <iostream> 
//#include <algorithm> 
//#include <functional>
//
//using namespace std;
//
//int main() {
//    int n;
//    cout << "Enter an array size:\n";
//    cout << "n = ";
//    cin >> n;
//    int* arr = new int[n];
//
//    cout << "Enter an array:\n";
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    sort(arr, arr + 4, less<int>());
//    sort(arr + n - 4, arr + n, greater<int>());
//    cout << "Output of the program:\n";
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    delete[] arr;
//    system("pause");
//    return 0;
//}