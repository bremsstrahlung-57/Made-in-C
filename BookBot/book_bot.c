#include<stdio.h>
#include<ctype.h>

    int main()
{
    FILE* fp;
    int presentChar;
    int arr[27] = {0};

    fp = fopen("file.txt", "r");

    while ((presentChar = tolower(fgetc(fp))) != EOF){
        if(isalpha(presentChar) != 0){
            int idx = presentChar;
            arr[idx-97] += 1;
        }
        else if (isdigit(presentChar) != 0){
            arr[26] += 1;            
        }
    }
    for(int i=0 ; i<(sizeof(arr)/sizeof(arr[0])) ; i++){
        if(i != 26){
            printf("%c -> %d\n",97+i,arr[i]);
        }
        else{
            printf("num -> %d\n",arr[i]);
            
        }
    }
    fclose(fp);
}