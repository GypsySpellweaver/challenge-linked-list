# Valgrind results

Setting the count of random numbers at 75k (76,800), compiling and running through Valgrind gave no memory leaks, or other errors. At a time of about 1 minute, I grew encouraged and increased the count to 150k (153,600) and repeated the process. Even that was only a shave above 4 minutes. Running the same, without Valgrind was about a minute and a half, so Valgrind's warning of taking more time is valid. The output of the sorting was redirected to a file in all three cases, so any I/O timing would be reasonably constant between runs. Below is the screen dump for the three runs. The first run's output, [challenge-main.log][l], is included in the repo. The others wouldn't be of any value and would amount to wasted space. (The first one might as well, but including one did seem appropriate.)


    gypsy@SuSE:/home/projects/challenge-linked-list> gcc -Wall -g challenge-main.c -o challenge-main && time valgrind --leak-check=full --show-leak-kinds=all ./challenge-main > challenge-main.log
    ==8738== Memcheck, a memory error detector
    ==8738== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==8738== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==8738== Command: ./challenge-main
    ==8738==
    ==8738==
    ==8738== HEAP SUMMARY:
    ==8738==     in use at exit: 0 bytes in 0 blocks
    ==8738==   total heap usage: 307,199 allocs, 307,199 frees, 3,993,584 bytes allocated
    ==8738==
    ==8738== All heap blocks were freed -- no leaks are possible
    ==8738==
    ==8738== For counts of detected and suppressed errors, rerun with: -v
    ==8738== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

    real    0m58.359s
    user    0m58.157s
    sys     0m0.176s
    gypsy@SuSE:/home/projects/challenge-linked-list> vi challenge-main.c
    gypsy@SuSE:/home/projects/challenge-linked-list> gcc -Wall -g challenge-main.c -o challenge-main && time valgrind --leak-check=full --show-leak-kinds=all ./challenge-main > challenge-main-2.log
    ==9120== Memcheck, a memory error detector
    ==9120== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==9120== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==9120== Command: ./challenge-main
    ==9120==
    ==9120==
    ==9120== HEAP SUMMARY:
    ==9120==     in use at exit: 0 bytes in 0 blocks
    ==9120==   total heap usage: 614,399 allocs, 614,399 frees, 7,987,184 bytes allocated
    ==9120==
    ==9120== All heap blocks were freed -- no leaks are possible
    ==9120==
    ==9120== For counts of detected and suppressed errors, rerun with: -v
    ==9120== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

    real    4m4.994s
    user    4m4.083s
    sys     0m0.684s
    gypsy@SuSE:/home/projects/challenge-linked-list> time ./challenge-main > challenge-main-3.log

    real    1m39.919s
    user    1m39.844s
    sys     0m0.021s

As an additional curiosity I decided to again double the number of nodes and run it again (without Valgrind). Running with 300k (307,200) list items still only took around 9 minutes. Much better than I'd have expected for my system.

Then, as one final "why not" I ran all the test through Valgrind as well. Just to see if my reading of them caught the memory errors, even though I wasn't "looking" for them specifically.

    gypsy@SuSE:/home/projects/challenge-linked-list> for trial in sanity empty with-one given-numbers random-numbers; do gcc -Wall -g test_$trial.c -o test_$trial; valgrind --leak-check=full --show-leak-kinds=all ./test_$trial > /dev/null; rm -f test_$trial; done
    ==29627== Memcheck, a memory error detector
    ==29627== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==29627== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==29627== Command: ./test_sanity
    ==29627==
    ==29627==
    ==29627== HEAP SUMMARY:
    ==29627==     in use at exit: 0 bytes in 0 blocks
    ==29627==   total heap usage: 2 allocs, 2 frees, 32 bytes allocated
    ==29627==
    ==29627== All heap blocks were freed -- no leaks are possible
    ==29627==
    ==29627== For counts of detected and suppressed errors, rerun with: -v
    ==29627== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    ==29634== Memcheck, a memory error detector
    ==29634== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==29634== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==29634== Command: ./test_empty
    ==29634==
    ==29634==
    ==29634== HEAP SUMMARY:
    ==29634==     in use at exit: 0 bytes in 0 blocks
    ==29634==   total heap usage: 25 allocs, 25 frees, 400 bytes allocated
    ==29634==
    ==29634== All heap blocks were freed -- no leaks are possible
    ==29634==
    ==29634== For counts of detected and suppressed errors, rerun with: -v
    ==29634== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    ==29641== Memcheck, a memory error detector
    ==29641== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==29641== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==29641== Command: ./test_with-one
    ==29641==
    ==29641==
    ==29641== HEAP SUMMARY:
    ==29641==     in use at exit: 0 bytes in 0 blocks
    ==29641==   total heap usage: 49 allocs, 49 frees, 784 bytes allocated
    ==29641==
    ==29641== All heap blocks were freed -- no leaks are possible
    ==29641==
    ==29641== For counts of detected and suppressed errors, rerun with: -v
    ==29641== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    ==29648== Memcheck, a memory error detector
    ==29648== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==29648== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==29648== Command: ./test_given-numbers
    ==29648==
    ==29648==
    ==29648== HEAP SUMMARY:
    ==29648==     in use at exit: 0 bytes in 0 blocks
    ==29648==   total heap usage: 39 allocs, 39 frees, 384 bytes allocated
    ==29648==
    ==29648== All heap blocks were freed -- no leaks are possible
    ==29648==
    ==29648== For counts of detected and suppressed errors, rerun with: -v
    ==29648== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    ==29655== Memcheck, a memory error detector
    ==29655== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==29655== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==29655== Command: ./test_random-numbers
    ==29655==
    ==29655==
    ==29655== HEAP SUMMARY:
    ==29655==     in use at exit: 0 bytes in 0 blocks
    ==29655==   total heap usage: 78 allocs, 78 frees, 1,008 bytes allocated
    ==29655==
    ==29655== All heap blocks were freed -- no leaks are possible
    ==29655==
    ==29655== For counts of detected and suppressed errors, rerun with: -v
    ==29655== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


# Final thoughts and summary

## Pointers

### Memory leaks

The pointers, and the potential for memory leaks in C when using them was the whole point of the experiment. I can see that avoiding memory leaks in a complex situation can become a non-trivial task. I also don't believe it is an altogether difficult proposition. My coding experience and expectations lead me to believe that the details, in any programming project, are significant, and that the programmer should be thinking about them as the code is being developed. With that approach, I don't think that avoiding memory leaks in C when using pointers is any more difficult than avoiding identifier name collisions in a large project.

### Complexity

While I'm new to C programming, I'm not new to all programming, so my view isn't that of a new, or aspiring, developer. Nevertheless, the use of pointers, as abstractions, or as indirect references, seems as natural to computer programming as the use of functions and procedures. Functions and procedures are really names for pointers anyway, truth be told. Somehow the word "pointer" got a bad reputation when all the other names we have for the same concept are "normal". Call it a potato, or a _pomme de terre_, it still tastes and looks the same, and has an unimaginable number of ways it can be used - some of which include eating.

## The C programming language

I like it. Okay, I'll admit; it's not _object-oriented_. I have nothing against OO programming in the least. Likewise, I have nothing against procedural programming, or functional programming. I don't prefer compiled over interpreted (or Java which is neither and both). I prefer neither nails, screws, nor Crazy-Glue. I don't think using nails to repair a porcelain tea set is a good idea. Nor is it efficient to use a hammer to fasten sheet-metal with bolts. Sometimes there are several options for getting a task accomplished, and not always is there a clear "best choice." The developer that is competent in more than one language, coding style, framework, or stack, has more tools to choose from, and has a better than average chance of not only having the "right tool for the job" but also knowing why the chosen tool _is_ the right one.

So... I like C. Not sure when it will happen, but I look forward to learning more about C, and becoming competent enough in C to add it to my own set of tools. Since they are closely related, I presume that C++ will get similar attention from me as C will. Perhaps even simultaneously.

## Merge Sort

Using pointers, and recursion, the merge sort becomes almost trivial to implement. At a cost, however. Recusion, even with pointers, is hard on the memeory allocated to the stack. Tail recursion can help with that, of course. Using arrays, even if it's an array of pointers, it's easy to work an interative approach to a merge sort. That's now how I did this one though. Depending on the size of the stack, this program will probably crash sooner than expected. On a GNU/Linux system with a stack space of 8192, I'd predict failure at around 130,000 nodes. Using `ulimit -s 32768` should allow enough room for a rather sizable list.


  [l]: https://raw.githubusercontent.com/GypsySpellweaver/challenge-linked-list/challenge/challenge-main.log

