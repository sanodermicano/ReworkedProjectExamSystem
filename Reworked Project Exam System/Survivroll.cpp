#include "allHeaders.h"
#define MOVEMENTSPEED 10

class gameObject 
{
private:

public:
	ALLEGRO_BITMAP *bitmap;
	float x, y;
	gameObject();
	~gameObject();
};

bool collision(float x, float y, float ex, float ey, float width, float height) 
{
	if (x + width < ex || x > ex + width || y + height < ey || y > ey + height) return false;
	else return true;
}

gameObject::gameObject() 
{
	x = 300.0 + (rand() % 600);
	y = -500.0 + (rand() % 2500);
}

gameObject::~gameObject() 
{
	al_destroy_bitmap(bitmap);
}

int survivroll() 
{
	srand(time(NULL));
	bool done = false, done1 = false, draw = true, lost = false;
	short animation = 0, count = 0, count2 = 300, speeder = 0, ms = MOVEMENTSPEED, tostart = 0, randomSong = rand() % 3;//hey there
	const short fps = 60;
	int score = 0;
	float sourceX = 0, sourceY = 0, px = 350, py = 550;
	Tools tool;
	tool.sendto("database/highscore.txt");
	int highscore = tool.recieveFromInt("database/highscore.txt");
	if (highscore < 0) highscore = 0;

	gameObject enemies1, enemies2, enemies3, enemies4;



	if (!al_init()) return -1;
	ALLEGRO_DISPLAY *display = al_create_display(800, 600);
	if (!display) return -1;

	al_set_window_title(display, "Survivroll");
	al_set_display_flag(display, ALLEGRO_MAXIMIZED, true);

	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_KEYBOARD_STATE keystate;

	ALLEGRO_COLOR blue = al_map_rgb(100, 100, 255);
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR gold = al_map_rgb(230, 230, 0);
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);


	ALLEGRO_BITMAP *player = al_load_bitmap("ball/ball-blueSprite.png");
	ALLEGRO_BITMAP *gameicon = al_load_bitmap("ball/ball-blue1.png");
	ALLEGRO_BITMAP *gameover = al_load_bitmap("game over.png");
	ALLEGRO_BITMAP *mainmenu = al_load_bitmap("menu.png");

	//al_set_display_icon(display,gameicon);

	ALLEGRO_FONT *font = al_load_ttf_font("Marlboro.ttf", 24, NULL);
	ALLEGRO_FONT *font75 = al_load_ttf_font("Marlboro.ttf", 75, NULL);



	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_get_standard_path(ALLEGRO_EXENAME_PATH);
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / fps);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_hide_mouse_cursor(display);


	al_start_timer(timer);
	enemies1.bitmap = al_load_bitmap("ball/1.png");
	enemies2.bitmap = al_load_bitmap("ball/2.png");
	enemies3.bitmap = al_load_bitmap("ball/3.png");
	enemies4.bitmap = al_load_bitmap("ball/3.png");

	system("cls");

	//unsigned int highscore = 0;
	//game loop___________________________________________________________________________________________________________
	while (done1 == false) 
	{
		ALLEGRO_EVENT mainevent;
		al_wait_for_event(event_queue, &mainevent);
		if (lost == false) {
			al_draw_bitmap(mainmenu, 0, 0, NULL);
			al_flip_display();
			if (mainevent.type == ALLEGRO_EVENT_KEY_UP) 
			{
				done = true;
				tostart = 0;
			}
			if (mainevent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) done = false, done1 = true;
			if (mainevent.type == ALLEGRO_EVENT_KEY_DOWN) if (mainevent.keyboard.keycode == ALLEGRO_KEY_ESCAPE) done = false, done1 = true;//look
		}

		while (done == true) {//put another while to add main menu and game over screens.
			ALLEGRO_EVENT events;
			al_wait_for_event(event_queue, &events);
			al_get_keyboard_state(&keystate);

			if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) done = false, done1 = true;
			if (events.type == ALLEGRO_EVENT_KEY_DOWN) if (events.keyboard.keycode == ALLEGRO_KEY_ESCAPE) done = false, done1 = true;//look

			if (events.type == ALLEGRO_EVENT_KEY_DOWN) if (events.keyboard.keycode == ALLEGRO_KEY_ENTER) done = false;//look

																													  //timer
			if (events.type == ALLEGRO_EVENT_TIMER) 
			{
				al_get_keyboard_state(&keystate);
				if (al_key_down(&keystate, ALLEGRO_KEY_A))px -= ms;
				else if (al_key_down(&keystate, ALLEGRO_KEY_D))px += ms;
				draw = true;
			}
			//animator
			animation++;
			if (animation>5) animation = 0;
			switch (animation) 
			{
			case 0:
				sourceX = 0;
				sourceY = 0;
				break;
			case 1:
				sourceX = 50;
				sourceY = 0;
				break;
			case 2:
				sourceX = 100;
				sourceY = 0;
				break;
			case 3:
				sourceX = 0;
				sourceY = 50;
				break;
			case 4:
				sourceX = 50;
				sourceY = 50;
				break;
			case 5:
				sourceX = 100;
				sourceY = 50;
				break;
			}

			enemies1.y += ms;
			enemies2.y += ms;
			enemies3.y += ms*1.25;
			enemies4.y += ms*1.25;
			//enemies3.x+=-10+rand()%10;
			//enemies4.x+=-10+rand()%10;

			if (enemies1.y > 700) 
			{
				enemies1.y = -2000 + (rand() % -2000);
				enemies1.x = 250 + (rand() % 250);
			}
			if (enemies2.y > 700) 
			{
				enemies2.y = -2000 + (rand() % -2000);
				enemies2.x = 250 + (rand() % 250);
			}
			if (enemies3.y > 700) 
			{
				enemies3.y = -2000 + (rand() % -500);
				enemies3.x = 50 + (rand() % 750);
			}
			if (enemies4.y > 700) 
			{
				enemies4.y = -2000 + (rand() % -500);
				enemies4.x = 50 + (rand() % 750);
			}

			//lines movement
			count += ms;
			if (count > 600) count = 0;
			count2 += ms;
			if (count2 > 600) count2 = 0;

			//ball limit
			if (px>730) px -= ms;
			if (px<25) px += ms;

			//ms bonus
			speeder++;//every 10 seconds the movement speed gets faster.
			if (speeder > 600) 
			{
				ms++;
				speeder = 0;
			}

			//game over
			if (tostart < 60) tostart++;
			else 
			{
				lost = collision(px, py, enemies1.x, enemies1.y, 50, 50);
				if (lost == true) 
				{
					done = false;
					break;
				}
				lost = collision(px, py, enemies2.x, enemies2.y, 50, 50);
				if (lost == true) 
				{
					done = false;
					break;
				}
				lost = collision(px, py, enemies3.x, enemies3.y, 50, 50);
				if (lost == true) 
				{
					done = false;
					break;
				}
				lost = collision(px, py, enemies4.x, enemies4.y, 50, 50);
				if (lost == true) 
				{
					done = false;
					break;
				}
			}
			score += ms;

			if (highscore<score) highscore = score;


			if (draw) 
			{
				al_draw_filled_triangle(30, 600, 770, 600, 400, -500, blue);
				al_draw_line(0, count, 800, count, black, 5);
				al_draw_line(0, count2, 800, count2, black, 5);
				al_draw_bitmap(enemies1.bitmap, enemies1.x, enemies1.y, NULL);
				al_draw_bitmap(enemies2.bitmap, enemies2.x, enemies2.y, NULL);
				al_draw_bitmap_region(enemies3.bitmap, sourceX, sourceY, 50, 50, enemies3.x, enemies3.y, NULL);
				al_draw_bitmap_region(enemies4.bitmap, sourceX, sourceY, 50, 50, enemies4.x, enemies4.y, NULL);
				al_draw_bitmap_region(player, sourceX, sourceY, 50, 50, px, py, NULL);

				al_draw_textf(font, white, 15, 50, NULL, "Score: %i", score);//yay!!!
				al_draw_textf(font, gold, 15, 20, NULL, "High Score: %i", highscore);

				draw = false;
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
		}
		if (lost == true) 
		{

			al_draw_bitmap(gameover, 0, 0, NULL);
			al_draw_textf(font75, gold, 50, 475, NULL, "Final Score = %i", score);
			al_flip_display();
			if (mainevent.type == ALLEGRO_EVENT_KEY_DOWN)
				if (mainevent.keyboard.keycode == ALLEGRO_KEY_R || mainevent.keyboard.keycode == ALLEGRO_KEY_SPACE) {
					done = true;
					lost = false;
					tostart = -120;
					score = 0;
				}
			if (mainevent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) done = false, done1 = true;
			if (mainevent.type == ALLEGRO_EVENT_KEY_DOWN) if (mainevent.keyboard.keycode == ALLEGRO_KEY_ESCAPE) done = false, done1 = true;
			ms = MOVEMENTSPEED;
		}
	}
	//game loop___________________________________________________________________________________________________________
	if (highscore>=score) 
	{
		tool.sendto("database/highscore.txt",highscore);
	}
	al_destroy_display(display);
	al_destroy_bitmap(player);
	al_destroy_bitmap(mainmenu);
	al_destroy_bitmap(gameover);
	al_destroy_font(font);
	player = 0;

	return 0;
}