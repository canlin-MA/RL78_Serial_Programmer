#include "gethex.h"

/*********************************************************************************************
* Function Name: getHex
* Description  : This function converts from hexadecimal ASCII representation to integer
* Arguments    : fp_in - input file pointer
* Return Value : 8-bit integer hex from ASCII
**********************************************************************************************/
int gethex(FILE *fp_in)
{
  int hex;
  
  hex = fgetc(fp_in);
  if ((hex >= '0') && (hex <= '9' ))
  {
    hex -= '0';
  }
  else if((hex >= 'A') && (hex <= 'F'))
  {
    hex = hex - 'A' + 10;
  }
  else
  {
    hex = -1; /* error ? */
  }
  return hex;
}

/*********************************************************************************************
* Function Name: get2Hex
* Description  : This function converts from hexadecimal ASCII representation to integer
* Arguments    : fp_in - input file pointer
* Return Value : 16-bit integer hex from ASCII
**********************************************************************************************/
int get2hex(FILE *fp_in)
{
  int hexhi, hexlo, byte;
  
  hexhi = gethex(fp_in);
  if (hexhi != -1)
  {
    hexlo = gethex(fp_in); 
    if (hexlo != -1)
    {
      byte = ((hexhi * 16) + hexlo);
      return byte;
    }
  }
  return -1;
}
/*********************************************************************************************
* Function Name: get4Hex
* Description  : This function converts from hexadecimal ASCII representation to integer
* Arguments    : fp_in - input file pointer
* Return Value : 16-bit integer hex from ASCII
**********************************************************************************************/
int get4hex(FILE *fp_in)
{
  int bytehi, bytelo, addr;
  
  bytehi = get2hex(fp_in);
  if (bytehi != -1)
  {
    bytelo = get2hex(fp_in);
    if (bytelo != -1)
    {
      addr = ((bytehi * 256) + bytelo);
      return addr;
    }
  }
  return -1;
}    