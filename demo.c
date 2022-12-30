#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
};
typedef struct Train Train;

int main(){
    char train_no[20];
    FILE *fp;
    fp=fopen("Train.txt","rb");
    Train pr;
    int count=0;
    fflush(stdin);
    fgets(train_no, 20, stdin);
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        printf("%s %s",train_no, pr.train_no);
        printf("%d : %d\n",++count,strcmp(pr.train_no,train_no));
    }
    return 0;
}