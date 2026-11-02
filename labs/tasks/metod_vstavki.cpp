#include <iostream>
using namespace std;

int main() {
     int arr[] = { 64, 25, 12, 22, 11, 90, 5, 37 };
     const int n = sizeof(arr) / sizeof(arr[0]);

     cout << "Массив до сортировки:    ";
     for (int i = 0; i < n; i++)
          cout << arr[i] << " ";
     cout << endl;

     for (int i = 1; i < n; i++)
          for (int j = i; j > 0; j--)
               if (arr[j] < arr[j - 1])
               {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
               }

     cout << "Массив после сортировки: ";
     for (int i = 0; i < n; i++)
          cout << arr[i] << " ";
     cout << endl;

     return 0;
}