double average(int* salary, int salarySize){
    /* one pass solution */
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;

    int *p = salary;
    for (int i = 0; i < salarySize; i++) {
        if (min > *p)
            min = *p;
        if (max < *p)
            max = *p;
        sum += *p;
        // printf("[%d, %d] %d\n", min, max, sum);
        p++;
    }
    return (sum - min - max) * 1.0 / (salarySize - 2);
}
