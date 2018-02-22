# Emoji

## Questions

1. 4 bytes. Because wchar_t represents a 4-byte char.

2. No, because char is only 1 byte in c.

3.

```c
emoji get_emoji(string prompt)
{
    string input = get_string("Code point: ");
    string convert;
    convert[0] = 0;
    convert[1] = 'x';
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        do
        {
            string input = get_string("Code point: ");
        }
        while (input[0] != 'U' || input[1] != '+');

        convert[i] = input[i];

    }

    int emoji = atoi(convert);

    return emoji;

}
```

## Debrief

1. NA

2. 30 min
