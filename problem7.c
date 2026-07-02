#include <stdio.h>
#include <stdbool.h>

/* FIFO Page replacement algorithm 
 * OS keeps track of all pages in the memory in a queue.
 * Oldest page is in the front of the queue.
 * When a new page needs to be replaced -> the page in the front of the queue
 * is selected for removal.
 */

 /* Pros and Cons
  * Pros:
  *     - Easy to implement
  *     - Fairness: All pages have an equal chance.
  *     - Low overhead: Doesn't need to track page access history or usage frequency
  *     - Required minimal memory and processing
  * Cons:
  *     - Higher page fault rate
  *     - It may replace frequently used pages.
  * 
  * */
#define MAX_FRAMES  4 

int frames[MAX_FRAMES];
int front = 0; // Points to the front of the queue
int page_faults = 0;

void insertPage(int page)
{
    frames[front] = page;
    front = (front + 1) % MAX_FRAMES;
    page_faults++;
}

int main()
{
    printf("Hello World\n");
    int page_reference[] = {1,2,3,4,2,1,5};
    int num_pages = sizeof(page_reference) / sizeof(page_reference[0]);
    printf("num_page: %d\n", num_pages);
    for(int i = 0; i < num_pages; i++)
    {
        int page = page_reference[i];
        printf("page: %d\n", page);
        
        // Check if the page is already in the frames
        bool found = false;
        for(int j = 0; j < MAX_FRAMES; j++)
        {
            printf("frames[j]: %d\n",frames[j]);
            if(frames[j] == page)
            {
                printf("alo\n");
                found = true;
                break;
            }
        }
        if (!found)
        {
            printf("insertPage\n");
            insertPage(page);
        }
    }
    
    printf("----Frame status----\n");
    printf("Page\n");
    for(int i = 0; i < MAX_FRAMES; i++)
    {
        if(frames[i] >= 0)
        {
            printf("%d\n", frames[i]);
        }
        else
        {
            printf("\t\n");
        }
    }
    
    printf("Number of page faults (FIFO): %d\n", page_faults);
    
    return 0;
}