runs 100 cases of 100 random inserts then 100 random deletes with your BTree and compares
it to Sean's

numbers between 0-99 and M and L between 3 and 10

HOW TO RUN:
You need to have your BTree executable named BTree and have Sean's BTree
executable named SeanBTree (i provided his but it might not work for you)

do ./selftest.sh in the command line
if it prints nothing, great, you pass and maybe run a couple more times
(do ./resettest before running again)
to change the number of cases run in one command change the 100 in line 3 of
selftest.sh

if it gives you an error to do with testgenerator then recompile it with

g++ -o testgenerator testgenerator.cpp

otherwise, if you get a bunch of output, then look at the first lines of
finalresult.txt. this will tell you the first result that was different in
results.txt. in results.txt you will see which test number it was, then
you go to inputs.txt and you will have access to the inputs that caused your
btree to have a different output than his. if 100 is too many inputs for you
then you can change the 100 in line 17 of testgenerator.cpp and recompile with
the command above.
