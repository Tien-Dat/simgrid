/* Copyright (c) 2015. The SimGrid Team.  All rights reserved.         */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

#include <xbt/dynar.h>

#include "mc/datatypes.h"
#include "mc_process.h"

#include "xbt/misc.h"           /* SG_BEGIN_DECL */

SG_BEGIN_DECL();

XBT_INTERNAL void MC_stack_area_add(stack_region_t stack_area);

XBT_INTERNAL xbt_dynar_t MC_checkpoint_ignore_new(void);

SG_END_DECL();
