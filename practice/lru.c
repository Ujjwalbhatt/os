#include<stdio.h>
int main(){
    int p[50],q[50],n,f,avail,ct[50],b[50],c=0,k=0,t;
    printf("Enter the value of pagese: ");
    scanf("%d",&n);
    printf("Enter the string pages: ");
    for (int i = 0; i< n; i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter the number of frames");
    scanf("%d",&f);
    q[k] = p[k];
    printf("%d\n",q[k]);
    c++;
    k++;
    for (int i = 1; i < n; i++)
    {
        avail = 0;
          for (int k = 0; k < f; k++)
          {
            if(p[i]==q[k]){
                avail = 1;
            }
          }
          if(avail==0){
            c++;
            if(k<f){
                q[k] = p[i];
                k++;
                for (int r = 0; r < k; r++)
                {
                    printf("%d ",q[r]);
                }
                printf("\n");
            }
            else{
                for (int r = 0; r < f; r++)
                {
                    ct[r] = 0;
                    for(int j=i-1;j<n;j--){
                        if(p[j]!=q[r]){
                            ct[r]++;
                        }
                        else{
                            break;
                        }
                    }
                }
                for (int r = 0; r < f; r++)
                {
                    b[r]=ct[r];
                }
                for (int r = 0; r < f; r++)
                {
                    for (int j = r; j < f; j++)
                    {
                        if(b[r]<b[j]){
                            t = b[r];
                            b[r] = b[j];
                            b[j]=t;
                        }
                    }
                    
                }
                for (int r = 0; r < f; r++)
                {
                    if(b[0]==ct[r]){
                        q[r] = p[i];
                    }
                    printf("%d ",q[r]);
                }
                printf("\n");      
            }
          }
             
        }
       printf("No. of page fault: %d",c); 
        
    }
    
    
