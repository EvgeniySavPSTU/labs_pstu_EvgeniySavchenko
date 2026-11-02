#include <iostream>
using namespace std;

int main() {
     int arr[] = { 64, 25, 12, 22, 11, 90, 5, 37 };
     const int n = sizeof(arr) / sizeof(arr[0]);

     cout << "Массив до сортировки:    ";
     for (int i = 0; i < n; i++)
          cout << arr[i] << " ";
     cout << endl;

     for (int i = 0; i < n - 1; i++)
     {
          int min = i;
          for (int j = i + 1; j < n; j++)
               if (arr[min] > arr[j])
                    min = j;
          if (min != i)
          {
               int temp = arr[i];
               arr[i] = arr[min];
               arr[min] = temp;
          }
     }

     cout << "Массив после сортировки: ";
     for (int i = 0; i < n; i++)
          cout << arr[i] << " ";
     cout << endl;

     return 0;
}