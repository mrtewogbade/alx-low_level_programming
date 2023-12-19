#include <stdio.h>

int main()
{
    // Create a file named "myfile.txt" and write the string "Hello, world!" to it
    int success = create_file("myfile.txt", "Hello, world!");

    if (success == 1)
    {
        printf("File created successfully!\n");
    }
    else
    {
        printf("Error creating file.\n");
    }

    return 0;
}

