#include "monty.h"

int main(int argc, char *argv[])
{
    char *filename, *opcode;
    stack_t *stack = NULL;
    FILE *file;
    char line[256];
    unsigned int line_number = 1;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    filename = argv[1];
    file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        return EXIT_FAILURE;
    }

       
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = '\0';  /*Remove newline character*/

        /* Split line into tokens*/
        opcode = strtok(line, " ");

        if (opcode)
        {
            if (strcmp(opcode, "push") == 0)
                push(&stack, line_number);
            else if (strcmp(opcode, "pall") == 0)
                pall(&stack, line_number);
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                return EXIT_FAILURE;
            }
        }

        line_number++;
    }

    fclose(file);
    return 0;
}
