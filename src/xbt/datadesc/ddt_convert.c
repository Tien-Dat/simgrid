/* ddt_remote - Stuff needed to get datadescs about remote hosts            */

/* Copyright (c) 2004, 2005, 2006, 2009, 2010. The SimGrid Team.
 * All rights reserved.                                                     */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

/************************************************************************/
/* C combines the power of assembler with the portability of assembler. */
/************************************************************************/

#include "datadesc_private.h"

XBT_LOG_NEW_DEFAULT_SUBCATEGORY(xbt_ddt_convert, xbt_ddt,
                                "Inter-architecture convertions");

/***
 *** Table of all known architectures:
 ***
l_C:1/1:_I:2/1:4/1:4/1:8/1:_P:4/1:4/1:_D:4/1:8/1: #xbt_arch=0;  xbt_size=32; xbt_arch_name=little32_1;
l_C:1/1:_I:2/2:4/2:4/2:8/2:_P:4/2:4/2:_D:4/2:8/2: #xbt_arch=1;  xbt_size=32; xbt_arch_name=little32_2;
l_C:1/1:_I:2/2:4/4:4/4:8/4:_P:4/4:4/4:_D:4/4:8/4: #xbt_arch=2;  xbt_size=32; xbt_arch_name=little32_4;
l_C:1/1:_I:2/2:4/4:4/4:8/8:_P:4/4:4/4:_D:4/4:8/8: #xbt_arch=3;  xbt_size=32; xbt_arch_name=little32_8;
l_C:1/1:_I:2/2:4/4:8/8:8/8:_P:8/8:8/8:_D:4/4:8/8: #xbt_arch=4;  xbt_size=64; xbt_arch_name=little64;
l_C:1/1:_I:2/2:4/4:4/4:8/8:_P:8/8:8/8:_D:4/4:8/8: #xbt_arch=5;  xbt_size=64; xbt_arch_name=little64_2;

B_C:1/1:_I:2/2:4/4:4/4:8/8:_P:4/4:4/4:_D:4/4:8/8: #xbt_arch=6;  xbt_size=32; xbt_arch_name=big32_8;
B_C:1/1:_I:2/2:4/4:4/4:8/8:_P:4/4:4/4:_D:4/4:8/4: #xbt_arch=7;  xbt_size=32; xbt_arch_name=big32_8_4;
B_C:1/1:_I:2/2:4/4:4/4:8/4:_P:4/4:4/4:_D:4/4:8/4: #xbt_arch=8;  xbt_size=32; xbt_arch_name=big32_4;
B_C:1/1:_I:2/2:4/2:4/2:8/2:_P:4/2:4/2:_D:4/2:8/2: #xbt_arch=9;  xbt_size=32; xbt_arch_name=big32_2;
B_C:1/1:_I:2/2:4/4:8/8:8/8:_P:8/8:8/8:_D:4/4:8/8: #xbt_arch=10; xbt_size=64; xbt_arch_name=big64;
B_C:1/1:_I:2/2:4/4:8/8:8/8:_P:8/8:8/8:_D:4/4:8/4: #xbt_arch=11; xbt_size=64; xbt_arch_name=big64_8_4;

  PLEASE DO NOT MESS WITH THESE HARDCODED VALUES
  
  
  Grep GRAS_THISARCH in buildtools/Cmake/CompleteInFiles.cmake for details
  
 ***/

const xbt_arch_desc_t xbt_arches[xbt_arch_count] = {

  {"little32_1", 0, {1, 2, 4, 4, 8, 4, 4, 4, 8},        /* little endian, 1 byte alignement (win32) */
   {1, 1, 1, 1, 1, 1, 1, 1, 1}},

  {"little32_2", 0, {1, 2, 4, 4, 8, 4, 4, 4, 8},        /* little endian, 2 bytes alignements (win32) */
   {1, 2, 2, 2, 2, 2, 2, 2, 2}},

  {"little32_4", 0, {1, 2, 4, 4, 8, 4, 4, 4, 8},        /* little endian, 4 bytes alignements (win32 and linux x86) */
   {1, 2, 4, 4, 4, 4, 4, 4, 4}},

  {"little32_8", 0, {1, 2, 4, 4, 8, 4, 4, 4, 8},        /* little endian, 8 bytes alignement (win32) */
   {1, 2, 4, 4, 8, 4, 4, 4, 8}},

  {"little64", 0, {1, 2, 4, 8, 8, 8, 8, 4, 8},  /* alpha, ia64 */
   {1, 2, 4, 8, 8, 8, 8, 4, 8}},

  {"little64_2", 0, {1, 2, 4, 4, 8, 8, 8, 4, 8},  /* win64 */
   {1, 2, 4, 4, 8, 8, 8, 4, 8}},

  {"big32_8", 1, {1, 2, 4, 4, 8, 4, 4, 4, 8},
   {1, 2, 4, 4, 8, 4, 4, 4, 8}},

  {"big32_8_4", 1, {1, 2, 4, 4, 8, 4, 4, 4, 8}, /* AIX */
   {1, 2, 4, 4, 8, 4, 4, 4, 4}},

  {"big32_4", 1, {1, 2, 4, 4, 8, 4, 4, 4, 8},   /* G5 */
   {1, 2, 4, 4, 4, 4, 4, 4, 4}},

  {"big32_2", 1, {1, 2, 4, 4, 8, 4, 4, 4, 8},   /* ARM */
   {1, 2, 2, 2, 2, 2, 2, 2, 2}},

  {"big64", 1, {1, 2, 4, 8, 8, 8, 8, 4, 8},     /* sparc */
   {1, 2, 4, 8, 8, 8, 8, 4, 8}},

  {"big64_8_4", 1, {1, 2, 4, 8, 8, 8, 8, 4, 8}, /* aix with -maix64 */
   {1, 2, 4, 8, 8, 8, 8, 4, 4}}
};

const char *xbt_datadesc_arch_name(int code)
{
  if (code < 0 || code >= xbt_arch_count)
    return "[unknown arch]";
  return xbt_arches[code].name;
}


/**
 * Local function doing the grunt work
 */
static void xbt_dd_reverse_bytes(void *to, const void *from,
                                  size_t length);

/**
 * xbt_dd_convert_elm:
 *
 * Convert the element described by @type comming from architecture @r_arch.
 * The data to be converted is stored in @src, and is to be stored in @dst.
 * Both pointers may be the same location if no resizing is needed.
 */
void
xbt_dd_convert_elm(xbt_datadesc_type_t type, int count,
                    int r_arch, void *src, void *dst)
{
  xbt_dd_cat_scalar_t scal = type->category.scalar_data;
  int cpt;
  const void *r_data;
  void *l_data;
  unsigned long r_size, l_size;
  /* Hexadecimal displayer
     union {
     char c[sizeof(int)];
     int i;
     } tester;
   */

  xbt_assert(type->category_code == e_xbt_datadesc_type_cat_scalar);
  xbt_assert(r_arch != GRAS_THISARCH);

  r_size = type->size[r_arch];
  l_size = type->size[GRAS_THISARCH];
  XBT_DEBUG("r_size=%lu l_size=%lu,    src=%p dst=%p", r_size, l_size, src,
         dst);

  XBT_DEBUG("remote=%c local=%c", xbt_arches[r_arch].endian ? 'B' : 'l',
         xbt_arches[GRAS_THISARCH].endian ? 'B' : 'l');

  if (r_size != l_size) {
    for (cpt = 0, r_data = src, l_data = dst;
         cpt < count;
         cpt++,
         r_data = (char *) r_data + r_size,
         l_data = (char *) l_data + l_size) {

      /*
         fprintf(stderr,"r_data=");
         for (cpt=0; cpt<r_size; cpt++) {
         tester.i=0;
         tester.c[0]= ((char*)r_data)[cpt];
         fprintf(stderr,"\\%02x", tester.i);
         }
         fprintf(stderr,"\n");
       */

      /* Resize that damn integer, pal */

      unsigned char *l_sign, *r_sign;
      int padding;
      int sizeChange = l_size - r_size;
      int lowOrderFirst = !xbt_arches[r_arch].endian ||
          xbt_arches[r_arch].endian == xbt_arches[GRAS_THISARCH].endian;

      XBT_DEBUG("Resize integer %d from %lu @%p to %lu @%p",
             cpt, r_size, r_data, l_size, l_data);
      xbt_assert(r_data != l_data, "Impossible to resize in place");

      if (sizeChange < 0) {
        XBT_DEBUG("Truncate %d bytes (%s,%s)", -sizeChange,
               lowOrderFirst ? "lowOrderFirst" : "bigOrderFirst",
               scal.encoding ==
               e_xbt_dd_scalar_encoding_sint ? "signed" : "unsigned");
        /* Truncate high-order bytes. */
        memcpy(l_data,
               xbt_arches[r_arch].endian ? ((char *) r_data - sizeChange)
               : r_data, l_size);

        if (scal.encoding == e_xbt_dd_scalar_encoding_sint) {
          XBT_DEBUG("This is signed");
          /* Make sure the high order bit of r_data and l_data are the same */
          l_sign = xbt_arches[GRAS_THISARCH].endian
              ? ((unsigned char *) l_data + l_size - 1)
              : (unsigned char *) l_data;
          r_sign = xbt_arches[r_arch].endian
              ? ((unsigned char *) r_data + r_size - 1)
              : (unsigned char *) r_data;
          XBT_DEBUG("This is signed (r_sign=%c l_sign=%c", *r_sign, *l_sign);

          if ((*r_sign > 127) != (*l_sign > 127)) {
            if (*r_sign > 127)
              *l_sign += 128;
            else
              *l_sign -= 128;
          }
        }
      } else {
        XBT_DEBUG("Extend %d bytes", sizeChange);
        if (scal.encoding != e_xbt_dd_scalar_encoding_sint) {
          XBT_DEBUG("This is signed");
          padding = 0;          /* pad unsigned with 0 */
        } else {
          /* extend sign */
          r_sign =
              xbt_arches[r_arch].endian ? ((unsigned char *) r_data +
                                            r_size - 1)
              : (unsigned char *) r_data;
          padding = (*r_sign > 127) ? 0xff : 0;
        }

        if (l_size != 0) {
          memset(l_data, padding, l_size);
        }
        memcpy(!xbt_arches[r_arch].endian ? l_data
               : ((char *) l_data + sizeChange), r_data, r_size);

        /*
           fprintf(stderr,"r_data=");
           for (cpt=0; cpt<r_size; cpt++) {
           tester.i=0;
           tester.c[0] = ((char*)r_data)[cpt];
           fprintf(stderr,"\\%02x", tester.i);
           }
           fprintf(stderr,"\n");

           fprintf(stderr,"l_data=");
           for (cpt=0; cpt<l_size; cpt++) {
           tester.i=0;
           tester.c[0]= ((char*)l_data)[cpt];
           fprintf(stderr,"\\%02x", tester.i);
           } fprintf(stderr,"\n");
         */
      }
    }
  }

  /* flip bytes if needed */
  if (xbt_arches[r_arch].endian != xbt_arches[GRAS_THISARCH].endian &&
      (l_size * count) > 1) {

    for (cpt = 0, r_data = dst, l_data = dst; cpt < count; cpt++, r_data = (char *) r_data + l_size,    /* resizing already done */
         l_data = (char *) l_data + l_size) {

      XBT_DEBUG("Flip elm %d", cpt);
      xbt_dd_reverse_bytes(l_data, r_data, l_size);
    }
  }

}

static void xbt_dd_reverse_bytes(void *to, const void *from,
                                  size_t length)
{

  char charBegin;
  const char *fromBegin;
  const char *fromEnd;
  char *toBegin;
  char *toEnd;

  for (fromBegin = (const char *) from,
       fromEnd = fromBegin + length - 1,
       toBegin = (char *) to,
       toEnd = toBegin + length - 1;
       fromBegin <= fromEnd; fromBegin++, fromEnd--, toBegin++, toEnd--) {

    charBegin = *fromBegin;
    *toBegin = *fromEnd;
    *toEnd = charBegin;
  }
}


/**
 * xbt_arch_selfid:
 *
 * returns the ID of the architecture the process is running on
 */
int xbt_arch_selfid(void)
{
  return GRAS_THISARCH;
}