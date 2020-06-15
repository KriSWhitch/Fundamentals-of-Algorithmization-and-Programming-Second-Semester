//#include <iostream> 
//#include <ctime> 
//#include <cstdlib>
//using namespace std;
//int main()
//{
//    const int size = 15;
//    int array[size];
//    int i, j;
//    srand(time(NULL));
//    int count = 0;
//
//    for (i = 0; i < size; i++)
//        array[i] = rand() % 10 - 5;
//
//    for (i = 0; i < size; i++)
//        cout << array[i] << " ";
//    cout << endl;
//
//    for (i = 0; i < size; i++)
//    {
//        int temp = array[i];
//
//        for (j = 0; j < size; j++)
//            if (temp == array[j])
//                count++;
//        if (count == 1)
//            cout << temp << " ";
//        count = 0;
//    }
//    cout << endl;
//}