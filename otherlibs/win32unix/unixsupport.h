/***********************************************************************/
/*                                                                     */
/*                           Objective Caml                            */
/*                                                                     */
/*  Xavier Leroy and Pascal Cuoq, projet Cristal, INRIA Rocquencourt   */
/*                                                                     */
/*  Copyright 1996 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

/* $Id$ */

#include <wtypes.h>
#include <winbase.h>
#include <stdlib.h>
/* Include io.h in current dir, which is a copy of the system's io.h,
   not io.h from ../../byterun */
#include "io.h"
#include <direct.h>
#include <process.h>

#define Handle_val(v) (*((HANDLE *) Data_custom_val(v)))

extern value win_alloc_handle(HANDLE);

#define Nothing ((value) 0)

extern void win32_maperr(unsigned long errcode);
extern void unix_error (int errcode, char * cmdname, value arg);
extern void uerror (char * cmdname, value arg);
extern value unix_freeze_buffer (value);

#define UNIX_BUFFER_SIZE 16384
