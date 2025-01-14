/* Definitions for Loongarch Haiku systems with ELF format.
   Copyright (C) 1998-2017 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()		\
  do									\
    {									\
      builtin_define ("__HAIKU__");					\
      builtin_define ("__stdcall=__attribute__((__stdcall__))");	\
      builtin_define ("__cdecl=__attribute__((__cdecl__))");		\
      builtin_define ("__STDC_ISO_10646__=201103L"); \
      builtin_assert ("system=haiku");					\
    }									\
  while (0)

#define MUSL_ABI_SPEC \
  "%{mabi=lp64d:}" \
  "%{mabi=lp64f:-sp}" \
  "%{mabi=lp64s:-sf}"

/* SUBTARGET_CC1_SPEC is passed to the compiler proper.  It may be
   overridden by subtargets.  */
#ifndef SUBTARGET_CC1_SPEC
#define SUBTARGET_CC1_SPEC ""
#endif

#undef LIB_SPEC
// Linux adds -latomic from RISC-V only has word-sized atomics
// Not sure if we really need it though.
#define LIB_SPEC " -lroot "

// riscv.h defines /lib and friends which breaks the sysroot
#undef STARTFILE_PREFIX_SPEC

#undef	LINK_SPEC
#define LINK_SPEC "-melf" ABI_GRLEN_SPEC "loongarch" " %{!r:-shared} %{nostart:-e 0} %{shared:-e 0} %{!shared: %{!nostart: -no-undefined}} -X"
