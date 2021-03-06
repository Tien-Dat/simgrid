/* Copyright (c) 2015. The SimGrid Team.
 * All rights reserved.                                                     */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <xbt/log.h>

#include "mc_protocol.h"
#include "mc_client.h"

extern "C" {

XBT_LOG_NEW_DEFAULT_SUBCATEGORY(mc_protocol, mc, "Generic MC protocol logic");

int MC_protocol_send(int socket, const void* message, size_t size)
{
  XBT_DEBUG("Protocol [%s] send %s",
    MC_mode_name(mc_mode),
    MC_message_type_name(*(e_mc_message_type*) message));

  while (send(socket, message, size, 0) == -1) {
    if (errno == EINTR)
      continue;
    else
      return errno;
  }
  return 0;
}

int MC_protocol_send_simple_message(int socket, e_mc_message_type type)
{
  s_mc_message_t message;
  message.type = type;
  return MC_protocol_send(socket, &message, sizeof(message));
}

int MC_protocol_hello(int socket)
{
  int e;
  if ((e = MC_protocol_send_simple_message(socket, MC_MESSAGE_HELLO)) != 0) {
    XBT_ERROR("Could not send HELLO message");
    return 1;
  }

  s_mc_message_t message;
  message.type = MC_MESSAGE_NONE;

  ssize_t s;
  while ((s = MC_receive_message(socket, &message, sizeof(message), 0)) == -1) {
    if (errno == EINTR)
      continue;
    else {
      XBT_ERROR("Could not receive HELLO message");
      return 2;
    }
  }
  if ((size_t) s < sizeof(message) || message.type != MC_MESSAGE_HELLO) {
    XBT_ERROR("Did not receive suitable HELLO message. Who are you?");
    return 3;
  }

  return 0;
}

ssize_t MC_receive_message(int socket, void* message, size_t size, int options)
{
  int res = recv(socket, message, size, options);
  if (res != -1) {
    XBT_DEBUG("Protocol [%s] received %s",
      MC_mode_name(mc_mode),
      MC_message_type_name(*(e_mc_message_type*) message));
  }
  return res;
}

const char* MC_message_type_name(e_mc_message_type type)
{
  switch(type) {
  case MC_MESSAGE_NONE:
    return "NONE";
  case MC_MESSAGE_HELLO:
    return "HELLO";
  case MC_MESSAGE_CONTINUE:
    return "CONTINUE";
  case MC_MESSAGE_IGNORE_HEAP:
    return "IGNORE_HEAP";
  case MC_MESSAGE_UNIGNORE_HEAP:
    return "UNIGNORE_HEAP";
  case MC_MESSAGE_IGNORE_MEMORY:
    return "IGNORE_MEMORY";
  case MC_MESSAGE_STACK_REGION:
    return "STACK_REGION";
  case MC_MESSAGE_REGISTER_SYMBOL:
    return "REGISTER_SYMBOL";
  case MC_MESSAGE_DEADLOCK_CHECK:
    return "DEADLOCK_CHECK";
  case MC_MESSAGE_DEADLOCK_CHECK_REPLY:
    return "DEADLOCK_CHECK_REPLY";
  case MC_MESSAGE_WAITING:
    return "WAITING";
  case MC_MESSAGE_SIMCALL_HANDLE:
    return "SIMCALL_HANDLE";
  case MC_MESSAGE_ASSERTION_FAILED:
    return "ASSERTION_FAILED";
  default:
    return "?";
  }
}

const char* MC_mode_name(e_mc_mode_t mode)
{
  switch(mode) {
  case MC_MODE_NONE:
    return "NONE";
  case MC_MODE_CLIENT:
    return "CLIENT";
  case MC_MODE_SERVER:
    return "SERVER";
  default:
    return "?";
  }
}

}
