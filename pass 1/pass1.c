#include <stdio.h>
#include<string.h>
int main()
{
  FILE *f1,*f2,*f3;

  f1=fopen("input.txt","r");
  f2=fopen("symtbl.txt","w");

  char lb[20], m1[20], op[20], opt[20];
  int opS, lc;

  fscanf(f1,"%s %s %d", lb, m1, &opS);
  if(strcmp(m1,"START")==0)
  {
    lc=opS;
    printf("\t%s \t%s \t%d \n",lb, m1, opS);
  }
  else
  {
    lc=0;
  }

  fscanf(f1,"%s %s", lb, m1);
  while(!feof(f1))
  {
    fscanf(f1,"%s", op);
    printf("%d \t%s \t%s \t%s \n", lc, lb, m1, op);
    if(strcmp(lb,"-")!=0)
    {
      if(strcmp(m1,"EQU")==0)
      {
        fprintf(f2,"\n%s\t%s\n",op,lb);
      }
      else
      {
        fprintf(f2,"\n%d\t%s\n",lc,lb);
      }
    }

    f3=fopen("optab.txt","r");     //mot nu lc
    fscanf(f3,"%s",opt);
    while(!feof(f3))
    {
      if(strcmp(m1,opt)==0)
      {
        lc=lc+4;
        break;
      }
      fscanf(f3,"%s",opt);
    }
    fclose(f3);

    if(strcmp(m1,"BALR")==0 || strcmp(m1,"USING")==0 || strcmp(m1,"EQU")==0)  //pot nnu lc
    {
      lc=lc+0;
    }
    else if(strcmp(m1,"DS")==0 || strcmp(m1,"DC")==0)
    {
      lc=lc+4;
    }

    fscanf(f1,"%s %s", lb, m1);
  }
  printf("Total lc value: %d", lc);
  return 0;
}
