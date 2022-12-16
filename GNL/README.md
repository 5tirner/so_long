# GNL

-----> GET_NEXT_LINE <-----

We want to extract only one line at a time from FD,
but we are not allowed to read the file in one go.

Here we are dealing with reading with BUFFER_SIZE.

This will be a good excursion to get a deep 
knowledge of memory allocation and also a starting 
point for learning about static variables
as well as using the read function.

My project includes three steps:

1 - Put what has been collected by BUFFER_SIZE
    into a stock. 

2 - Extract the line ending in "n/" or "0/" 
    and put it into an array such that the array 
    is the return value of the GNL function. 

3 - Keep what is not taken out by the function 
    so that you can get it back in case 
    something is still there.
