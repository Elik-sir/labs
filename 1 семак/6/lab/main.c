// обработать табуляцию
// слияние 3-х файлов

#include <stdio.h>

#include "util.h"
#include "tree.h"

void readWords(tree *tree_p, FILE *file);

int main()
{

    tree *tree_p = createTree();
    FILE *file, *file1, *file2, *file3;

    fopen_s(&file, "test.txt", "r");
    exitIfNull(file, "No file!");
    fopen_s(&file1, "test2.txt", "r");
    exitIfNull(file1, "No file!");
    fopen_s(&file2, "test3.txt", "r");
    exitIfNull(file2, "No file!");
    char current_symbol;
    file3 = fopen("merged.txt", "w+");
    while (!feof(file))
    {
        current_symbol = fgetc(file);

        if (current_symbol == EOF || current_symbol == '\0')
        {
            fputc(' ', file3);
            break;
        }
        fputc(current_symbol, file3);
    }
    while (!feof(file1))
    {
        current_symbol = fgetc(file1);
        if (current_symbol == EOF || current_symbol == '\0')
        {
            fputc(' ', file3);
            break;
        }
        fputc(current_symbol, file3);
    }

    while (!feof(file2))
    {
        current_symbol = fgetc(file2);
        if (current_symbol == EOF || current_symbol == '\0')
        {
            fputc(' ', file3);
            break;
        }
        fputc(current_symbol, file3);
    }
    fclose(file);
    fclose(file1);
    fclose(file2);
    fclose(file3);
    file3 = fopen("merged.txt", "r");
    readWords(tree_p, file3);
    fclose(file3);
    printTree(tree_p);
    printf("\n");

    printf("%d\n", calculateDepth(tree_p));

    return 0;
}

void readWords(tree *tree_p, FILE *file)
{
    int buffIndex = 0;
    char buff[100];

    int tempWordSize = 10, tempWordInd = 0;
    char *tempWord = (char *)newMem(sizeof(char) * tempWordSize);

    char c = '\0';

    while (1)
    {
        fgets(buff, 100, file);
        for (int i = 0; i < 99; i++)
        {
            c = buff[i];

            if ((!isValidSymbol(c) || c == '\n' || c == '\0') && isValidSymbol(buff[i + 1]))
            {
                if (tempWordInd >= tempWordSize)
                {
                    tempWord = (char *)resizeMem(tempWord, tempWordSize += 1);
                }
                tempWord[tempWordInd++] = '\0';

                insertTreeNode(tree_p, tempWord);

                tempWord = (char *)newMem(sizeof(char) * (tempWordSize = 10));
                tempWordInd = 0;

                if (c == '\0')
                {

                    goto end;
                }
                if (c == '\n')
                {
                    i++;
                }

                continue;
            }

            if (c == '\0')
            {
                printf("%c", c);
                goto end;
            }

            if (isValidSymbol(c))
            {
                if (tempWordInd >= tempWordSize)
                {
                    tempWord = (char *)resizeMem(tempWord, tempWordSize *= 2);
                }

                tempWord[tempWordInd++] = c;
            }
        }
    }

end:;
}