#pragma once
#include "ClientAPI.h"
#include "API_Util.h"
#include "SDL_mixer.h"

class AudioEngine
{
private:
	static bool isMuteAll;
	static int currentVolume;

public:
	static void Load()
	{
		/*int channel;

		channel = Mix_PlayChannel(1, sound, -1);
		if (channel == -1) {
			fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
		}

		Mix_Volume(-1, currentVolume);

		// Clear Audio on  close
		/*	while (Mix_Playing(channel) != 0);

		Mix_FreeChunk(sound);

		Mix_CloseAudio();*/
	}

	static void MuteAll() {
		if (!isMuteAll) {
			Mix_Volume(-1, 0);
			AudioEngine::isMuteAll = true;
		}
		else {
			Mix_Volume(-1, currentVolume);
			AudioEngine::isMuteAll = false;
		}
		
	}
};