/*
 * storage_private.h
 *
 *  Created on: 2 mars 2012
 *      Author: navarro
 */

#ifndef STORAGE_PRIVATE_H_
#define STORAGE_PRIVATE_H_

typedef struct storage {
  s_surf_resource_t generic_resource;   /*< Structure with generic data. Needed at begin to interate with SURF */
  e_surf_resource_state_t state_current;        /*< STORAGE current state (ON or OFF) */
  lmm_constraint_t constraint;
} s_storage_t, *storage_t;

typedef struct surf_action_storage {
  s_surf_action_lmm_t generic_lmm_action;
  int index_heap;
} s_surf_action_storage_t, *surf_action_storage_t;

#endif /* STORAGE_PRIVATE_H_ */