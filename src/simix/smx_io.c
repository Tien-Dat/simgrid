/* Copyright (c) 2007, 2008, 2009, 2010. The SimGrid Team.
 * All rights reserved.                                                     */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

#include "smx_private.h"
#include "xbt/sysdep.h"
#include "xbt/log.h"
#include "xbt/dict.h"
#include "mc/mc.h"

XBT_LOG_NEW_DEFAULT_SUBCATEGORY(simix_io, simix,
                                "Logging specific to SIMIX (io)");


//SIMIX FILE READ
void SIMIX_pre_file_read(smx_simcall_t simcall)
{
  smx_action_t action = SIMIX_file_read(simcall->issuer,
      simcall->file_read.ptr,
      simcall->file_read.size,
      simcall->file_read.nmemb,
      simcall->file_read.stream);
  xbt_fifo_push(action->simcalls, simcall);
  simcall->issuer->waiting_action = action;
}

smx_action_t SIMIX_file_read(smx_process_t process, void* ptr, size_t size, size_t nmemb, smx_file_t stream)
{
  smx_action_t action;
  smx_host_t host = process->smx_host;

  /* check if the host is active */
  if (surf_workstation_model->extension.
      workstation.get_state(host->host) != SURF_RESOURCE_ON) {
    THROWF(host_error, 0, "Host %s failed, you cannot call this function",
           host->name);
  }

  action = xbt_mallocator_get(simix_global->action_mallocator);
  action->type = SIMIX_ACTION_IO;
  action->name = NULL;
#ifdef HAVE_TRACING
  action->category = NULL;
#endif

  action->io.host = host;
  //  TODO in surf model disk???
  //  action->io.surf_io = surf_workstation_model->extension.storage.read(host->host, name),
  action->io.surf_io = surf_workstation_model->extension.workstation.sleep(host->host, 1.0);

  surf_workstation_model->action_data_set(action->io.surf_io, action);
  XBT_DEBUG("Create io action %p", action);

  return action;
}

//SIMIX FILE WRITE
void SIMIX_pre_file_write(smx_simcall_t simcall)
{
  smx_action_t action = SIMIX_file_write(simcall->issuer,
      simcall->file_write.ptr,
      simcall->file_write.size,
      simcall->file_write.nmemb,
      simcall->file_write.stream);
  xbt_fifo_push(action->simcalls, simcall);
  simcall->issuer->waiting_action = action;
}

smx_action_t SIMIX_file_write(smx_process_t process, const void* ptr, size_t size, size_t nmemb, smx_file_t stream)
{
  smx_action_t action;
  smx_host_t host = process->smx_host;

  /* check if the host is active */
  if (surf_workstation_model->extension.
      workstation.get_state(host->host) != SURF_RESOURCE_ON) {
    THROWF(host_error, 0, "Host %s failed, you cannot call this function",
           host->name);
  }

  action = xbt_mallocator_get(simix_global->action_mallocator);
  action->type = SIMIX_ACTION_IO;
  action->name = NULL;
#ifdef HAVE_TRACING
  action->category = NULL;
#endif

  action->io.host = host;
  //  TODO in surf model disk???
  //  action->io.surf_io = surf_workstation_model->extension.storage.write(host->host, name),
  action->io.surf_io = surf_workstation_model->extension.workstation.sleep(host->host, 2.0);

  surf_workstation_model->action_data_set(action->io.surf_io, action);
  XBT_DEBUG("Create io action %p", action);

  return action;
}

//SIMIX FILE OPEN
void SIMIX_pre_file_open(smx_simcall_t simcall)
{
  smx_action_t action = SIMIX_file_open(simcall->issuer,
      simcall->file_open.path,
      simcall->file_open.mode);
  xbt_fifo_push(action->simcalls, simcall);
  simcall->issuer->waiting_action = action;
}

smx_action_t SIMIX_file_open(smx_process_t process, const char* path, const char* mode)
{
  smx_action_t action;
  smx_host_t host = process->smx_host;

  /* check if the host is active */
  if (surf_workstation_model->extension.
      workstation.get_state(host->host) != SURF_RESOURCE_ON) {
    THROWF(host_error, 0, "Host %s failed, you cannot call this function",
           host->name);
  }

  action = xbt_mallocator_get(simix_global->action_mallocator);
  action->type = SIMIX_ACTION_IO;
  action->name = NULL;
#ifdef HAVE_TRACING
  action->category = NULL;
#endif

  action->io.host = host;
  //  TODO in surf model disk???
  //  action->io.surf_io = surf_workstation_model->extension.storage.open(host->host, name),
  action->io.surf_io = surf_workstation_model->extension.workstation.sleep(host->host, 3.0);

  surf_workstation_model->action_data_set(action->io.surf_io, action);
  XBT_DEBUG("Create io action %p", action);

  return action;
}

//SIMIX FILE CLOSE
void SIMIX_pre_file_close(smx_simcall_t simcall)
{
  smx_action_t action = SIMIX_file_close(simcall->issuer,
      simcall->file_close.fp);
  xbt_fifo_push(action->simcalls, simcall);
  simcall->issuer->waiting_action = action;
}

smx_action_t SIMIX_file_close(smx_process_t process, smx_file_t fp)
{
  smx_action_t action;
  smx_host_t host = process->smx_host;

  /* check if the host is active */
  if (surf_workstation_model->extension.
      workstation.get_state(host->host) != SURF_RESOURCE_ON) {
    THROWF(host_error, 0, "Host %s failed, you cannot call this function",
           host->name);
  }

  action = xbt_mallocator_get(simix_global->action_mallocator);
  action->type = SIMIX_ACTION_IO;
  action->name = NULL;
#ifdef HAVE_TRACING
  action->category = NULL;
#endif

  action->io.host = host;
  //  TODO in surf model disk???
  //  action->io.surf_io = surf_workstation_model->extension.storage.close(host->host, name),
  action->io.surf_io = surf_workstation_model->extension.workstation.sleep(host->host, 4.0);

  surf_workstation_model->action_data_set(action->io.surf_io, action);
  XBT_DEBUG("Create io action %p", action);

  return action;
}

//SIMIX FILE STAT
void SIMIX_pre_file_stat(smx_simcall_t simcall)
{
  smx_action_t action = SIMIX_file_stat(simcall->issuer,
      simcall->file_stat.fd,
      simcall->file_stat.buf);
  xbt_fifo_push(action->simcalls, simcall);
  simcall->issuer->waiting_action = action;
}

smx_action_t SIMIX_file_stat(smx_process_t process, int fd, void* buf)
{
  smx_action_t action;
  smx_host_t host = process->smx_host;

  /* check if the host is active */
  if (surf_workstation_model->extension.
      workstation.get_state(host->host) != SURF_RESOURCE_ON) {
    THROWF(host_error, 0, "Host %s failed, you cannot call this function",
           host->name);
  }

  action = xbt_mallocator_get(simix_global->action_mallocator);
  action->type = SIMIX_ACTION_IO;
  action->name = NULL;
#ifdef HAVE_TRACING
  action->category = NULL;
#endif

  action->io.host = host;
  //  TODO in surf model disk???
  //  action->io.surf_io = surf_workstation_model->extension.storage.stat(host->host, name),
  action->io.surf_io = surf_workstation_model->extension.workstation.sleep(host->host, 5.0);

  surf_workstation_model->action_data_set(action->io.surf_io, action);
  XBT_DEBUG("Create io action %p", action);

  return action;
}

void SIMIX_post_io(smx_action_t action)
{
  switch (surf_workstation_model->action_state_get(action->io.surf_io)) {

    case SURF_ACTION_FAILED:
      action->state = SIMIX_FAILED;
      break;

    case SURF_ACTION_DONE:
      action->state = SIMIX_DONE;
      break;

    default:
      THROW_IMPOSSIBLE;
      break;
  }

  SIMIX_io_finish(action);
}

void SIMIX_io_destroy(smx_action_t action)
{
  XBT_DEBUG("Destroy action %p", action);
  if (action->io.surf_io)
    action->io.surf_io->model_type->action_unref(action->io.surf_io);
  xbt_mallocator_release(simix_global->action_mallocator, action);
}

void SIMIX_io_finish(smx_action_t action)
{
  volatile xbt_fifo_item_t item;
  smx_simcall_t simcall;

  xbt_fifo_foreach(action->simcalls, item, simcall, smx_simcall_t) {

    switch (action->state) {

      case SIMIX_DONE:
        /* do nothing, action done */
        break;

      case SIMIX_FAILED:
        TRY {
          THROWF(io_error, 0, "IO failed");
        }
	CATCH(simcall->issuer->running_ctx->exception) {
	  simcall->issuer->doexception = 1;
	}
      break;

      case SIMIX_CANCELED:
        TRY {
          THROWF(cancel_error, 0, "Canceled");
        }
	CATCH(simcall->issuer->running_ctx->exception) {
	  simcall->issuer->doexception = 1;
        }
	break;

      default:
        xbt_die("Internal error in SIMIX_io_finish: unexpected action state %d",
            action->state);
    }
    simcall->issuer->waiting_action = NULL;
    SIMIX_simcall_answer(simcall);
  }

  /* We no longer need it */
  SIMIX_io_destroy(action);
}