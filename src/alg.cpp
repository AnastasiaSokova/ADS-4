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
        for (int j = i; j < len; ++j) {
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
            for (int j = i; j < len; ++j) {
                if (arr[i] + arr[j] == value) {
                    count++;
                }
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
  sort(arr, len);
    int count = 0, element;
    bool flag;
    for (int l = 0; l < len; ++l) {
        element = value - arr[l];
        while (true) {
            flag = true;
            int i = l, j = len - 1;
            while (i < j) {
                int mid = i + (j - i) / 2;
                if (arr[mid] == element) {
                    for (int ii = mid; ii < len; ++ii) {
                        arr[ii] = arr[ii + 1];
                    }
                    len--;
                    count++;
                    flag = false;
                    break;
                }
                else if (arr[mid] > element) {
                    j = mid;
                }
                else {
                    i = mid + 1;
                }
            }
            if (i == j && arr[i] == element) {
                count++;
            }
            if (flag) {
                break;
            }
        }
    }
    return count;
}
