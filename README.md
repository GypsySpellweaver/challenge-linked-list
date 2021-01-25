# Create a singly-linked list from scratch in C without having memory leaks

---

## Final results

The trials are done, and the results are in. See the [REPORT_VALGRIND.md][r] file for all the details, and my conclusions.

---

## Background

On the [Computer Science Educators][c] of the [Stack Exchange Network][s] a question was posed: "[Why are pointers a key topic in a CS curriculum and oft cited as something people don't get?][q]". User [ncmathsadist][u] posted an answer indicating the difficulty with pointers in C is the memory management associated with their use rather than their actual usage.

In connection with that answer, and by way of demonstrating the difficulty of memory management, the user issued a challenge, so to speak:

> Try coding a singly-linked list from scratch in C without having memory leaks.

Furthermore, the user made the statement that

> It is an edifying and humility-instilling experience.

The user closed their post with a final warning:

> Warning: valgrind will hurt your feelings.

---

## Explaining the repo's usage pattern

Since I have never written any code in C, including the infamous _Hello World_ program, I thought I would make a good test subject for that challenge.

This repository will likely have an unusually high number of commits, since I intend to document the developement process, and my learning, rather than only committing "working code" as is the normal practice for git repositories.

Of course, I've never use `valgrind` either, so that will have to be installed, and learned, after I "think" I have the solution in hand. Testing for memory leaks with `valgrind` beforehand might be considered cheating in this case, so I'll withhold its installation and use until I have my "final answer, Alex."

---

## System in use for development and testing

### CPU:

AMD FX™-8300 Eight-Core Processor

### Memory:

16,818,520,064 bytes

### `uname -a`:

>     Linux SuSE 4.4.143-65-default #1 SMP Tue Aug 14 09:18:29 UTC 2018 (4e090cc) x86_64 x86_64 x86_64 GNU/Linux`

### `gcc --version`:

>     gcc (SUSE Linux) 4.8.5
>     Copyright (C) 2015 Free Software Foundation, Inc.
>     This is free software; see the source for copying conditions. There is NO
>     warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

### Valgrind Info (Installed 2016-08-31 03:54:04 UTC)

Current version of Valgrind is [Valgrind 3.13.0][d] - 14 June 2017.

Available from [http://valgrind.org/downloads/current.html][v].


Includes a sepecial warning:

>  Programs running under Valgrind run significantly more slowly, and use much more memory -- e.g. more than twice as much as normal under the Memcheck tool. Therefore, it's best to use Valgrind on the most capable machine you can get your hands on.

    $ valgrind --version

yields

    valgrind-3.13.0

Looks like all is well.

    $ valgrind --leak-check=full ls -l

yields

    ==17534==
    ==17534== HEAP SUMMARY:
    ==17534==     in use at exit: 20,507 bytes in 34 blocks
    ==17534==   total heap usage: 633 allocs, 599 frees, 96,021 bytes allocated
    ==17534==
    ==17534== LEAK SUMMARY:
    ==17534==    definitely lost: 0 bytes in 0 blocks
    ==17534==    indirectly lost: 0 bytes in 0 blocks
    ==17534==      possibly lost: 0 bytes in 0 blocks
    ==17534==    still reachable: 20,507 bytes in 34 blocks
    ==17534==         suppressed: 0 bytes in 0 blocks
    ==17534== Reachable blocks (those to which a pointer was found) are not shown.
    ==17534== To see them, rerun with: --leak-check=full --show-leak-kinds=all
    ==17534==
    ==17534== For counts of detected and suppressed errors, rerun with: -v
    ==17534== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

That looks to me like it's a "done deal" for the install of Valgrind.

---

## License and copyright

This software is available under the [MIT][m] [License][l].

Copyright ©2018 Gypsy Spellwaver

### The MIT License

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGE-
    MENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
    FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
    CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


  [a]: https://cseducators.stackexchange.com/a/5007/104
  [c]: https://cseducators.stackexchange.com
  [d]: ftp://sourceware.org/pub/valgrind/valgrind-3.13.0.tar.bz2
  [l]: https://en.wikipedia.org/wiki/MIT_License
  [m]: https://opensource.org/licenses/MIT
  [q]: https://cseducators.stackexchange.com/q/5003/104
  [r]: https://github.com/GypsySpellweaver/challenge-linked-list/blob/challenge/REPORT_VALGRIND.md
  [s]: https://stackexchange.com
  [u]: https://cseducators.stackexchange.com/users/21/ncmathsadist
  [v]: http://valgrind.org/downloads/current.html
