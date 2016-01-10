/*
  Ghost File System - Plugins, or simply GhostFS - Plugins
  Copyright (C) 2016 Péricles Lopes Machado

  This program can be distributed under the terms of the GNU GPL.
  See the file COPYING.
*/

#ifndef TEST_PROTOCOL_H
#define TEST_PROTOCOL_H

#include <protocol/base_protocol.h>

#include "ghostfs_plugins.h"

GHOST_FS_PLUGINS_DECL class test_protocol : public base_protocol {
    virtual const char* name() { return "test"; }

    virtual bool is_url_valid(const char* url);
    virtual uint64_t get_content_length_for_url(const char *url);
    virtual void get_block(const char *url, size_t block_id, size_t block_size,
        const std::unordered_map<std::string, std::string>& attributes, char* data);
};

#endif // TEST_PROTOCOL_H
