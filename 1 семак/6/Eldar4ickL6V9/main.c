#include <stdio.h>

#include "util.h"
#include "tree.h"

void readWords(tree *tree_p, FILE *file);

int main()
{

    tree *tree_p = createTree();
    FILE *file;

    fopen_s(&file, "test.txt", "r");
    exitIfNull(file, "No file!");
    readWords(tree_p, file);

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
            if (c == ' ' || c == '\n' || c == '\0')
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