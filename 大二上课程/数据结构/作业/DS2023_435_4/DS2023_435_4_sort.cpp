#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

template <class T>
void Insert(const T& e, T* a, int i) 
{
	a[0] = e;
	while (e < a[i]) 
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;
}

template <class T>
void InsertionSort(T* a, const int n)
{
	for (int j = 2; j <= n; j++)
	{
		T temp = a[j];
		Insert(temp, a, j - 1);
	}
}

template <class T>
void swap(T& a, T& b) 
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
const T& medianOfThree(const T& a, const T& b, const T& c) 
{
    if ((a < b && b < c) || (c < b && b < a))
        return b;
    else if ((b < a && a < c) || (c < a && a < b))
        return a;
    else
        return c;
}

template <class T>
void QuickSort(T* a, const int left, const int right) 
{
    if (left < right) 
    {
        int i = left, j = right + 1;
        const T& pivot = medianOfThree(a[left], a[(left + right) / 2], a[right]);

        do 
        {
            do i++; while (a[i] < pivot);
            do j--; while (a[j] > pivot);
            if (i < j) 
            {
                T temp1 = a[i];
                a[i] = a[j];
                a[j] = temp1;
            }
        } while (i < j);

        T temp2 = a[left];
        a[left] = a[j];
        a[j] = temp2;        // Swap pivot into the correct place

        QuickSort(a, left, j - 1); // Sort the left subarray
        QuickSort(a, j + 1, right); // Sort the right subarray
    }
}

template <class T>
void Merge(T* initList, T* mergedList, int l, int m, int n)
{
    int i1 = l, i2 = m + 1, iResult = l;
    while (i1 <= m && i2 <= n)
    {
        if (initList[i1] <= initList[i2])
            mergedList[iResult++] = initList[i1++];
        else
            mergedList[iResult++] = initList[i2++];
    }

    while (i1 <= m) 
        mergedList[iResult++] = initList[i1++];

    while (i2 <= n) 
        mergedList[iResult++] = initList[i2++];
}

template <class T>
void MergePass(T* initList, T* resultList, int n, int s)
{
    for (int i = 0; i <= n - 2 * s; i += 2 * s)
    {
        int end = min(i + 2 * s - 1, n - 1); 
        Merge(initList, resultList, i, i + s - 1, end);
    }
    if (n - s > 0)
    {
        Merge(initList, resultList, n - s - s, n - s - 1, n - 1); 
    }
}

template <class T>
void MergeSort(T* a, const int n)
{
    T* tempList = new T[n + 1];
    for (int l = 1; l < n; l *= 2)
    {
        MergePass(a, tempList, n, 1);
        l *= 2;
        MergePass(tempList, a, n, l);
    }
    delete[] tempList;
}

template <class T>
void Adjust(T* a, const int root, const int n)
{
    T e = a[root];
    int j;

    for (j = 2 * root; j <= n; j *= 2)
    {
        if (j < n && a[j] < a[j + 1])
            j++;
        if (e >= a[j])
            break;
        a[j / 2] = a[j];
    }

    a[j / 2] = e;
}

template <class T>
void HeapSort(T* a, const int n)
{
    for (int i = n / 2; i >= 1; i--)
        Adjust(a, i, n);

    for (int i = n - 1; i >= 1; i--)
    {
        T temp = a[1];
        a[1] = a[i+1];
        a[i+1] = temp;
        Adjust(a, 1, i);
    }
}

template <class T>
void Permute(T* a, int n)
{
    for (int i = n; i >= 2; i--)
    {
        int j = rand() % i + 1;
            T temp = a[j];
            a[j] = a[i];
            a[i] = temp;
    }
}

int main()
{
    const int n1 = 500;
    const int n2 = 1000;
    const int n3 = 2000;
    const int n4 = 3000;
    const int n5 = 4000;
    const int n6 = 5000;
    int a1[n1];
    int a2[n2];
    int a3[n3];
    int a4[n4];
    int a5[n5];
    int a6[n6];
    for (int i = n1; i > 0; --i)
        a1[n1 - i] = i;
    for (int i = n2; i > 0; --i)
        a2[n2 - i] = i;
    for (int i = n3; i > 0; --i)
        a1[n3 - i] = i;
    for (int i = n4; i > 0; --i)
        a2[n4 - i] = i;
    for (int i = n5; i > 0; --i)
        a1[n5 - i] = i;
    for (int i = n6; i > 0; --i)
        a2[n6 - i] = i;

    int num_tests = 3000;

//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª500¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª500¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
    cout << "\n\nn = 500£º" << endl;
    clock_t start51 = clock();
    for (int i = 0; i < num_tests; ++i)
        InsertionSort(a1, n1);
    clock_t end51 = clock();
    double elapsed51 = double(end51 - start51) / CLOCKS_PER_SEC;
    double average_time51 = elapsed51 / static_cast<double>(num_tests);
    cout << "Average time for InsertionSort: " << average_time51 << " seconds" << endl;

    clock_t start52 = clock();
    for (int i = 0; i < num_tests; ++i)
        QuickSort(a1, 0, n1 - 1);
    clock_t end52 = clock();
    double elapsed52 = double(end52 - start52) / CLOCKS_PER_SEC;
    double average_time52 = elapsed52 / static_cast<double>(num_tests);
    cout << "Average time for QuickSort: " << average_time52 << " seconds" << endl;

    clock_t start53 = clock();
    for (int i = 0; i < num_tests; ++i)
        MergeSort(a1, n1);
    clock_t end53 = clock();
    double elapsed53 = double(end53 - start53) / CLOCKS_PER_SEC;
    double average_time53 = elapsed53 / static_cast<double>(num_tests);
    cout << "Average time for MergeSort: " << average_time53 << " seconds" << endl;

    double max_total_time54 = 0;
    for (int j = 0; j < 10; ++j)
    {
        clock_t start54 = clock();
        for (int i = 0; i < num_tests; ++i)
        {
            Permute(a1, n1);
            HeapSort(a1, n1);
        }
        clock_t end54 = clock();
        double elapsed54 = double(end54 - start54) / CLOCKS_PER_SEC;
        if (max_total_time54 < elapsed54)
            max_total_time54 = elapsed54;
    }
    double average_time54 = max_total_time54 / static_cast<double>(num_tests);
    cout << "Average time for HeapSort: " << average_time54 << " seconds" << endl;


    //¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª1000¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª1000¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
    cout << "\n\nn = 1000£º" << endl;
    clock_t start101 = clock();
    for (int i = 0; i < num_tests; ++i)
        InsertionSort(a2, n2);
    clock_t end101 = clock();
    double elapsed101 = double(end101 - start101) / CLOCKS_PER_SEC;
    double average_time101 = elapsed101 / static_cast<double>(num_tests);
    cout << "Average time for InsertionSort: " << average_time101 << " seconds" << endl;

    clock_t start102 = clock();
    for (int i = 0; i < num_tests; ++i)
        QuickSort(a2, 0, n2 - 1);
    clock_t end102 = clock();
    double elapsed102 = double(end102 - start102) / CLOCKS_PER_SEC;
    double average_time102 = elapsed102 / static_cast<double>(num_tests);
    cout << "Average time for QuickSort: " << average_time102 << " seconds" << endl;

    clock_t start103 = clock();
    for (int i = 0; i < num_tests; ++i)
        MergeSort(a2, n2);
    clock_t end103 = clock();
    double elapsed103 = double(end103 - start103) / CLOCKS_PER_SEC;
    double average_time103 = elapsed103 / static_cast<double>(num_tests);
    cout << "Average time for MergeSort: " << average_time103 << " seconds" << endl;

    long long max_total_time104 = 0;
    for (int j = 0; j < 10; ++j)
    {
        clock_t start104 = clock();
        for (int i = 0; i < num_tests; ++i)
        {
            Permute(a2, n2);
            HeapSort(a2, n2);
        }
        clock_t end104 = clock();
        double elapsed104 = double(end104 - start104) / CLOCKS_PER_SEC;
        if (max_total_time104 < elapsed104)
            max_total_time104 = elapsed104;
    }
    double average_time104 = max_total_time104 / static_cast<double>(num_tests);
    cout << "Average time for HeapSort: " << average_time104 << " seconds" << endl;


    //¡ª¡ª¡ª¡ª¡ª¡ª¡ª2000¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª2000¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
    cout << "\n\nn = 2000£º" << endl;
    clock_t start201 = clock();
    for (int i = 0; i < num_tests; ++i)
        InsertionSort(a3, n3);
    clock_t end201 = clock();
    double elapsed201 = double(end201 - start201) / CLOCKS_PER_SEC;
    double average_time201 = elapsed201 / static_cast<double>(num_tests);
    cout << "Average time for InsertionSort: " << average_time201 << " seconds" << endl;

    clock_t start202 = clock();
    for (int i = 0; i < num_tests; ++i)
        QuickSort(a3, 0, n3 - 1);
    clock_t end202 = clock();
    double elapsed202 = double(end202 - start202) / CLOCKS_PER_SEC;
    double average_time202 = elapsed202 / static_cast<double>(num_tests);
    cout << "Average time for QuickSort: " << average_time202 << " seconds" << endl;

    clock_t start203 = clock();
    for (int i = 0; i < num_tests; ++i)
        MergeSort(a3, n3);
    clock_t end203 = clock();
    double elapsed203 = double(end203 - start203) / CLOCKS_PER_SEC;
    double average_time203 = elapsed203 / static_cast<double>(num_tests);
    cout << "Average time for MergeSort: " << average_time203 << " seconds" << endl;

    long long max_total_time204 = 0;
    for (int j = 0; j < 10; ++j)
    {
        clock_t start204 = clock();
        for (int i = 0; i < num_tests; ++i)
        {
            Permute(a3, n3);
            HeapSort(a3, n3);
        }
        clock_t end204 = clock();
        double elapsed204 = double(end204 - start204) / CLOCKS_PER_SEC;
        if (max_total_time204 < elapsed204)
            max_total_time204 = elapsed204;
    }
    double average_time204 = max_total_time204 / static_cast<double>(num_tests);
    cout << "Average time for HeapSort: " << average_time204 << " seconds" << endl;


    //¡ª¡ª¡ª¡ª¡ª¡ª¡ª3000¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª3000¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
    cout << "\n\nn = 3000£º" << endl;
    clock_t start301 = clock();
    for (int i = 0; i < num_tests; ++i)
        InsertionSort(a4, n4);
    clock_t end301 = clock();
    double elapsed301 = double(end301 - start301) / CLOCKS_PER_SEC;
    double average_time301 = elapsed301 / static_cast<double>(num_tests);
    cout << "Average time for InsertionSort: " << average_time301 << " seconds" << endl;

    clock_t start302 = clock();
    for (int i = 0; i < num_tests; ++i)
        QuickSort(a4, 0, n4 - 1);
    clock_t end302 = clock();
    double elapsed302 = double(end302 - start302) / CLOCKS_PER_SEC;
    double average_time302 = elapsed302 / static_cast<double>(num_tests);
    cout << "Average time for QuickSort: " << average_time302 << " seconds" << endl;

    clock_t start303 = clock();
    for (int i = 0; i < num_tests; ++i)
        MergeSort(a4, n4);
    clock_t end303 = clock();
    double elapsed303 = double(end303 - start303) / CLOCKS_PER_SEC;
    double average_time303 = elapsed303 / static_cast<double>(num_tests);
    cout << "Average time for MergeSort: " << average_time303 << " seconds" << endl;

    long long max_total_time304 = 0;
    for (int j = 0; j < 10; ++j)
    {
        clock_t start304 = clock();
        for (int i = 0; i < num_tests; ++i)
        {
            Permute(a4, n4);
            HeapSort(a4, n4);
        }
        clock_t end304 = clock();
        double elapsed304 = double(end304 - start304) / CLOCKS_PER_SEC;
        if (max_total_time304 < elapsed304)
            max_total_time304 = elapsed304;
    }
    double average_time304 = max_total_time304 / static_cast<double>(num_tests);
    cout << "Average time for HeapSort: " << average_time304 << " seconds" << endl;


    //¡ª¡ª¡ª¡ª¡ª¡ª¡ª4000¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª4000¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
    cout << "\n\nn = 4000£º" << endl;
    clock_t start401 = clock();
    for (int i = 0; i < num_tests; ++i)
        InsertionSort(a5, n5);
    clock_t end401 = clock();
    double elapsed401 = double(end401 - start401) / CLOCKS_PER_SEC;
    double average_time401 = elapsed401 / static_cast<double>(num_tests);
    cout << "Average time for InsertionSort: " << average_time401 << " seconds" << endl;

    clock_t start402 = clock();
    for (int i = 0; i < num_tests; ++i)
        QuickSort(a5, 0, n5 - 1);
    clock_t end402 = clock();
    double elapsed402 = double(end402 - start402) / CLOCKS_PER_SEC;
    double average_time402 = elapsed402 / static_cast<double>(num_tests);
    cout << "Average time for QuickSort: " << average_time402 << " seconds" << endl;

    clock_t start403 = clock();
    for (int i = 0; i < num_tests; ++i)
        MergeSort(a5, n5);
    clock_t end403 = clock();
    double elapsed403 = double(end403 - start403) / CLOCKS_PER_SEC;
    double average_time403 = elapsed403 / static_cast<double>(num_tests);
    cout << "Average time for MergeSort: " << average_time403 << " seconds" << endl;

    long long max_total_time404 = 0;
    for (int j = 0; j < 10; ++j)
    {
        clock_t start404 = clock();
        for (int i = 0; i < num_tests; ++i)
        {
            Permute(a5, n5);
            HeapSort(a5, n5);
        }
        clock_t end404 = clock();
        double elapsed404 = double(end404 - start404) / CLOCKS_PER_SEC;
        if (max_total_time404 < elapsed404)
            max_total_time404 = elapsed404;
    }
    double average_time404 = max_total_time404 / static_cast<double>(num_tests);
    cout << "Average time for HeapSort: " << average_time404 << " seconds" << endl;


    //¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª5000¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª5000¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
    cout << "\n\nn = 5000£º" << endl;
    clock_t start501 = clock();
    for (int i = 0; i < num_tests; ++i)
        InsertionSort(a6, n6);
    clock_t end501 = clock();
    double elapsed501 = double(end501 - start501) / CLOCKS_PER_SEC;
    double average_time501 = elapsed501 / static_cast<double>(num_tests);
    cout << "Average time for InsertionSort: " << average_time501 << " seconds" << endl;

    clock_t start502 = clock();
    for (int i = 0; i < num_tests; ++i)
        QuickSort(a6, 0, n6 - 1);
    clock_t end502 = clock();
    double elapsed502 = double(end502 - start502) / CLOCKS_PER_SEC;
    double average_time502 = elapsed502 / static_cast<double>(num_tests);
    cout << "Average time for QuickSort: " << average_time502 << " seconds" << endl;

    clock_t start503 = clock();
    for (int i = 0; i < num_tests; ++i)
        MergeSort(a6, n6);
    clock_t end503 = clock();
    double elapsed503 = double(end503 - start503) / CLOCKS_PER_SEC;
    double average_time503 = elapsed503 / static_cast<double>(num_tests);
    cout << "Average time for MergeSort: " << average_time503 << " seconds" << endl;

    long long max_total_time504 = 0;
    for (int j = 0; j < 10; ++j)
    {
        clock_t start504 = clock();
        for (int i = 0; i < num_tests; ++i)
        {
            Permute(a6, n6);
            HeapSort(a6, n6);
        }
        clock_t end504 = clock();
        double elapsed504 = double(end504 - start504) / CLOCKS_PER_SEC;
        if (max_total_time504 < elapsed504)
            max_total_time504 = elapsed504;
    }
    double average_time504 = max_total_time504 / static_cast<double>(num_tests);
    cout << "Average time for HeapSort: " << average_time504 << " seconds" << endl;

}