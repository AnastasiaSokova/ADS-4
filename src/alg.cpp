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

int binsearch(int* arr, int k, int len, int element) {
    int mid, side;
    int count = 0;
    int i = k; int j = len;
    while (i < j - 1) {
        int mid = i + (j - i) / 2;
        if (arr[mid] > element) {
            j = mid;
        } else if (arr[mid] < element) {
            i = mid;
        } else {
            count++;
            side = mid - 1;
            while (arr[side] == element) {
                if (side > i) {
                    side--;
                    count++;
                }
            }
            side = mid + 1;
            while (arr[side] == element) {
                if (side < j) {
                    side++;
                    count++;
                }
            }
            break;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    sort(arr, len);
    int count = 0;
    int element;
    for (int k = 0; k < len - 1; ++k) {
        element = value - arr[k];
        count += binsearch(arr, k, len, element);
    }
    return count;
}
