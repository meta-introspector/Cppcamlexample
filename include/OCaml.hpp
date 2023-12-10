#pragma once
// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

// OCaml uses "Assert" instead of "assert" for some reason - these do the same thing though. So this is kinda needed.
#include <assert.h>
#define Assert assert

#include<caml/address_class.h>
#include<caml/alloc.h>
#include<caml/backtrace_prim.h>
#include<caml/backtrace.h>
#include<caml/bigarray.h>
#include<caml/callback.h> // this one's the big important one for embedding OCaml
//#include<caml/compact.h>
#include<caml/compare.h>
//#include<caml/compatibility.h>
#include<caml/config.h>
#include<caml/custom.h>
#include<caml/debugger.h>
#include<caml/dynlink.h>
#include<caml/exec.h>
#include<caml/fail.h>
#include<caml/finalise.h>
#include<caml/fix_code.h>
//#include<caml/freelist.h>
#include<caml/gc_ctrl.h>
#include<caml/gc.h>
#include<caml/globroots.h>
#include<caml/hash.h>
#include<caml/hooks.h>
#include<caml/instrtrace.h>
#include<caml/instruct.h>
//#include<caml/int64_emul.h>
//#include<caml/int64_format.h>
//#include<caml/int64_native.h>
#include<caml/interp.h>
#include<caml/intext.h>
#include<caml/io.h>
//#include<caml/jumptbl.h> // gives compile errors
#include<caml/major_gc.h>
#include<caml/md5.h>
#include<caml/memory.h>
#include<caml/minor_gc.h>
#include<caml/misc.h>
#include<caml/mlvalues.h>
#include<caml/osdeps.h>
#include<caml/prims.h>
#include<caml/printexc.h>
#include<caml/reverse.h>
#include<caml/roots.h>
//#include<caml/signals_machdep.h>
#include<caml/signals.h>
#include<caml/socketaddr.h>
//#include<caml/spacetime.h>
#include<caml/stack.h>
//#include<caml/stacks.h>
#include<caml/startup_aux.h>
#include<caml/startup.h>
#include<caml/sys.h>
#include<caml/threads.h>
//#include<caml/ui.h>
#include<caml/unixsupport.h>
#include<caml/version.h>
#include<caml/weak.h>
