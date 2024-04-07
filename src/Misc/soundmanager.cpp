#include "soundmanager.h"
#include <iostream>
#include <SFML/Audio.hpp>

void SoundManager::Initialize()
{
	try
	{
		auto path = GetSoundRootPath();
		
		// Iterate through all files in the directory
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			// Check if the file is an MP3 file
			if (entry.path().extension() == ".mp3")
			{
				// Add the file path to the unordered map with the file name as key
				soundFilesCache[entry.path().filename().string()] = entry.path().string();
			}
		}
	}
	catch (const std::filesystem::filesystem_error& ex)
	{
		// ignore error i guess
	}
}

void SoundManager::PlaySound(std::string soundFile)
{
	auto it = soundFilesCache.find(soundFile);
	if (it != soundFilesCache.end())
	{
		auto filePath = it->second;
		sf::SoundBuffer buffer;
		if (!buffer.loadFromFile(filePath))
			return;

		sf::Sound sound(buffer);
		sound.play();
	}
}

std::filesystem::path SoundManager::GetSoundRootPath()
{
	return std::filesystem::current_path() / L"ChaosMod" / L"Sounds";
}
