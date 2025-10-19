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
#include "wav.h"

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("mcdpcm [input] [output]\n\n"
               "    [input]  - Input file (Must be 8-bit mono WAV format)\n"
               "    [output] - Output file\n");
        return -1;
    }

	return ConvertWavFile(argv[1], argv[2]) - 1;
}