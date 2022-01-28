const short LCO = 'A' - 'a'; //Lower case offset

int length(char *word)
{
    int i = 0;
    while (word[i] != '\0')
    {
        i++;
    }
    return i;
}

short toLowerCase(char c)
{
    return c >= 'a' ? c : c + ' ';
}

short compareByAlphabet(char *word1, char *word2)
{
    for (int i = 0; word1[i] != '\0' && word2[i] != '\0'; i++)
    {
        int res = (int)toLowerCase(word1[i]) - (int)toLowerCase(word2[i]);
        if (res > 0)
        {
            return 1;
        }
        else if (res < 0)
        {
            return 0;
        }
    }
    return length(word1) > length(word2);
}