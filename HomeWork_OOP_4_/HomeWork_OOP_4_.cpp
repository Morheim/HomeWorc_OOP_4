#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <string>
#include "blackjack.h"

using namespace std;

void DZ1()
{
    cout << "//===================================================[DZ1]===================================================//\n\n";
}
void DZ2()
{
    cout << "\n\n//===================================================[DZ2]===================================================//\n\n";
}
void DZ3()
{
    cout << "\n\n\n//===================================================[DZ3]===================================================//\n";
}
void delimiterDZ()
{
    cout << "\n//===========================================================================================================//\n\n";
}
void END()
{
    cout << "\n\n\n//===================================================[END]===================================================//\n\n";
}

/*      DZ1
    Добавить в контейнерный класс, который был написан в этом уроке, методы:
        •для удаления последнего элемента массива (аналог функции pop_back() в векторах)
        •для удаления первого элемента массива (аналог pop_front() в векторах)
        •для сортировки массива
        •для вывода на экран элементов.
*/

class ArrayInt
{
private:
    int* data;
    int length;
public:
    ArrayInt() : length(0), data(nullptr) {};

    ArrayInt(int inLength) : length(inLength)
    {
        assert(length >= 0);
        if (length > 0)
        {
            data = new int[length];
        }
        else
            data = nullptr;
    }

    void erase()
    {
        if (length > 0)
        {
            delete[] data;
            data = nullptr;
            length = 0;
        }
    }

    int getLength() const {
        return length;
    }

    int& operator[](int index)
    {
        return data[index];
    }

    void deleteLast()
    {

        assert(length != 0);

        if (length == 1)
        {
            erase();
        }
        else
        {
            int* new_data = new int[length - 1];

            for (int i = 0; i < length - 1; i++) {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
            length--;
        }
    }

    void deleteFirst()
    {
        assert(length != 0);

        if (length == 1)
        {
            erase();
        }
        else
        {
            int* new_data = new int[length - 1];

            for (int i = 0; i < length - 1; i++) {
                new_data[i] = data[i + 1];
            }

            delete[] data;
            data = new_data;
            length--;
        }
    }

    //сортировка пузырьком
    void sort()
    {
        assert(length != 0);

        int tempIndex = 0;
        int lastIndex = length - 1;
        int temp;

        while (lastIndex > 0)
        {
            if (data[tempIndex] > data[tempIndex + 1])
            {
                temp = data[tempIndex];
                data[tempIndex] = data[tempIndex + 1];
                data[tempIndex + 1] = temp;
            }

            if (tempIndex == lastIndex - 1)
            {
                tempIndex = 0;
                lastIndex--;
            }
            else
            {
                tempIndex++;
            }
        }
    }

    void print() const {
        assert(length != 0);

        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
        cout << "length: " << length << endl;
    }

    ~ArrayInt() {
        delete[] data;
    }
};

/*      DZ2
    Дан вектор чисел, требуется выяснить, сколько среди них различных.
    Постараться использовать максимально быстрый алгоритм.
*/
void printVector(vector<int>& input)
{
    cout << "\n";
    for (vector<int>::iterator it = input.begin(); it != input.end(); ++it)
        cout << *it << " ";
}
int countUniqueNumbers(vector<int> input)
{
    sort(input.begin(), input.end());
    vector<int>::iterator it;
    it = unique(input.begin(), input.end());
    input.resize(distance(input.begin(), it));
    //printVector(input); - test
    return input.size();
}

int main()
{
    setlocale(LC_ALL, "rus");
    {
        DZ1();
        int size = 0;
        cin >> size;
        ArrayInt array(size);
        for (int j = 0; j < size; j++)
        {
            array[j] = rand() % 50;
        }
        array.deleteFirst();
        array.deleteLast();
        array.print();
    }
    {
        DZ2();
        vector<int> array = { 92,32,32,14,73,43413,23,14,78,1,2,6,9,0,15 };
        cout << "\nНачальный массивчик: ";
        printVector(array);
        int count = countUniqueNumbers(array);
        cout << "\nУникальные числа: " << count;
    }

    {
        DZ3();
        Card aceClubs(ACE, CLUBS);
        Card aceHearts(ACE, HEARTS);
        Card kingClubs(KING, CLUBS);

        Hand playerHand;
        playerHand.Add(&aceClubs);
        playerHand.Add(&aceHearts);
        playerHand.Add(&kingClubs);

        int sum = playerHand.GetValue();
        std::cout << "\n\nКолличество очков игрока: " << sum;
        playerHand.Clear();
        sum = playerHand.GetValue();
        std::cout << "\nРука чиста! Новое колличество очков равно: " << sum;
        END();
    }
}