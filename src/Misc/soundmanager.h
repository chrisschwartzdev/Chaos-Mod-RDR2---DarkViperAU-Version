#pragma once
#include <filesystem>
#include <string>
#include <unordered_map>

class SoundManager
{
public:
    static void Initialize();
    static void PlaySound(std::string soundFile);
private:
    static std::filesystem::path GetSoundRootPath();
    static std::unordered_map<std::string, std::string> soundFilesCache;
};
