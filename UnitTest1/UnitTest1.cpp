#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../Lab07_1rec/Lab07_1rec.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

// Допоміжна функція для створення масиву
int** CreateArray(const int rowCount, const int colCount) {
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];
    return a;
}

// Допоміжна функція для видалення масиву
void DeleteArray(int** a, const int rowCount) {
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
}

namespace ArrayTest
{
    TEST_CLASS(ArrayTest)
    {
    public:

        TEST_METHOD(CreateTest)
        {
            int rowCount = 3, colCount = 4;
            int** a = CreateArray(rowCount, colCount);
            Create(a, rowCount, colCount, 1, 10, 0, 0);

            // Перевіряємо, що значення в масиві знаходяться в межах [1, 10]
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::IsTrue(a[i][j] >= 1 && a[i][j] <= 10);
                }
            }

            DeleteArray(a, rowCount);
        }

        TEST_METHOD(SortTest)
        {
            int rowCount = 3, colCount = 3;
            int** a = CreateArray(rowCount, colCount);

            // Заповнюємо масив вручну для перевірки сортування
            a[0][0] = 3; a[0][1] = 2; a[0][2] = 1;
            a[1][0] = 2; a[1][1] = 3; a[1][2] = 1;
            a[2][0] = 1; a[2][1] = 2; a[2][2] = 3;

            Sort(a, rowCount, colCount);

            // Перевіряємо, що масив відсортовано за першим, другим і третім елементами
            Assert::AreEqual(1, a[0][0]);
            Assert::AreEqual(2, a[1][0]);
            Assert::AreEqual(3, a[2][0]);

            DeleteArray(a, rowCount);
        }
    };
}
