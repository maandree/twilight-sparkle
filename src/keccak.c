/**
 * twilight-sparkle – Bootkits detection software
 * 
 * Copyright © 2012  Mattias Andrée (maandree@kth.se)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "keccak.h"



/**
 * Mane method!
 * 
 * @param  argc  Full command line argument count (unused)
 * @param  argv  Full command line argument array (unused)
 */
int main(int argc, char** argv)
{
  (void) argc;
  (void) argv;
  
  unsigned char* test = (unsigned char*)"The quick brown fox jumps over the lazy dog.";
  size_t testlen = 43;
  
  size_t* sizes = (size_t*)malloc(8 * sizeof(size_t));
  char** corrects = (char**)malloc(8 * sizeof(char**));
  *sizes++ = 224;  *corrects++ = "310aee6b30c47350576ac2873fa89fd190cdc488442f3ef654cf23fe";
  *sizes++ = 224;  *corrects++ = "c59d4eaeac728671c635ff645014e2afa935bebffdb5fbd207ffdeab";
  *sizes++ = 256;  *corrects++ = "4d741b6f1eb29cb2a9b9911c82f56fa8d73b04959d3d9d222895df6c0b28aa15";
  *sizes++ = 256;  *corrects++ = "578951e24efd62a3d63a86f7cd19aaa53c898fe287d2552133220370240b572d";
  *sizes++ = 384;  *corrects++ = "283990fa9d5fb731d786c5bbee94ea4db4910f18c62c03d173fc0a5e494422e8a0b3da7574dae7fa0baf005e504063b3";
  *sizes++ = 384;  *corrects++ = "9ad8e17325408eddb6edee6147f13856ad819bb7532668b605a24a2d958f88bd5c169e56dc4b2f89ffd325f6006d820b";
  *sizes++ = 512;  *corrects++ = "d135bb84d0439dbac432247ee573a23ea7d3c9deb2a968eb31d47c4fb45f1ef4422d6c531b5b9bd6f449ebcc449ea94d0a8f05f62130fda612da53c79659f609";
  *sizes++ = 512;  *corrects++ = "ab7192d2b11f51c7dd744e7b3441febf397ca07bf812cceae122ca4ded6387889064f8db9230f173f6d1ab6e24b6e50f065b039f799f5592360a6558eb52d760";
  sizes -= 8;
  corrects -= 8;
  
  size_t size;
  char* correct;
  unsigned char* result;
  
  int passed;
  unsigned char have;
  unsigned char should_have;
  
  long i;
  for (i = 0; i < 8; i++)
    {
      size = *(sizes + i) >> 3;
      correct = *(corrects + i);
      result = (unsigned char*)malloc(size);
      checksum(test, testlen + (i & 1), result, size);
      
      passed = 1;
      for (long j = 0; j < (long)size; j++)
	{
	  have = *(result + j);
	  should_have = 0;
	  for (int k = 0; k < 2; k++)
	    {
	      char c = *(correct + (j << 1) + k);
	      should_have = (should_have << 4) | (c - (c < 'a' ? '0' : ('a' - 10)));
	    }
	  
	  if (have != should_have)
	    {
	      passed = 0;
	      break;
	    }
	}
      
      printf(passed ? "passed\n" : "failed\n");
      
      free(result);
    }
  
  free(sizes);
  free(corrects);
}



/**
 * Calculate the checksum of buffer, using SHA-3 (Keccak)
 * 
 * @param  input       The input buffer
 * @param  inputsize   The input buffer size
 * @param  output      The output buffer
 * @param  outputsize  The output buffer size
 */
void checksum(unsigned char* input, size_t inputsize, unsigned char* output, size_t outputsize)
{
}

