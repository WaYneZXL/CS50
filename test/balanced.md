# Fair and Balanced

## Questions

1. Yes, because 16 + 26 = 3 + 39 = 42

2. Yes, because 0 + 0 = 0 + 0 = 0

3.

```c
//

bool balanced(int n, int array[])
{
    int lefthalf = 0;
    int righthalf = 0;

    if (n % 2 == 0)
    {
        int half = n / 2;

        for (i = 0; i < half; i++)
        {
            lefthalf = lefthalf + array[i];
        }

        for (j = half; j < n; j++)
        {
            righthalf = righthalf + array[j];
        }

    }
    else
    {
        int half = n / 2 - 1;

        for (i = 0; i < half; i++)
        {
            lefthalf = lefthalf + array[i];
        }

        for (j = half + 1 ; j < n; j++)
        {
            righthalf = righthalf + array[j];
        }

    }

    if (lefthalf = righthalf)
    {
        return true;
    }
    else
    {
        return false;
    }

}

```

## Debrief

1. NA

2. 20 min
