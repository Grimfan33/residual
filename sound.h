// Residual - Virtual machine to run LucasArts' 3D adventure games
// Copyright (C) 2003-2004 The ScummVM-Residual Team (www.scummvm.org)
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA

#ifndef SOUND_H
#define SOUND_H

#include "bits.h"
#include "resource.h"
#include "mixer/audiostream.h"
#include <list>

class Sound : public Resource {
public:
	Sound(const char *filename, const char *data, int len);
	~Sound();

	bool done() const { return _currPos >= _numSamples; }
	bool hasReachedPos(int position) const { return _currPos >= position; }
	int  getCurrPos() const {return _currPos;}

private:
	int _numSamples, _numChannels, _currPos;
	int16 *_samples;

	static void init();

	void reset();
	void mix(int16 *data, int samples);

	friend class Mixer;
};

class Mixer : public AudioStream {
public:
	static Mixer *instance();

	void start();

	void playVoice(Sound *s);
	void playSfx(Sound *s);
	void stopSfx(Sound *s);
	void stopVoice(Sound *s);
	void setImuseState(int state);
	void setImuseSeq(int seq);

	Sound *findSfx(const char *filename);
	bool voicePlaying() const;

	void getAudio(int16 *data, int numSamples);

	bool isStereo() const { return true; };
	bool endOfData() const { return false; }
	int getRate() const { return 22050; };
	int readBuffer(int16 *data, const int numSamples) {
		getAudio(data, numSamples);
		return numSamples;
	}

private:
	Mixer();
	~Mixer() { }

	static Mixer *_instance;
	typedef std::list<ResPtr<Sound> > SoundList;
	SoundList _voiceSounds, _sfxSounds;
	ResPtr<Sound> _musicSound, _seqSound;
};

#endif
