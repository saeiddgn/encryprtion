#include <stdio.h>
#include <string.h>

#define CIRC_BUF_SIZE 20

//
// The circular buffer structure.
//

struct circBuf
{
    char buf[CIRC_BUF_SIZE];  // Data is stored here.
    int  head;                // The in-use data ends before this index.
    int  tail;                // The in-use data starts at this index.
};


//
// Copy characters out of a circular buffer. Removes the characters
// from the buffer after they're copied out.
//
// PARAMETERS:
//   char *to           - where to copy the characters to.
//   struct circBuf *cb - the circular buffer.
//   int len            - how many characters to copy out.
//

void circBufCopyOut(char* to, struct circBuf* cb, int len)
{
    if (cb->tail < cb->head)
    {
        for (int i = 0; i < len; i++) 
        {
        to[i] = cb->buf[cb->tail +i];
        }
    }else if (cb->tail > cb->head)
    {
        for (int i = 0; i < len; i++)
        {
            if (cb->tail + i > CIRC_BUF_SIZE-1)
            {
            to[i] = cb->buf[cb->tail + i-CIRC_BUF_SIZE];
            }
            else
            {
                to[i] = cb->buf[cb->tail + i];
            }
        }
    }else
    {
        //to=0;
    }
}


#ifndef RunTests
int main()
{
    struct circBuf cbuf;
    char result[CIRC_BUF_SIZE];

    // As an example, initialise the circular buffer with "fghij".
    memcpy(cbuf.buf, "abcdefghijklmnopqrst", CIRC_BUF_SIZE);
    cbuf.tail = 18;  // The in-use data starts at the character 5: 'f'.
    cbuf.head = 2; // The in-use data ends before character 10: 'k'.

    // Copy some characters out of the circular buffer.
    memset(result, 0, sizeof(result));
    circBufCopyOut(result, &cbuf, 5);  // Copy 3 characters out.

    printf("Copied: %s\n", result);

    return 0;
}
#endif