#include <stdio.h>
#include "decode.h"
#include "types.h"
#include <string.h>
#include "common.h"
#include <stdlib.h>

/* Function Definiation */

// Function definition for do decoding
d_Status do_decoding(DecodeInfo *decInfo)
{
    if (open_files_dec(decInfo) == d_success)
    {
	printf("Open files is a successfully\n");

	//Decode magic string
	if (decode_magic_string(decInfo) == d_success)
	{
	    printf("Decoded magic string Successfully\n");

	    //Decode secret file extension size
	    if (decode_file_extn_size(strlen(".txt"), decInfo->fptr_d_src_image) == d_success)
	    {
		printf("Decoded file extension size Succesfully\n");

		//Decode secret file extension(.txt in our case) 
		if (decode_secret_file_extn(decInfo->d_extn_secret_file, decInfo) == d_success)
		{
		    printf("Decoded Secret File Extension Succesfully\n");

		    //Decode secret file size
		    if (decode_secret_file_size(decInfo->size_secret_file, decInfo) == d_success)
		    {
			printf("Decoded secret file size Successfully\n");

			//Decode secret file data
			if (decode_secret_file_data(decInfo) == d_success)
			{
			    printf("Decoded secret file data Succuessfully\n");
			}
			else
			{
			    printf("Decoding of secret file data is a failure\n");
			}
		    }
		    else
		    {
			printf("Decode of secret file size is a failure\n");
			return d_failure;
		    }
		}
		else
		{
		    printf("Decode of Secret file extension is a failure\n");
		    return d_failure;
		}
	    }
	    else
	    {
		printf("Decoded of file extension size is a failure\n");
		return d_failure;
	    }
	}
	else
	{
	    printf("Decoding of magic string is a failure\n");
	    return d_failure;
	}
    }
    else
    {
	printf("Open files is a failure\n");
	return d_failure;
    }
    return d_success;
}

/* Get File names and validate
 * Input: Stego Image file name and Output file name
 * Output: Stores the above files names
 * Return Value: e-success or e_failure, on file errors
 */
d_Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    if (strcmp(strstr(argv[2], "."), ".bmp") == 0)
    {
	decInfo->d_src_image_fname = argv[2];
    }
    else
    {
	return d_failure;
    }

    if (argv[3] != NULL)
    {
	decInfo->d_secret_fname = argv[3];
    }
    else
    {
	decInfo->d_secret_fname = "decode.txt";
    }
    return d_success;
}

/* Get File pointers for i/p and o/p files
 * Inputs: Stego Image file, Output file
 * Ouput: File pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
d_Status open_files_dec(DecodeInfo *decInfo)
{
    // Stego Image file
    decInfo->fptr_d_src_image = fopen(decInfo->d_src_image_fname, "r");
    // Do Error handling
    if (decInfo->fptr_d_src_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->d_src_image_fname);
	return d_failure;
    }

    // Dest file
    decInfo->fptr_d_secret = fopen(decInfo->d_secret_fname, "w");
    // Do Error handling
    if (decInfo->fptr_d_secret == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->d_secret_fname);
	return d_failure;
    }
    // If no failure then return d_success
    return d_success;
}

/* Decodes the magic string from stego image
 * Input: Magic string and File info of input and output
 * Output: Proceed decoing if magic string if found or else stop decoding
 * Return: e_success or e_failure
 */
d_Status decode_magic_string(DecodeInfo *decInfo)
{
    fseek(decInfo->fptr_d_src_image, 54, SEEK_SET);
    int i = strlen(MAGIC_STRING);
    decInfo->magic_data = malloc(strlen(MAGIC_STRING) + 1);
    decode_data_from_image(strlen(MAGIC_STRING), decInfo->fptr_d_src_image, decInfo);
    decInfo->magic_data[i] = '\0';

    if (strcmp(decInfo->magic_data, MAGIC_STRING) == 0)
	return d_success;
    else
	return d_failure;
}

// Function definition for decoding data fom image
d_Status decode_data_from_image(int size, FILE *fptr_d_src_image, DecodeInfo *decInfo)
{
    int i;
    char str[8];
    for (i = 0; i < size; i++)
    {
	fread(str, 8, sizeof(char), fptr_d_src_image);
	decode_byte_from_lsb(&decInfo->magic_data[i], str);
    }
    return d_success;
}

// Function definition for decode byte from lsb
d_Status decode_byte_from_lsb(char *data, char *image_buffer)
{
    int bit = 7;
    unsigned char ch = 0x00;
    for (int i = 0; i < 8; i++)
    {
	ch = ((image_buffer[i] & 0x01) << bit--) | ch;
    }
    *data = ch;
    return d_success;
}

/* Decode file extenstion size from stego image
 * Input: File info of stego image and output file
 * Output: Decode the extenstion size from stego image and store in image_data_size
 * Return: e_success or e_failure
 */
d_Status decode_file_extn_size(int size, FILE *fptr_d_src_image)
{
    char str[32];
    int length;
    fread(str, 32, sizeof(char), fptr_d_src_image);
    decode_size_from_lsb(str, &length);

    if (length == size)
	return d_success;
    else
	return d_failure;
}

// Function definition decode size from lsb
d_Status decode_size_from_lsb(char *buffer, int *size)
{
    int j = 31;
    int num = 0x00;
    for (int i = 0; i < 32; i++)
    {
	num = ((buffer[i] & 0x01) << j--) | num;
    }
    *size = num;
}

/* Decode file extenstion from stego image 
 * Input: Extenstion Size and File info of stego image
 * Output: Decodes the file extenstion and store in extn_output_file
 * Return: e_success or e_failure
 */
d_Status decode_secret_file_extn(char *file_ext, DecodeInfo *decInfo)
{
    file_ext = ".txt";
    int i = strlen(file_ext);
    decInfo->d_extn_secret_file = malloc(i + 1);

    decode_extension_data_from_image(strlen(file_ext), decInfo->fptr_d_src_image, decInfo);
    decInfo->d_extn_secret_file[i] = '\0';

    if (strcmp(decInfo->d_extn_secret_file, file_ext) == 0)
	return d_success;
    else
	return d_failure;
}

// Function definition decode extension data from image
d_Status decode_extension_data_from_image(int size, FILE *fptr_d_src_image, DecodeInfo *decInfo)
{
    for (int i = 0; i < size; i++)
    {
	fread(decInfo->d_src_image_fname, 8, 1, fptr_d_src_image);
	decode_byte_from_lsb(&decInfo->d_extn_secret_file[i], decInfo->d_src_image_fname);
    }
    return d_success;
}

/* Decode secret file size from stego image
 * Input: FILE info of stego image and output file
 * Output: Decodes the file image and store in image_data_size
 * Return: e_success or e_failure
 */
d_Status decode_secret_file_size(int file_size, DecodeInfo *decInfo)
{
    char str[32];
    fread(str, 32, sizeof(char), decInfo->fptr_d_src_image);
    decode_size_from_lsb(str, &file_size);
    decInfo->size_secret_file = file_size;
    return d_success;
}

/* Decode file data from stego image
 * Input: FILE info of stego image and output decode file
 * Output: Write decode data in the output file
 * Return: e_success or e_failure
 */
d_Status decode_secret_file_data(DecodeInfo *decInfo)
{
    char ch;
    for (int i = 0; i < decInfo->size_secret_file; i++)
    {
	fread(decInfo->d_src_image_fname, 8, sizeof(char), decInfo->fptr_d_src_image);
	decode_byte_from_lsb(&ch, decInfo->d_src_image_fname);
	fputc(ch, decInfo->fptr_d_secret);
    }
    return d_success;
}
