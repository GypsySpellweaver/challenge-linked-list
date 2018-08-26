# Create a singly-linked list from scratch in C without having memory leaks

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

Of course, I've never use `valgrind` either, so that will have to be installed, and learned, after I "think" I have the solution in hand. Testing for memory leaks with `valgrind` beforehand might considered cheating in this case, so I'll withhold its installation and use until I have my "final answer, Alex."

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
    Copyright (C) 2015 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions. There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

---

## License and copyright

This software is available under the [MIT][m] [License][l].

Copyright ©2018 Gypsy Spellwaver


  [a]: https://cseducators.stackexchange.com/a/5007/104
  [l]: https://en.wikipedia.org/wiki/MIT_License
  [m]: https://opensource.org/licenses/MIT
  [q]: https://cseducators.stackexchange.com/q/5003/104
  [u]: https://cseducators.stackexchange.com/users/21/ncmathsadist