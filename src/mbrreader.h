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
#ifndef __MBRREADER_H__
#define __MBRREADER_H__

#include <stdio.h>
#include <stdlib.h>



/**
 * The size of the MBR code, this should never ever be modified.
 */
#define MBR_SIZE 446


/**
 * Print information a about something that is weird
 */
#define printweird(message)  printf("\033[33mtwilight-sparkle: weird: \033[39m" message);

/**
 * Print information a about an error
 */
#define printerror(message)  printf("\033[1;31mtwilight-sparkle: error: \033[39m" message "\033[0m");


#endif /* __MBRREADER_H__ */
