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

#include "helpers.h"

/*
 * Read short from file
 * 
 * ARGUMENTS:
 *     fp - File handle
 * RETURNS:
 *     Read value
 */
short ReadShort(FILE* fp)
{
	unsigned char buffer[2] = { 0, 0 };
	size_t read = 0;

	assert(fp);
	read = fread(buffer, 1, 2, fp);

	if (read == 0) {
		return 0;
	}
	return (buffer[0]) | (buffer[1] << 8);
}

/*
 * Read long from file
 *
 * ARGUMENTS:
 *     fp - File handle
 * RETURNS:
 *     Read value
 */
long ReadLong(FILE* fp)
{
	unsigned char buffer[4] = { 0, 0, 0, 0 };
	size_t read = 0;

	assert(fp);
	read = fread(buffer, 1, 4, fp);

	if (read == 0) {
		return 0;
	}
	return (buffer[0]) | (buffer[1] << 8) | (buffer[2] << 16) | (buffer[3] << 24);
}

/*
 * Convert sample
 *
 * ARGUMENTS:
 *     sample - Sample to convert
 * RETURNS:
 *     Converted sample
 */
unsigned char ConvertSample(unsigned char sample)
{
	if (sample >= 0x80) {
		return 0x80 | ((sample & 0x7F) * 0x7E) / 0x7F;
	}
	return (((0x7F - sample) * 0x7E) / 0x7F) + 1;
}