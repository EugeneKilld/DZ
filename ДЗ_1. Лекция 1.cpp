#include <iostream>
#include <cstdlib> //для srand() и rand()
#include <ctime> // для функции time()
#include <math.h> // pow()

using namespace std;

int getRandomNumber(int min, int max); //случайное число в диапозоне min-max

int main()
{
    const int n = 20;
    int random_arr[n];
    int sum = 0;
    
    srand(static_cast<unsigned int>(time(0))); 
 
    for (int i = 0; i < n; ++i)
    {
        random_arr[i] = getRandomNumber(1, 10);
        sum += random_arr[i];
        std::cout << random_arr[i] << " ";
    }
    
    cout << endl;
    double mean = sum / n; //среднее значение
    std::cout << "mean = " << mean << endl;
    double dispersion = 0;
    
    for (int i = 0; i < n; ++i) //дисперсия
    {
        dispersion += pow(random_arr[i] - mean, 2); 
    }
    dispersion /= n - 1;
    cout << "dispersion = " << dispersion << endl;
    
    double z = 1.96; //квантиль нормального распределения, найден по таблице 
    double accuracy = dispersion / sqrt(n) * z; //точность
    
    //находим интервал
    double low = mean - accuracy, high = mean + accuracy;
    cout << "low = " << low << "; high = " << high << endl;
    
    for (int i = 0; i < n; ++i) //вывод входящих в интервал значений
    {
        if (random_arr[i] >= low && random_arr[i] <= high)
            cout << random_arr[i] << " ";
    }
    
    return 0;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
