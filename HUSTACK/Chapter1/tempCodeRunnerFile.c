
    int array[n];
    int count = 0;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &array[i]);
        if(sqrt(array[i]) == (int)(sqrt(array[i]))) {
            count ++;
        }
    }
    printf("%d", count);
    return 0;
}