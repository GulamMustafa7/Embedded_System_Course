#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

	return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

	return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

	return e_failure;
    }

    // No failure return e_success
    return e_success;
}
/*#############################################################################################*/

/* Function Definitions */

/* Read and validate command line argument
 * Input: Command line Argument count and Arguments wtih File name info
 * Output: File names stored in encoded Info
 * Return: e_success or e_failure
 */
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    if (strcmp((strstr(argv[2], ".")) , ".bmp") == 0)
    {
	encInfo -> src_image_fname = argv[2];
    }
    else
    {
	return e_failure;
    }

    if (strcmp((strstr(argv[3], ".")) , ".txt") == 0)
    {
	encInfo -> secret_fname = argv[3];
    }
    else
    {
	return e_failure;
    }

    if (argv[4] != NULL)
    {
	encInfo -> stego_image_fname = argv[4];
    }
    else
    {
	encInfo -> stego_image_fname = "stego.bmp";
    }
    return e_success;
}

/* Encoding the secret file data to stego image
 * Input: FILE info of image, secret file and stego image
 * Output: Encodes the data in secret to stego image
 * Return: e_success or e_failure;
 */
Status do_encoding(EncodeInfo *encInfo)
{
    printf("Started Encoding\n");
    // Open required files
    if (open_files(encInfo) == e_success)
    {
	printf("Open file is successful\n");
	if (check_capacity(encInfo) == e_success)
	{
	    printf("Check capacity is successful\n");

	    //Copying Image Header
	    if (copy_bmp_header(encInfo -> fptr_src_image, encInfo -> fptr_stego_image) == e_success)
	    {
		printf("Copied bmp header is successful\n");

		// Encode magic string in destination image
		if (encode_magic_string(MAGIC_STRING, encInfo) == e_success)
		{
		    printf("Encoded Magic String is successful\n");

		    // Encoding secret.txt file extenstion size
		    if (encode_size(strlen(strstr(encInfo -> secret_fname, ".")), encInfo -> fptr_src_image, encInfo -> fptr_stego_image) == e_success)
		    {
			printf("Encoded secret file extension size is successful\n");

			//Encode the secret file extension
			if (encode_secret_file_extn(strstr(encInfo -> secret_fname, "."), encInfo) == e_success)
			{
			    printf("Encoded secret file extension is successful\n");

			    //Encode the secret file size
			    if (encode_secret_file_size(encInfo -> size_secret_file, encInfo) == e_success)
			    {
				printf("Encoded secret file size is successful\n");

				//Encode secret file data
				if (encode_secret_file_data(encInfo) == e_success)
				{
				    printf("Encoded secret file data is successful\n");

				    //Copy the remaining data
				    if (copy_remaining_img_data(encInfo -> fptr_src_image, encInfo -> fptr_stego_image) == e_success)
				    {
					printf("Copied the remaining bytes is successful\n");
				    }
				    else
				    {
					printf("Copied the remaining bytes is failed\n");
					return e_failure;
				    }
				}
				else
				{
				    printf("Encoded secret file data is failed\n");
				    return e_failure;
				}
			    }
			    else
			    {
				printf("Encoded secret file size is failed\n");
				return e_failure;
			    }
			}
			else
			{
			    printf("Encoded secret file extension is failed\n");
			    return e_failure;
			}
		    }
		    else
		    {
			printf("Encoded secret file extension size is failed\n");
			return e_failure;
		    }
		}
		else
		{
		    printf("ENCODED Magic String is failed\n");
		}
	    }
	    else
	    {
		printf("Copied bmp header is failed\n");
		return e_failure;
	    }
	}
	else
	{
	    printf("Check capacity is failed\n");
	}
    }
    else
    {
	printf("Open file is failed\n");
	return e_failure;
    }
    return e_success;
}

/* To check the capacity of source image to handle secret data
 * Input: File info source image, stego image and secret file
 * Output: Get Source image capacity and store in image_capacity
 * Return: e_success or e_failure
 */
Status check_capacity(EncodeInfo *encInfo)
{
    encInfo -> image_capacity = get_image_size_for_bmp(encInfo -> fptr_src_image);
    encInfo -> size_secret_file = get_file_size(encInfo -> fptr_secret);
    if (encInfo -> image_capacity > (54 + (2 + 4 + 4 + 4 + encInfo -> size_secret_file) * 8))
    {
	return e_success;
    }
    else	
    {
	return e_failure;
    }	
}

/* Get the file size
 * Input:  File pointer
 * Return: Size of file in bytes
 */
uint get_file_size(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);
    return ftell(fptr);
}

/* Copy the header bytes data to stego image
 * Input: FILE pointers source and stego image
 * Output: Copies header data of source image to stego image
 * Return: e_success
 */
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    char str[54];
    fseek(fptr_src_image, 0, SEEK_SET);
    fread(str, 54, 1, fptr_src_image);
    fwrite(str, 54, 1, fptr_dest_image);
    return e_success;
}

/* Encode Magic string in stego image
 * Input: magic string and FILEs info
 * Output: Encode magic character '#*' in stego image first 8 bytes from image data
 * Return: e_success
 */
Status encode_magic_string(char *magic_string, EncodeInfo *encInfo)
{
    encode_data_to_image(magic_string, strlen(magic_string), encInfo -> fptr_src_image,encInfo -> fptr_stego_image, encInfo);
    return e_success;
}

/* Encode secret data to image data
 * Input: Secret data, secret data size, File pointer of source and stego image files
 * Output: Gets source image data and encodes it with secret data by calling another function
 * Return: e_success
 */
Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image, EncodeInfo *encInfo)
{
    int i;
    for(i = 0; i < size; i++)
    {
	fread(encInfo -> image_data, 8, 1, fptr_src_image);
	encode_byte_to_lsb(data[i], encInfo -> image_data);
	fwrite(encInfo -> image_data, 8, 1, fptr_stego_image);
    }
    return e_success;
}

/* Encodes secret byte data to image 8 byte data
 * Input: Secret 1 byte data and Image 8 byte data
 * Output: Encode data to image_buffer
 */
Status encode_byte_to_lsb(char data, char *image_buffer)
{
    int i;
    unsigned int mask = 1 << 7;
    for(i = 0; i < 8; i++)
    {
	image_buffer[i] = ((image_buffer[i] & 0xfe) | (data & mask) >> (7 - i));
	mask = mask >> 1;
    }
}

/* Encode the secret file extenstion size to stego image
 * Input: FILEs info
 * Output: Encode file extenstion size to stego image
 * Return: e_success
 */
Status encode_size(int size, FILE *fptr_src_image, FILE *fptr_stego_image)
{
    char str[32];
    fread(str, 32, 1, fptr_src_image);
    encode_size_to_lsb(str, size);
    fwrite(str, 32, 1, fptr_stego_image);
    return e_success;
}

//Encode file extension size to lsb
Status encode_size_to_lsb(char *buffer, int size)
{
    int i;
    unsigned int mask = 1 << 31;
    for(i = 0; i < 32; i++)
    {
	buffer[i] = ((buffer[i] & 0xfe) | (size & mask) >> (31 - i));
	mask = mask >> 1;
    }
}

/* Encode file extenstion to stego image
 * Input: Files info
 * Output: Copy source image data to stego image with encoded file extenstion
 * Return: e_success
 */
Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo)
{
    encode_data_to_image(file_extn, strlen(file_extn), encInfo -> fptr_src_image, encInfo -> fptr_stego_image, encInfo);
    return e_success;
}

/* Encode secret file size data to stego image
 * Input: Files info
 * Output: Encode secret file size data to stego image
 * Return: e_success
 */
Status encode_secret_file_size(int file_size, EncodeInfo *encInfo)
{
    char str[32];
    fread(str, 32, 1, encInfo -> fptr_src_image);
    encode_size_to_lsb(str, file_size);
    fwrite(str, 32, 1, encInfo -> fptr_stego_image);
    return e_success;
}

/* Encode secret file data to stego image file
 * Input: Files info
 * Output: Encodes secret data to stego image
 * Return: e_success
 */
Status encode_secret_file_data(EncodeInfo *encInfo)
{
    char str[encInfo -> size_secret_file];
    fseek(encInfo -> fptr_secret, 0, SEEK_SET);
    fread(str, encInfo -> size_secret_file, 1, encInfo -> fptr_secret);
    encode_data_to_image(str, encInfo -> size_secret_file, encInfo -> fptr_src_image, encInfo -> fptr_stego_image, encInfo);
    return e_success;
}

/* Copy remaining source image data to stego image
 * Input: File pointer of source and stego image
 * Output: Remaining image data copied from source image
 * Return: e_success 
 */
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    char ch;
    while (fread(&ch, 1, 1, fptr_src) > 0)
    {
	fwrite(&ch, 1, 1, fptr_dest);
    }
    return e_success;
}
