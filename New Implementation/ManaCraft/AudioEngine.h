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
		int audio_rate = 22050;
		Uint16 audio_format = AUDIO_S16SYS;
		int audio_channels = 2;
		int audio_buffers = 4096;

		SDL_Init(SDL_INIT_AUDIO);

		if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)) {
			printf("Unable to open audio!\n");
			exit(1);
		}

		Mix_Chunk *sound = NULL;

		sound = Mix_LoadWAV("Resources/Audios/Menu/Bg.ogg");
		//sound = Mix_LoadWAV("Resources/Audios/test.wav");
		if (sound == NULL) {
			fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
		}

		int channel;

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