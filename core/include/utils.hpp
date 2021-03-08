#include <json.hpp>
#include <curl/curl.h>

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include <stdio.h>

#define API_AGENT "EmreTech"
using json = nlohmann::json;

void downloadFile(const char *url, const char *filename);

std::string getLatestTag(std::string url);
std::string getLatestDownload(std::string url);