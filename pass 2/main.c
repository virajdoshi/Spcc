#include<stdio.h>
#include<string.h>
int main()
{
    FILE *f1, *f2, *f3;
    
    f1=fopen("input.txt","r");
    f2=fopen("symtbl.txt","r");
    
    int br_value, lc_symtbl, offset;
    char lb[20], m1[20], temp[20], op[20], mot[2][2]={"L","A","ST","\0"}, symtbl[20], br[20]={0};
    
    fscanf(f1,"%s %s %s %s",lb,m1,temp,op);
    while(!feof(f1))
    {
        if(strcmp(m1,"USING")==0)
        {
            br_value=0;
            br[0]=op[0];
            br[1]=op[1];
            printf("Base register: %s\n",br);
            printf("Value: %d\n",br_value);
        }
        
        for(int i=0;i<4;i++)
        {
            fscanf(f2,"%d %s", &lc_symtbl, symtbl);
            if(strcmp(op,symtbl)==0)
            {
                printf("%s, 1, ",m1);
                offset=lc_symtbl-br_value;
                printf("%d(%d,%s)\n",offset,br_value,br);
            }
        }
        fseek(f2,0,SEEK_SET);
        fscanf(f1,"%s %s %s %s",lb,m1,temp,op);
    }
}