int next_turn(int total, int possible)
{

    int i, max, min;
    int fib[100];

    if (possible >= total)
        return total;

    fib[0] = 1;
    fib[1] = 1;
    for (i = 1; total >= fib[i]; i++)
    {
        fib[i + 1] = fib[i] + fib[i - 1];
    }

    min = max = total / fib[i - 1];

    for (i = i - 1; i > 0; i--)
    {
        if ((total / fib[i]) == 1)
            min = fib[i];
        total = total % fib[i];
    }

    if (possible >= min)
        return min;

    return 1;
}
