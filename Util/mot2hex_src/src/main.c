/*
* Intel HEX to Motorola MOT Converter
* Author: FT
* Usage: mot2hex <filename.hex>
*/

#include <stdlib.h>
#include "gethex.h"

int main(int argc, char *argv[])
{
  FILE *fp_in, *fp_out;
  char fname_in[256];
  char fname_out[256];
  int byte, addr, start, i;
  int motorola_check, intel_check;
  int motorola_count, intel_count;
  
  if (argc != 2)
  {
    printf("\nhex2mot version 0.99 - 2015-05-27\n");
    printf("Command line utility to convert a Motorola MOT file to Intel HEX format\n");
    printf( "\n usage: mot2hex <filename.mot> \n" );
    printf( "\n        the output will be a file named filename.mot.hex \n" );
    return 0;
  }
  
  sprintf(fname_in, "%s", argv[1]);
  fp_in = fopen(fname_in, "r");
  fopen_check(fp_in,fname_in);
    
  sprintf( fname_out, "%s.hex", argv[1] );
  fp_out = fopen(fname_out, "w");
  fopen_check(fp_out,fname_out);
  
  byte = 0;
  addr = 0;
  start = -1;
  
  while( byte != -1 )
  {
    /*
    * Motorola 8-bit record starts with "S1"
    */
    do 
    {
      byte = fgetc(fp_in);
    } while((byte != 'S') && (byte != -1));
    
    byte = fgetc(fp_in);
    if( byte == '1' )
    {
      /*
      * Get byte count from Motorola record
      */
      motorola_count = get2hex(fp_in);
      motorola_check = motorola_count;
      
      /*
      * Intel byte count is for data field only
      * round up to even byte boundary
      */
      intel_count = motorola_count - 3;
      intel_check = intel_count;
      
      /*
      * Get two byte Motorola address field
      */
      addr = get4hex(fp_in);
      motorola_check += (addr & 0xFF); 
      motorola_check += (addr & 0xFF00) >> 8;
      
      /*
      * output Intel start of record
      * ":" <data count> <address> <record type>
      */
      intel_check += (addr & 0xFF);
      intel_check += (addr & 0xFF00) >> 8;
      fprintf(fp_out, ":%02X%04x00", intel_count, addr );
      
      /*
      * Input Motorola data field
      */
      for (i=0; i < intel_count; ++i)
      {
        byte = get2hex(fp_in);
        motorola_check += byte;
        
        /*
        * Output Intel data field
        */
        intel_check += byte;
        fprintf(fp_out, "%02X", byte);
        
        /*
        * Get the start of record from the reset vector
        */
        if(addr == 0xFFFE)
        {
          start = byte * 256;
        }
        if(addr == 0xFFFF)
        {
          start += byte;
        }
        addr ++;
      }
      
      /*
      * Display Motorola checksum for current record
      * should be 0xFF
      */	
      byte = get2hex(fp_in) & 0xFF;
      motorola_check += byte;
      motorola_check &= 0xFF;
      printf(" Motorola checksum = %02X   ", motorola_check);
      
      /*
      * Display Intel checksum
      */
      intel_check &= 0xFF;
      intel_check = 0x100 - intel_check;
      intel_check &= 0xFF;
      printf("-> Intel checksum = %02X \n", intel_check);
      
      /*
      * Output Intel checksum
      */
      fprintf(fp_out, "%02X\n", intel_check);
      if( addr > 0xFFFF )
      {
        byte = -1;
      }
    }
  }
  
  /*
  * output Intel transfer address
  */
  if( start != -1 )
  {
    fprintf(fp_out, ":00%04x01", start);
  }
  
  if (intel_count)
  {
    printf("\n \n Conversion process finished.\n");
  }
  
  /*
  * Close input and output files and exit
  */
  fclose(fp_in);
  fclose(fp_out);
  
  return 0;
}

int fopen_check(FILE *fp, const char *fname)
{
  if(!fp)
  {
    printf("Can't open %s", fname);
    exit(0);
  }
  return 1;
}