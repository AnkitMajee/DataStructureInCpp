#include <bits\stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mSort(arr, left, mid);
        mSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(vector<int> &arr)
{
    mSort(arr, 0, arr.size() - 1);
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void qSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        qSort(arr, low, pi - 1);
        qSort(arr, pi + 1, high);
    }
}

void quickSort(vector<int> &arr)
{
    qSort(arr, 0, arr.size() - 1);
}

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void countSort(vector<int> &arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); ++i)
        count[arr[i] - min]++;
    for (int i = 1; i < count.size(); ++i)
        count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = output[i];
}

void radixCountSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n), count(10);
    for (int i = 0; i < n; ++i)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; --i)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radixSort(vector<int> &arr)
{
    int max = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max / exp > 0; exp *= 10)
        radixCountSort(arr, exp);
}

void bucketSort(vector<int> &arr)
{
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    int bucketCount = max / 10 + 1;
    vector<vector<int>> buckets(bucketCount);
    for (int i = 0; i < n; ++i)
    {
        int index = arr[i] / 10;
        buckets[index].push_back(arr[i]);
    }
    for (int i = 0; i < bucketCount; ++i)
        sort(buckets[i].begin(), buckets[i].end());
    int index = 0;
    for (int i = 0; i < bucketCount; ++i)
        for (int j = 0; j < buckets[i].size(); ++j)
            arr[index++] = buckets[i][j];
}

void shellSort(vector<int> &arr)
{
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; ++i)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
}

double measureTime(void (*sortFunc)(vector<int> &), vector<int> &arr, int repetitions)
{
    double totalElapsed = 0.0;
    for (int i = 0; i < repetitions; ++i)
    {
        vector<int> arrCopy = arr;
        auto start = chrono::high_resolution_clock::now();
        sortFunc(arrCopy);
        auto end = chrono::high_resolution_clock::now();
        totalElapsed += chrono::duration<double>(end - start).count();
    }
    return totalElapsed / repetitions;
}

int main()
{
    srand(time(0));
    vector<int> inputSize = {1000, 2000, 5000, 10000, 20000, 30000, 40000, 50000, 60000};
    vector<void (*)(vector<int> &)> sorting_functions = {
        bubbleSort, insertionSort, selectionSort, mergeSort, quickSort,
        heapSort, countSort, radixSort, bucketSort, shellSort};
    vector<string> sorting_names = {
        "BubbleSort", "InsertionSort", "SelectionSort", "MergeSort", "QuickSort",
        "HeapSort", "CountSort", "RadixSort", "BucketSort", "ShellSort"};

    ofstream outFile("results.csv");
    outFile << "InputSize";
    for (const auto &name : sorting_names)
    {
        outFile << "," << name;
    }
    outFile << "\n";

    int repetitions = 10;
    for (const auto &size : inputSize)
    {
        vector<int> arr(size);
        for (int &elem : arr)
        {
            elem = rand() % 1000;
        }
        outFile << size;
        for (const auto &sortFunc : sorting_functions)
        {
            double time = measureTime(sortFunc, arr, repetitions);
            cout << sorting_names[&sortFunc - &sorting_functions[0]] << " with size " << size << ": " << time << " seconds\n";
            outFile << "," << time;
        }
        outFile << "\n";
    }
    outFile.close();
    
    return 0;
}