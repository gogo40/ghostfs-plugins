/*
  Ghost File System - Plugins, or simply GhostFS - Plugins
  Copyright (C) 2016 Péricles Lopes Machado

  This program can be distributed under the terms of the GNU GPL.
  See the file COPYING.
*/

#include "test/test_protocol.h"
#include <utils.h>

bool test_protocol::is_url_valid(const char *url)
{
    log("verify if url is valid using test protocol...");
    return true;
}

uint64_t test_protocol::get_content_length_for_url(const char *url)
{
    log("get content length for url using test protocol...");
    return 10;
}

void test_protocol::get_block(const char *url, size_t block_id, size_t block_size, const std::unordered_map<std::string, std::string> &attributes, char *data)
{
    log("get block using test protocol...");
}
