

template <typename T>
void printVector(std::vector<T>& v) {

    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
        std::cout << *i << ' ';

    std::cout << '\n';
}

template <typename T>
void populateVector(std::vector<T>& v, const int cardinality, const int min, const int max) {


    // this is an alternative to using rand() and srand(˜)
    std::default_random_engine generator;

    // this sets the seed to system time; removing it or changing to a constant value will make the random numbers the same between calls
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

    std::uniform_int_distribution<int> distributor{ min, max };


    for (int i = 0; i < cardinality; ++i)
        v.push_back(distributor(generator));


}

template <typename T>
const T& parseMedian(std::vector<T>& v, int lhs, int rhs)
{
    int mid = (lhs + rhs) / 2;

    if (v[mid] < v[lhs])
        std::swap(v[lhs], v[mid]);

    if (v[rhs] < v[lhs])
        std::swap(v[lhs], v[rhs]);

    if (v[rhs] < v[mid])
        std::swap(v[mid], v[rhs]);

    std::swap(v[mid], v[--rhs]);

    return v[rhs];
}


template <typename T>
const T& parseMiddle(std::vector<T>& v, int lhs, int rhs) {
    int mid = (lhs + rhs) / 2;
    return v[mid];
}



template <typename T>
void insertionSort(std::vector<T>& v, int lhs, int rhs)
{
    for (int p = lhs + 1; p <= rhs; ++p)
    {
        T tmp = std::move(v[p]);

        int j;

        for (j = p; j > lhs && tmp < v[j - 1]; --j)
            v[j] = std::move(v[j - 1]);
        v[j] = std::move(tmp);
    }
}


template <typename T>
void quicksortHybridMiddle(std::vector<T>& v, int lhs, int rhs)
{
    // this works with insertion sort
    // need to find way to work in quicksort-only mode
    int threshold = 20; // change to pass as a variable

    if (lhs + threshold <= rhs) {

        //std::cout << "performing quicksort\n";
        // branch here depending on middle or median3 parameter
        // ie if median==true

        // if using middle:
        const T& pivot = parseMiddle(v, lhs, rhs);

        // if using median-of-three:
        //const T &pivot = parseMedian(v, lhs, rhs);


        // partition
        int i = lhs, j = rhs - 1;

        for (; ; ) {
            while (v[++i] < pivot) {} // can change to for loops
            while (pivot < v[--j]) {}

            if (i < j)
                std::swap(v[i], v[j]);

            else
                break;
        }

        std::swap(v[i], v[rhs - 1]);

        quicksortHybridMiddle(v, lhs, i - 1);
        quicksortHybridMiddle(v, i + 1, rhs);
    }

    else { insertionSort(v, lhs, rhs); }
}


template <typename T>
void quicksortHybridMedian3(std::vector<T>& v, int lhs, int rhs)
{
    // this works with insertion sort
    // need to find way to work in quicksort-only mode
    int threshold = 20; // change to pass as a variable

    if (lhs + threshold <= rhs) {

        const T& pivot = parseMedian(v, lhs, rhs);

        // partition
        int i = lhs, j = rhs - 1;

        for (; ; ) {
            while (v[++i] < pivot) {}
            while (pivot < v[--j]) {}

            if (i < j)
                std::swap(v[i], v[j]);

            else
                break;
        }

        std::swap(v[i], v[rhs - 1]);

        quicksortHybridMedian3(v, lhs, i - 1);
        quicksortHybridMedian3(v, i + 1, rhs);
    }

    else { insertionSort(v, lhs, rhs); }
}


template <typename T>
void quicksortHybridMiddle(std::vector<T>& v)
{
    quicksortHybridMiddle(v, 0, v.size() - 1);
}


template <typename T>
void quicksortHybridMedian3(std::vector<T>& v)
{
    quicksortHybridMedian3(v, 0, v.size() - 1);
}


template <typename T>
int partitionMiddle(std::vector<T>& v, int lhs, int rhs) {


    //int pivot = lhs + (rhs - lhs) / 2;


    int pivot = parseMiddle(v, lhs, rhs);
    //int pivot = parseMedian(v, lhs, rhs);

    //int pivot = v[mid];


    int i = lhs, j = rhs;
    int temp;

    while (i <= j) {

        while (v[i] < pivot) { i++; }
        while (v[j] > pivot) { j--; }

        if (i <= j)
        {
            //std::swap(v[i++], v[j]);
            temp = v[i];
            v[i++] = v[j];
            v[j--] = temp;
        }

    }
    return i;
}



template <typename T>
int partitionMedian3(std::vector<T>& v, int lhs, int rhs) {


    //int pivot = lhs + (rhs - lhs) / 2;


    //int pivot = parseMiddle(v, lhs, rhs);
    int pivot = parseMedian(v, lhs, rhs);

    //int pivot = v[mid];


    int i = lhs, j = rhs;
    int temp;

    while (i <= j) {

        while (v[i] < pivot) { i++; }
        while (v[j] > pivot) { j--; }

        if (i <= j) {
            //std::swap(v[i++], v[j]);
            temp = v[i];
            v[i++] = v[j];
            v[j--] = temp;


        }
            

    }
    return i;
}

template <typename T>
void quicksortNormalMiddle(std::vector<T>& v, int lhs, int rhs) {
    if (lhs < rhs) {
        int pivot = partitionMiddle(v, lhs, rhs);


        quicksortNormalMiddle(v, lhs, pivot - 1);
        quicksortNormalMiddle(v, pivot, rhs);
    }
}

template <typename T>
void quicksortNormalMedian3(std::vector<T>& v, int lhs, int rhs) {
    if (lhs < rhs) {
        int pivot = partitionMedian3(v, lhs, rhs);


        quicksortNormalMedian3(v, lhs, pivot - 1);
        quicksortNormalMedian3(v, pivot, rhs);
    }
}



template <typename T>
void quicksortNormalMiddle(std::vector<T>& v) {
    quicksortNormalMiddle(v, 0, v.size() - 1);
}

template <typename T>
void quicksortNormalMedian3(std::vector<T>& v) {
    quicksortNormalMedian3(v, 0, v.size() - 1);
}

