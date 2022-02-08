void exitIfNull(void* link, char* err_msg);

short isValidSymbol(const char c);

void* newMem(int size);

void* resizeMem(void* mem, int newSize);