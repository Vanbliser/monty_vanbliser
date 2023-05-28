#include "monty.h"

/* Global variable to track the stack */
stack_t *stack = NULL;
char **token = NULL;

/* Custom strdup() function */
char *my_strdup(const char *str)
{
    size_t len = strlen(str) + 1;
    char *dup = (char *)malloc(len);
    if (dup)
    {
        memcpy(dup, str, len);
    }
    return dup;
}

/* Function to tokenize a line */
char **tokenize(char *line)
{
    const char *delimiters = " \t\n";
    char **tokens = NULL;
    char *token = NULL;
    int index = 0;

    tokens = (char **)malloc(sizeof(char *) * 3);
    if (!tokens)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, delimiters);
    while (token && index < 2)
    {
        tokens[index] = my_strdup(token);
        if (!tokens[index])
        {
            fprintf(stderr, "Error: strdup failed\n");
            free_tokens(tokens);
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, delimiters);
        index++;
    }
    tokens[index] = NULL;

    return tokens;
}

/* Function to free the memory used by tokens */
void free_tokens(char **tokens)
{
    int i = 0;
    while (tokens && tokens[i])
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

/* Main function */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line;
    /*size_t line_len = 0;*/
    unsigned int line_number = 0;

    /* Check the number of arguments */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    /* Open the input file */
    if (!(file = fopen(argv[1], "r")))
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    /* Process each line of the file */
    line = NULL;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;

	/*Remove trailing newline char*/

        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
	}

        token = tokenize(line);

        if (token && token[0])
	{

      		if (strcmp(token[0], "push") == 0)
                    push(&stack, line_number, token);
                else if (strcmp(token[0], "pall") == 0)
                    pall(&stack);
                else
		{

                    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token[0]);
                    free_stack(stack);
                    free_tokens(token);
                    fclose(file);
                    return EXIT_FAILURE;
                }
	}

        free_tokens(token);
    }
       
    free(line);
    /*line = NULL;
    line_len = 0;*/
    

    free_stack(stack);
    fclose(file);
    return EXIT_SUCCESS;
}
