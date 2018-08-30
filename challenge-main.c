/*
 * MIT License
 *
 * Copyright ©2018 Ronald Lamoreaux
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "help-int.c"
#include "help-float.c"
#include "single-link-list.c"
#include "single-link-list-sort.c"

/*
 * the test packages
 */
#include "_sanity.c"
#include "_empty.c"
#include "_with-one.c"
#include "_given-numbers.c"
#include "_random-numbers.c"
#include "_remote.c"


int main() {
    srand(time(NULL));
    sanityChecksInt();
    sanityChecksFloat();
    workOutWithEmptyList();
    workOutWithListOfOne();
    workOutWithGivenNumbers();
    workOutWithRandomNumbers(11100);
    LLNode* random_head_ptr = newListNode(NULL);
    workOutWithRandomNumbersRemotely(12345, random_head_ptr);
    workOutWithRandomNumbersRemotelyFinal(random_head_ptr);
    free(random_head_ptr);
    return 0;
}
