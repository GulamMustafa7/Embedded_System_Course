//#############################################################################################//
/*
Title: Steganography

Description: Programme to encode secret file data to source image file by creating new image file with option '-e' and decode data from new image file to new text file with option '-d'.

Name:   GulamMustafa Ibrahim Kazi.

Date:   27/12/2023

///////////////////////////////////// : For Encoding : //////////////////////////////////////////

Input Files :  For option 'e'
a) Source image file name
b) Secret text file name
c) Output image file name

Sample Execution : ./a.out -e beautiful.bmp secret.txt stego.bmp

Output:	Selected encoding
        Read and validate is successful
        Started Encoding
        Open file is successful
        width = 1024
        height = 768
        Check capacity is successful
        Copied bmp header is successful
        Encoded Magic String is successful
        Encoded secret file extension size is successful
        Encoded secret file extension is successful
        Encoded secret file size is successful
        Encoded secret file data is successful
        Copied the remaining bytes is successful
        Encoding is successful

///////////////////////////////////// : For Decoding : //////////////////////////////////////////

Input Files :  For option 'd'
a) Stego image file name
b) Output text file name

Sample Execution : ./a.out -d stego.bmp

Output:	Selected decoding
        Open files is a successfully
        Decoded magic string Successfully
        Decoded file extension size Succesfully
        Decoded Secret File Extension Succesfully
        Decoded secret file size Successfully
        Decoded secret file data Succuessfully
        Decoding is successful
 */
//#############################################################################################//

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"
#include "common.h"

int main(int argc , char *argv[])
{
    //Check the number of arguments(if only './a.out' is passed)
    if (argc < 2)
    {
	printf("Please pass the files in arguments\nFor Encoding : \n./a.out -e beautiful.bmp secret.txt\nFor Decoding : \n./a.out -d stego.bmp\n");
	return 0;
    }

    //Check operation type(Encode or Decode)
    if (check_operation_type(argv) == e_encode)
    {
	//Check the number of arguments.
	if (argc < 3)
	{
	    printf("Please pass the .bmp & .txt files\nUsage for Encoding : \n./a.out -e beautiful.bmp secret.txt\n");
	    return 0;
	}

	printf("Selected encoding\n");

	// Declare structure variable
	EncodeInfo encInfo;
	// Read and validate encode arguments
	if (read_and_validate_encode_args(argv , &encInfo) == e_success)
	{
	    printf("Read and validate is successful\n");
	    if (do_encoding(&encInfo) == e_success)
	    {
		printf("Encoding is successful\n");
	    }
	    else
	    {
		printf("Encoding is failed\n");
		return e_failure;
	    }
	}
	else
	{
	    printf("Read and validate is Failed\nPlease pass ./a.out -e beautiful.bmp secret.txt\n");
	    return 1;
	}
    }
    else if (check_operation_type(argv) == e_decode)
    {
	//Check the number of arguments.
	if (argc < 3)
	{
	    printf("Please pass the .bmp\nUsage for Decoding : \n./a.out -d stego.bmp\n");
	    return 0;
	}

	printf("Selected decoding\n");

	// Declare structure variables
	DecodeInfo decInfo;
	if (read_and_validate_decode_args(argv, &decInfo) == e_success)
	{
	    // Decode the stego image
	    if (do_decoding(&decInfo) == e_success)
	    {
		printf("Decoding is successful\n");
	    }
	    else
	    {
		printf("Decoding is failed\n");
		return e_failure;
	    }
	}
	else
	{
	    printf("Invalide input \nFor Encoding : \n./a.out -e beautiful.bmp secret.txt\nFor Decoding : \n./a.out -d stego.bmp\n");
	    return 1;
	}
    }
    return 0;
}

/* Check for operation to be performed
 * Input: Command line arguments
 * Output: Operation to be performed
 * Return: integer constant coresponding to operation
 */
OperationType check_operation_type(char *argv[])
{
    if (strcmp(argv[1] , "-e") == 0)
    {
	return e_encode;
    }
    else if (strcmp(argv[1] , "-d") == 0)
    {
	return e_decode;
    }
    else
    {
	return e_unsupported;
    }
}
