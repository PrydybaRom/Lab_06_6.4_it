
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
using namespace std;


double generateRandomDouble(double min, double max) {
    int randomInt = rand() % ((static_cast<int>(max) - static_cast<int>(min) + 1) * 10);
    return min + static_cast<double>(randomInt) / 10.0;
}

// Заповнення масиву дійсними випадковими числами
void fillArrayWithRandomNumbers(std::vector<double>& arr, int size, double min, double max) {
    srand(static_cast<unsigned int>(time(0))); 
 
    for (int i = 0; i < size; ++i) {
        arr[i] = generateRandomDouble(min, max);
    }
}


// Вивід масиву
void PrintArr(vector<double>& t, const int size)
{
    cout << "Array -" << "{";
    for (int i = 0; i < size; i++)
    {
        cout << fixed << setprecision(2) << setw(7) << t[i];
    }
    cout << setw(-4) << "}" << endl;
}

// Сума додатніх елементів масиву
int sumElements(std::vector<double>& arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}


// Добуток елементів масиву, розташованих між максимальним за модулем і мінімальним за модулем елементами.
int minAndMax(std::vector<double>& arr, int size) {
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < size; i++) {

        if (abs(arr[i]) > abs(arr[maxIndex])) {
            maxIndex = i;
        }

        if (abs(arr[i]) < abs(arr[minIndex])) {
            minIndex = i;
        }

    }

    // Знаходимо початковий та кінцевий індекс для обчислення добутку
    int startIndex = min(maxIndex, minIndex) + 1;
    int endIndex = max(maxIndex, minIndex) - 1;

    // Обчислюємо добуток елементів між максимальним та мінімальним за модулем
    double product = 1.0;
    for (int i = startIndex; i <= endIndex; i++) {
        product *= arr[i];
    }
    return product;
}

// Впорядкувати непарні елементи масиву за спаданням
void bubbleSort(vector<double>& t, int size) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < size; ++i) {
            if (t[i - 1] < t[i] && static_cast<int>(t[i - 1]) % 2 != 0 && static_cast<int>(t[i]) % 2 != 0) {
                // Обмін елементів, якщо вони непарні та не відсортовані за спаданням
                double x = t[i - 1];
                t[i - 1] = t[i];
                t[i] = x;
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    double a = 1.0;
    double b = 1.0;
    int N;
    cout << "Enter lenght of array: "; 
    cin >> N;

    const int SIZE = N;

    vector <double> arr(N);

    fillArrayWithRandomNumbers(arr, N, a, b);
    PrintArr(arr, N);

    double result = sumElements(arr, N);

    cout << endl;
    cout << "==================================="<<endl;
    cout << "Sum elements: " << setw(11) << right << result <<endl;
    cout << "The product elements: " << setw(2) << right << minAndMax(arr, N) <<endl;
    cout << "===================================" << endl;

    bubbleSort(arr, N);
    PrintArr(arr, N);
   
    return 0;
}
