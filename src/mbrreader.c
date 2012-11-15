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
#include "mbrreader.h"
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
  
  FILE* file = fopen("/dev/" DISC, "r");
  if (file)
    {
      unsigned char* mbr = (unsigned char*)malloc(MBR_SIZE);
      size_t gotbytes = fread(mbr, 1, MBR_SIZE, file);
      if (gotbytes < MBR_SIZE)
	{
	  printweird("What the hay! Could not read entire MBR in one sweep.");
	  size_t total = gotbytes;
	  while (total < MBR_SIZE)
	  {
	    gotbytes = fread(mbr + total, 1, MBR_SIZE - total, file);
	    if (gotbytes <= 0)
	      {
		printerror("Could not read entire MBR.");
		fclose(file);
		free(mbr);
		return 1;
	      }
	    total += gotbytes;
	  }
	}
      fclose(file);
      free(mbr);
    }
  else
    {
      printerror("Cannot read disc /dev/" DISC ", are you root?\n");
    }
  
  return 0;
}

