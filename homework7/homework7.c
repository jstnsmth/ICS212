/******************************************************************
//
//  NAME:        Justin Smith
//
//  HOMEWORK:    8
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 10, 2023
//
//  FILE:        homework8.c
//
//  DESCRIPTION: This program reads a binary file that contains a TCP header. Then it will print the data in the file.
//               Will then generate a response header and write that data  to a response binary file.
//
******************************************************************/

#include <stdio.h>

/******************************************************************
// 
//  Function name: readfile
//
//  DESCRIPTION:   Will read a binary file and store the data into the unsigned char[] called request.
//  
//  Parameters:    filename (const char[]) : the file name
//                 request  (unsigned char[]) : where the data from the binary file will be stored.
//
//  Return values: 0 : success
//                -1 : fail
//
******************************************************************/

int readfile(const char filename[], unsigned char request[])
{
    int result = 0;
    FILE * filePointer;
    filePointer = fopen(filename, "rb");

    if (filePointer != NULL)
    {
        fread(request, 1, 20, filePointer);
        fclose(filePointer);
    }
    else
    {
        result = -1;
    }
    return result;
}

/******************************************************************
//  
//  Function name: writefile
//
//  DESCRIPTION:   Will write into a binary file that contains the response data.
//
//  Parameters:    filename (const char[]) : the file name
//                 response (unsigned char[]) : the data that will be written into the binary file
//
//  Return values: 0 : success
//                -1 : fail
//
******************************************************************/

int writefile(const char filename[], unsigned char response[])
{
    int result = 0;
    FILE * filePointer;
    filePointer = fopen(filename, "wb");

    if (filePointer != NULL)
    {
        fwrite(response, 1, 20, filePointer);
        fclose(filePointer);
    }
    else
    {
        result = -1;
    }
    return result;
}

/******************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION:   Will print out the data inside of the binary file which is stored inside of request.
//                 Will print out the source port, destination port, sequence number, acknowledgement number
//                 and will print any of the control bits which are turned on.
//
//  Parameters:    data (const unsigned char[]) : holds the binary data
//
//  Return values: void
//
******************************************************************/

void printheader(const unsigned char data[])
{
    int i;
    char flags[6][4] = {"URG", "ACK", "PSH", "RST", "SYN", "FIN"};
    unsigned int seqNum = (data[7] << 24) | (data[6] << 16) | (data[5] << 8) | data[4];
    unsigned int ackNum = (data[11] << 24) | (data[10] << 16) | (data[9] << 8) | data[8];

    printf("Data: ");
    for (i = 0; i < 20; i++)
    {
        printf("%02X ", data[i]);
    }
    printf("\nSource Port: %d\n", (data[1] << 8) | data[0]);
    printf("Destination Port: %d\n", (data[3] << 8) | data[2]);
    printf("Sequence Number: %u\n", seqNum);
    printf("Acknowledgement Number: %u\n", ackNum);
    printf("Control bits which are set to 1:\n");

    for (i = 0; i < 6; i++)
    {
        if (data[13] & (1 << (5-i)))
        {
            printf("%s\n", flags[i]);
        }
    }
}

/******************************************************************
//
//  Function name: makeheader
//
//  DESCRIPTION:   Uses the request data to generate a response header and store it into an unsigned char array.
//                 If sourceport is greater than 32767 it will flip the 4th and 11th bits.
//                 Switches the source and destination ports.
//                 Sets the acknowledgment number to the sequence number of the request header
//                 Sets the sequence number to the sequence number of the request header and increments it.
//                 If the control bit SYN is set to 1. Will set SYN and ACK to 1 in response header
//                 Rest is identical
//
//  Parameters:    request (const unsigned char[]) : holds the request TCP header data.
//                 response (unsigned char[])      : will hold the response header data.
//
//  Return values: void
//
******************************************************************/

void makeheader(const unsigned char request[], unsigned char response[])
{
    int i;
    unsigned int sourcePort = (request[1] << 8 | request[0]);
    unsigned int seqNum = (request[7] << 24) | (request[6] << 16) | (request[5] << 8) | request[4];

    if (sourcePort & 0x8000)
    {
        sourcePort ^= 0x1020;
    }

    seqNum++;
    response[0] = request[2];
    response[1] = request[3];
    response[2] = sourcePort;
    response[3] = (sourcePort >> 8);
    response[4] = seqNum;
    response[5] = (seqNum >> 8);
    response[6] = (seqNum >> 16);
    response[7] = (seqNum >> 24);
    response[8] = request[4];
    response[9] = request[5];
    response[10] = request[6];
    response[11] = request[7];
    response[12] = request[12];
    response[13] = request[13];

    if (request[13] & (1 << 1))
    {
        response[13] |= (1 << 1) | (1 << 4);
    }

    for (i = 14; i < 20; i++)
    {
        response[i] = request[i];
    }
}

/******************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Will correctly call the functions to read the three request files, prints the data of the request files,
//                 makes the header of the request files and will write the response into separate binary files.
//  
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]) : array of arguments
//
//  Return values: 0 : success
//
******************************************************************/

int main(int argc, char* argv[])
{
    unsigned char request[20];
    unsigned char responseHeader[20];

    printf("\nRequest 1:\n");
    if (readfile("request1.bin", request) == 0)
    {
        printheader(request);
        makeheader(request, responseHeader);
        printf("\nResponse 1:\n");
        printheader(responseHeader);
        if (writefile("response1.bin", responseHeader) == -1)
        {
            printf("Unable to write file.\n");
        }
    }
    else
    {
        printf("Unable to read file.\n");
    }

    printf("\nRequest 2:\n");
    if (readfile("request2.bin", request) == 0)
    {
        printheader(request);
        makeheader(request, responseHeader);
        printf("\nResponse 2:\n");
        printheader(responseHeader);
        if (writefile("response2.bin", responseHeader) == -1)
        {
            printf("Unable to write file.\n");
        }
    }
    else
    {
        printf("Unable to read file.\n");
    }

    printf("\nRequest 3:\n");
    if (readfile("request3.bin", request) == 0)
    {
        printheader(request);
        makeheader(request, responseHeader);
        printf("\nResponse 3:\n");
        printheader(responseHeader);
        if (writefile("response3.bin", responseHeader) == -1)
        {
            printf("Unable to write file.\n");
        }
        printf("\n");
    }
    else
    {
        printf("Unable to read file.\n");
    }
    return 0;
}
