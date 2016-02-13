#ifndef PRACTICE_ARRAY_H
#define PRACTICE_ARRAY_H

template<class T>
class Array {

private:
    T *data;
    int size;

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


    void merge(T *in1, int size1, T *in2, int size2, T *out ) {


    }

    void split(T *in, int start, int end) {

        if (start >= end) {
            return;
        }

        int mid = (end - start) / 2;

        T *left = new T[mid - start];
        T *right = new T[end - mid + 1];

        split(left, start, start + mid);
        split(right, start + mid + 1, end);

        merge(left, mid, right, end - mid + 2, 0);

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
