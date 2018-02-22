# Stack Smashing

## Questions

1. Stack Canaries is a mechanism that helps to protect from buffer overflow attacks. Basically when a return address is stored in the frame, a random integer chosen by the program
will be placed before it, and the integer is called the canary value. Therefore, when someone attemps to attack the program using buffer overflow, then canary value will likely
be rewritten and therefore an attack will be detected by the program.

2. It is a reference to canaries used in coal mines to detect toxic gas at the beginning of 20th centuary.

3.
int calculation(int n)
{
    return n * n + 2147483647;
    // the maximum integer value is +2147483647
}


Reference: https://stackoverflow.com/questions/26158/how-does-a-stack-overflow-occur-and-how-do-you-prevent-it

## Debrief

1. wikipedia, youtube, stackoverflow.com (ref'ed above)

2. 15 min
