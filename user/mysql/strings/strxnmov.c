/* Copyright (C) 2002 MySQL AB
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.
   
   You should have received a copy of the GNU Library General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA */

/*  File   : strxnmov.c
    Author : Richard A. O'Keefe.
    Updated: 2 June 1984
    Defines: strxnmov()

    strxnmov(dst, len, src1, ..., srcn, NullS)
    moves the first len characters of the concatenation of src1,...,srcn
    to dst.  If there aren't that many characters, a NUL character will
    be added to the end of dst to terminate it properly.  This gives the
    same effect as calling strxcpy(buff, src1, ..., srcn, NullS) with a
    large enough buffer, and then calling strnmov(dst, buff, len).
    It is just like strnmov except that it concatenates multiple sources.
    Beware: the last argument should be the null character pointer.
    Take VERY great care not to omit it!  Also be careful to use NullS
    and NOT to use 0, as on some machines 0 is not the same size as a
    character pointer, or not the same bit pattern as NullS.

    Note: strxnmov is like strnmov in that it moves up to len
    characters; dst will be padded on the right with one NUL characters if
    needed.
*/

#include <my_global.h>
#include "m_string.h"
#include <stdarg.h>

char *strxnmov(char *dst,uint len, const char *src, ...)
{
  va_list pvar;
  char *end_of_dst=dst+len;

  va_start(pvar,src);
  while (src != NullS)
  {
    do
    {
      if (dst == end_of_dst)
	goto end;
    }
    while ((*dst++ = *src++));
    dst--;
    src = va_arg(pvar, char *);
  }
  *dst=0;
end:
  va_end(pvar);
  return dst;
}
