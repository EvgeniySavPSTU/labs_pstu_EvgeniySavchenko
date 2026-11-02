//Дан двумерный массив, найти максимальный элемент и его индексы. 
#include <iostream>
using namespace std;
int main()
{
    int m[3][4] = {
        {1, 2, 5, 6},
        {5, 4, 2, 1},
        {42, 60, 23, 5}
    }
    ,mx = m[0][0], indi = 0, indj = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (m[i][j] > mx)
            {
                mx = m[i][j];
                indi = i;
                indj = j;
            }
        }
    }
    cout << "Max: " << mx<< " Polozenie -> Stroka: " << indi<< " Stolbez: " << indj << endl;
    return 0;
}
