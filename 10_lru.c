#include <stdio.h>
int main()
{
    int q[20], p[50], c = 0, avail, f, k = 0, n, t, b[20], c2[20];
    printf("Enter no of pages:");
    scanf("%d", &n);
    printf("Enter the reference string:");
    for (int i = 0; i < n; i++)
    scanf("%d", &p[i]);
    printf("Enter no of frames:");
    scanf("%d", &f);
    q[k] = p[k];              // no page fault for first page
    printf("\n\t%d\n", q[k]); // print first page
    c++;
    k++;
    for (int i = 1; i < n; i++)
    {
        avail = 0;
        for (int j = 0; j < f; j++) // check if page already exists
        {
            if (p[i] == q[j]) // if not exists
                avail = 1;         // increment c1
        }
        if ( avail == 0) // if page not found
        {
            c++; // increment page fault
            if (k < f)
            {
                q[k] = p[i]; // add page to queue
                k++;     // increment queue size
                for (int j = 0; j < k; j++) // print the queue
                    printf("\t%d", q[j]);
                printf("\n");
            }
            else // if all frames are full
            {
                for (int r = 0; r < f; r++) // check for page to be replaced
                {
                    c2[r] = 0;       // initialize c2
                    for (int j = i - 1; j < n; j--) // check for page to be replaced
                    {
                        if (q[r] != p[j]) // if not found
                            c2[r]++;     // increment c2
                        else
                            break;
                    }
                }   
                for (int r = 0; r < f; r++) // check for page to be replaced
                    b[r] = c2[r];
                for (int r = 0; r < f; r++)  
                {
                    for (int j = r; j < f; j++) // sort the pages to be replaced
                    {
                        if (b[r] < b[j]) 
                        {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }
                for (int r = 0; r < f; r++) 
                {
                    if (c2[r] == b[0])
                        q[r] = p[i];
                    printf("\t%d", q[r]);
                }
                printf("\n");
            }
        }
    }
    printf("\nThe no of page faults is %d", c);
}