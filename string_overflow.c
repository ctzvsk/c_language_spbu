#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[40] = "Hello, ";
    char name[20];
    puts("What is your name?");

    // scanf %s -- string, %[^\n]s -- string with spaces (multiple words)
    // Fix format string to also avoid overflow.
    // See man 3 scanf or https://www.man7.org/linux/man-pages/man3/scanf.3.html#EXAMPLES
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0;
    strcat_s(s, 20, name);
    strcat_s(s, 20, "!");
    puts(s);
    return 0;
}