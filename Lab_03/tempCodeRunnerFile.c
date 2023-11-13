
    else
    {
        printf("Rejected\n");
    }

    path[pathLength++] = start;
    int n = pathLength;
    printf("path: ");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%c -> ", path[i]);
    }
    printf("\n\n");
    return 0;
}
