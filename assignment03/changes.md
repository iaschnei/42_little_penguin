Here is a summary of the changes I made : 

All functions are now static since they are never called elsewhere. (I'm not actually sure this is
a kernel coding style good practice)

After `static int do_work(int *my_int)` the '{' goes to the next line (as with all functions).
The useless variable `retval` has also been removed.

The for loop contains a single line and doesn't need to be surrounded by braces.

The `if (y > 10)` has changed : the comparison sign went from < to > because it wouldn't make sense
to say "We slept a long time" if we slept under 10 times...
I also removed the useless comment since the code is self-explanatory.
Since the new block only contains one line it doesn't need braces either.

The useless and unreachable `return 1;` has been removed.

For the `my_init` function i added the keyword "__init"
Same thing with `my_exit` with "__exit"

