/*
    Copyright (c) 2025 Devon Artmeier

    Permission to use, copy, modify, and /or distribute this software
    for any purpose with or without fee is hereby granted.

    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
    WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIE
    WARRANTIES OF MERCHANTABILITY AND FITNESS.IN NO EVENT SHALL THE
    AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
    DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
    PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
    TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
    PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef MCDPCM_HELPERS_H
#define MCDPCM_HELPERS_H

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*
 * Read short from file
 * 
 * ARGUMENTS:
 *     fp - File handle
 * RETURNS:
 *     Read value
 */
short ReadShort(FILE* fp);

/*
 * Read long from file
 *
 * ARGUMENTS:
 *     fp - File handle
 * RETURNS:
 *     Read value
 */
long ReadLong(FILE* fp);

/*
 * Convert sample
 *
 * ARGUMENTS:
 *     sample - Sample to convert
 * RETURNS:
 *     Converted sample
 */
unsigned char ConvertSample(unsigned char sample);

#endif /* MCDPCM_HELPERS_H */