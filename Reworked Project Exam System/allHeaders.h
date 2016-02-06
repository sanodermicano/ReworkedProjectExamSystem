#pragma once
#pragma warning(disable : 4996)
#ifndef allHeaders_h
#define allHeaders_h


#include "main.h"
#include "Tools.h"
#include "Insturctor.h"
#include "Questions.h"
#include "TF.h"
#include "Multiple.h"
#include "Student.h"
#include "User.h"
#include <time.h>
#include <stdlib.h>
#include <sapi.h>
#include <atlbase.h>
#include <sphelper.h>
#include <sstream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5\bitmap.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\keyboard.h>
#include <allegro5\bitmap.h>
#include <allegro5\bitmap_draw.h>
#include<allegro5\allegro_ttf.h>
#include<amp.h>
#define FPS 20
#endif
unsigned short AI(char board[][3]);
void tictac(bool isSpecialCase);
int survivroll();
int voiceRecognition(string Qtext);
void speak(string Qtext,int sleepTime);