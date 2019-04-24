#include<stdio.h>
#include<string.h>
int main()
{
    FILE *f1, *f2, *f3;
    
    f1=fopen("input2.txt","r");
    f2=fopen("symtbl2.txt","r");
    
    int br_value, lc_symtbl, offset, ra, check=1;
    char lb[20], m1[20], temp[20], op[20], symtbl[20], br[20]={0};
    
    fscanf(f1,"%s %s %s %s",lb,m1,temp,op);
    while(!feof(f1))
    {
        if(strcmp(m1,"USING")==0)
        {
            br_value=0;
            strcpy(br,op);
            printf("Base register: %s\n",br);
            printf("Value: %d\n",br_value);
        }
        
        for(int i=0;i<4;i++)
        {
            fscanf(f2,"%d %s %d", &lc_symtbl, symtbl, &ra);
            // printf("GOT :%d %s %d op: %s\n" ,lc_symtbl, symtbl, ra , op);
            if((strcmp(op,symtbl)==0) || (strcmp(temp , symtbl) == 0))
            {
                if(check)
                {
                    printf("%s ",m1);  
                    check=0;
                }
                if(ra)
                {
                    offset=lc_symtbl-br_value;
                    printf("%d(%d,%s)",offset,br_value,br);   
                }
                else
                    printf("%d ", lc_symtbl);
            }
        }
        check=1;
        fseek(f2,0,SEEK_SET);
        printf("\n");
        fscanf(f1,"%s %s %s %s",lb,m1,temp,op);
    }
}
