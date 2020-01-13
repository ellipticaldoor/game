#pragma once
#include <pch.hpp>

std::string readTextFile(const std::string &fileName) {
  std::ifstream ifs(
    fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
  std::ifstream::pos_type fileSize = ifs.tellg();
  ifs.seekg(0, std::ios::beg);

  std::vector<char> bytes(fileSize);
  ifs.read(&bytes[0], fileSize);

  return std::string(&bytes[0], fileSize);
}
