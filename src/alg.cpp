// Copyright 2021 NNTU-CS
void sort(int* arr, int len) {
    int element;
    bool flag;
    for (int i = len - 1; i > 0; --i) {
        flag = true;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                element = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = element;
                flag = false;
            }
        }
        if (flag) {
            break;
        }
    }
}

int countPairs1(int *arr, int len, int value) {
  sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
  sort(arr, len);
    int count = 0;
    for (int i = len; i >= 0; --i) {
        if (arr[i] <= value) {
            for (int j = i + 1; j < len; ++j) {
                if (arr[i] + arr[j] == value) {
                    count++;
                }
            }
        }
    }
    return count;
}

int binsearch(int* arr, int size, int value, int place) {
    int i = 0, j = size - 1;
    int k = 0;
    int* brr = new int[size];
    for (int i = 0; i < size; ++i) {
        brr[i] = 0;
    }
    while (i < j) {
        int mid = i + (j - i) / 2;
        if (arr[mid] >= value) {
            j = mid;
        } else {
            i = mid + 1;
        }
        if (arr[j] == value && brr[j] == 0 && j != place) {
            k++;
            brr[j] = 1;
        }
    }
    return k;
}

int countPairs3(int *arr, int len, int value) {
    sort(arr, len);
    int count = 0;
    int element = 0;
    int* f = new int[len];
    bool flag;
    for (int i = 0; i < len; ++i) {
        f[i] = INT16_MAX;
    }
    for (int i = 0; i < len; ++i) {
        flag = true;
        element = value - arr[i];
        for (int k = 0; k < len; ++k) {
            if (f[k] == element) {
                flag = false;
            }
        }
        if (flag) {
            count += binsearch(arr, len, element, i);
            f[i] = arr[i];
        }
    }
    return count;
}
