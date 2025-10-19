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

#define BUFFER_SIZE (0x1000)

/*
 * Convert WAV file
 * 
 * ARGUMENTS:
 *     in_filename  - Input filename
 *     out_filename - Output filename
 * RETURNS:
 *     0 if failed, 1 if successful
 */
int ConvertWavFile(const char *in_filename, const char *out_filename)
{
	int success = 0;
	int i = 0;
	
	FILE *in_fp = 0;
	char id[5] = { 0, 0, 0, 0, 0 };
	long chunk_size = 0;
	long chunk_position = 0;
	long data_size = 0;
	long data_position = 0;

	FILE *out_fp = 0;
	unsigned char buffer[BUFFER_SIZE];
	long bytes_left = 0;
	long bytes_read = 0;

	assert(in_filename && out_filename);

	in_fp = fopen(in_filename, "rb");
	if (!in_fp) {
		printf("Error: Could not open \"%s\" for reading.\n", in_filename);
		goto cleanup;
	}

	fread(id, 1, 4, in_fp);
	if (strcmp(id, "RIFF") != 0) {
		printf("Error: \"%s\" is not a valid WAV file.\n", in_filename);
		goto cleanup;
	}
	fseek(in_fp, 4, SEEK_CUR);

	fread(id, 1, 4, in_fp);
	if (strcmp(id, "WAVE") != 0) {
		printf("Error: \"%s\" is not a valid WAV file.\n", in_filename);
		goto cleanup;
	}

	while (1) {
		fread(id, 1, 4, in_fp);
		if (ferror(in_fp)) {
			printf("Error: Failed to read chunk ID from \"%s\".\n", in_filename);
			goto cleanup;
		}
		if (feof(in_fp)) break;

		chunk_size = ReadLong(in_fp);
		chunk_position = ftell(in_fp);

		if (strcmp(id, "fmt ") == 0) {
			if (ReadShort(in_fp) != 1) {
				printf("Error: \"%s\" has an invalid audio format.\n", in_filename);
				goto cleanup;
			}

			if (ReadShort(in_fp) != 1) {
				printf("Error: \"%s\" is not a mono audio file.\n", in_filename);
				goto cleanup;
			}

			fseek(in_fp, 10, SEEK_CUR);
			
			if (ReadShort(in_fp) != 8) {
				printf("Error: \"%s\" is not an 8-bit audio file.\n", in_filename);
				goto cleanup;
			}
		} else if (strcmp(id, "data") == 0) {
			data_size = chunk_size;
			data_position = chunk_position;
		}
		
		fseek(in_fp, chunk_position + chunk_size, SEEK_SET);
	}

	out_fp = fopen(out_filename, "wb");
	if (!out_fp) {
		printf("Error: Could not open \"%s\" for writing.\n", out_filename);
		goto cleanup;
	}

	bytes_left = data_size;
	fseek(in_fp, data_position, SEEK_SET);

	while (bytes_left > 0) {
		bytes_read = fread(buffer, 1, BUFFER_SIZE, in_fp);
		if (ferror(in_fp)) {
			printf("Error: Failed to read from \"%s\".\n", in_filename);
			goto cleanup;
		}

		if (bytes_read > 0) {
			for (i = 0; i < bytes_read; i++) {
				buffer[i] = ConvertSample(buffer[i]);
			}
			fwrite(buffer, 1, bytes_read, out_fp);
			bytes_left -= bytes_read;
		}
		if (feof(in_fp)) break;
	}
	
	success = 1;

cleanup:
	if (in_fp) {
		fclose(in_fp);
	}
	if (out_fp) {
		fclose(out_fp);
	}

	return success;
}