/*
  Ghost File System - Plugins, or simply GhostFS - Plugins
  Copyright (C) 2016 Péricles Lopes Machado

  This program can be distributed under the terms of the GNU GPL.
  See the file COPYING.
*/

#ifndef GHOSTFS_PLUGINS_H
#define GHOSTFS_PLUGINS_H

#include <protocol/load_drivers.h>

#if defined(_WIN32) || defined(WIN32)
#ifdef LIB_STATIC
#define GHOST_FS_PLUGINS_DECL GHOSTFS_EXT_LIB_DECL
#else
#ifdef GHOST_FS_PLUGINS_EXPORT
#define GHOST_FS_PLUGINS_DECL GHOSTFS_EXT_LIB_DECL __declspec(dllexport)
#else
#define GHOST_FS_PLUGINS_DECL GHOSTFS_EXT_LIB_DECL __declspec(dllimport)
#endif
#endif
#else
#define GHOST_FS_PLUGINS_DECL GHOSTFS_EXT_LIB_DECL
#endif

#endif // GHOSTFS_PLUGINS_H
