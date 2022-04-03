
#include<stdio.h>
int main() {
int countTable[] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
int arr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned int number, w;
//number = 4294967295;

number = 65536;
for(int i=0;i<65536;i++){
w = 0;
int c=i;
while( c > 0)
{
w += countTable[c & 15];
c = (c >> 4);
}
arr[w]=arr[w]+1;
}

for(int i=0;i<16;i++){
    printf("%d ", arr[i]);
}
//определяем число единиц в следующих 4 разрядах(w2)
//определяем число единиц в следующих 4 разрядах(w3)
printf("%d", w);
}