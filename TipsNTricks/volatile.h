/*

The statement "the value can be changed by means outside of this code" basically means that another program or hardware can update that variable. This is totally possible. One way of thinking of this is by relating this concept to a file that is shared among multiple programs. A file can be opened, written, and read by many programs at once. When you read from a file you want to make sure that you are reading the latest update and not the oldest.

Going back to the volatile keyword, placing volatile before a variable, in effect, does the same thing. It makes sure that what you are reading out of the variable isn't based on the compiler's optimization or an old copy of the variable that your program had. Moreover, the volatile keyword ensures that the variable is fetched from memory on every access. Therefore, both of those statements are correct regarding the volatile keyword.

*/