#ifndef PRACTICE_ARRAY_H
#define PRACTICE_ARRAY_H

template<class T>
class Array {

private:
    T *data;
    int size;

    /**
     * Merge Sort
     */
    void merge(T *out, T *in1, int size1, T *in2, int size2) {
        int i1 = 0;
        int i2 = 0;
        int o = 0;

        while ( i1 < size1 && i2 < size2) {
            if (in1[i1] < in2[i2]) {
                out[o++] = in1[i1++];
            } else {
                out[o++] = in2[i2++];
            }
        }
        while ( i1 < size1 ) {
            out[o++] = in1[i1++];
        }
        while ( i2 < size2 ) {
            out[o++] = in2[i2++];
        }

    }

    void mergeSort(T *in, int l, int r) {

        if (r - l < 2) {
            return;
        }

        int mid = (l + r) / 2;
        int lSize = mid - l;
        int rSize = r - mid;
        int i;

        // Divide the input in to two sub arrays
        T *left = new T[lSize];
        T *right = new T[rSize];

        for(i = 0; i < lSize; i++) {
            left[i] = in[l + i];
        }
        for(i = 0; i < rSize; i++) {
            right[i] = in[mid + i];
        }

        mergeSort(left, 0, lSize);
        mergeSort(right, 0, rSize);

        merge(in, left, lSize, right, rSize);

        free(left);
        free(right);
    }

public:

    Array(int s) {
        size = s;
        data = new T[size];
    }

    ~Array() {
        delete [] data;
    }

    void generate_random() {
        int i;
        for (i=0;i<size;i++) {
            data[i] = rand() % 1000;
        }
    }

    void print(){
        std::cout << data[0];
        int i;
        for (i=1;i<size;i++) {
            std::cout << "," << data[i];
        }
        std::cout << std::endl;
    }

    void bubbleSort() {
        int i,j;
        for (i=size-1;i>=0;i--) {
            for (j=0;j<=i;j++) {
                if (data[j] > data[j+1]) {
                    T temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
            }
        }
    }

    void mergeSort() {
        mergeSort(data, 0, size);
    }

    /**
     * Simple Binary search
     */
    int find(T value) {

        int l = 0;
        int r = size - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if ( data[mid] == value ) {
                return mid;
            } else {
                if (value < data[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};


#endif //PRACTICE_ARRAY_H
