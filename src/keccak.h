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
#ifndef __KECCAK_H__
#define __KECCAK_H__

#include <stdlib.h>
#include <stdio.h>



/**
 * Calculate the checksum of buffer, using SHA-3 (Keccak)
 * 
 * @param  input       The input buffer
 * @param  inputsize   The input buffer size
 * @param  output      The output buffer
 * @param  outputsize  The output buffer size
 */
void checksum(unsigned char* input, size_t inputsize, unsigned char* output, size_t outputsize);


#endif /* __KECCAK_H__ */
