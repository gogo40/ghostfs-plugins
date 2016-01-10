/*
  Ghost File System - Plugins, or simply GhostFS - Plugins
  Copyright (C) 2016 Péricles Lopes Machado

  This program can be distributed under the terms of the GNU GPL.
  See the file COPYING.
*/

#include <protocol/base_protocol.h>
#include <utils.h>

#include "ghostfs_plugins.h"
#include "test/test_protocol.h"

GHOST_FS_PLUGINS_DECL void drivers_init()
{
    log("loading drivers...\n");

    register_handler(new test_protocol);
}
