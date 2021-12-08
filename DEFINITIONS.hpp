#pragma once

#define SCREEN_WIDTH 768 // Ширина экрана
#define	SCREEN_HEIGHT 1024 // Высота экрана

#define SPLASH_STATE_SHOW_TIME 3.0 // Как долго мы будем видеть экран-заставку 

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png" // Ставим задний фон экрана-заставки
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sky.png" // Ставим задний фон главного меню
#define GAME_BACKGROUND_FILEPATH "Resources/res/sky.png" // Ставим задний фон непосредственно игры
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/sky.png" // Ставим задний фон экрана окончания игры

#define GAME_TITLE_FILEPATH "Resources/res/title.png" // Картинка - название
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png" // Картинка - кнопка для старта

#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png" // Труба сверху
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png" // Труба снизу

#define LAND_FILEPATH "Resources/res/Land.png" // Картинка земли

#define BIRD_FRAME_1_FILEPATH "Resources/res/bird-01.png" // Картинки для анимации птицы
#define BIRD_FRAME_2_FILEPATH "Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/bird-04.png"

#define PIPE_MOVEMENT_SPEED 200.0f // Скорость движения труб
#define PIPE_SPAWN_FREQUENCY 1.5f // Частота спавна труб

#define BIRD_ANIMATION_DURATION 0.4f // Как долго будет длиться анимация

#define BIRD_STATE_STILL 1 // Птица летит 
#define BIRD_STATE_FALLING 2 // Птица падает
#define BIRD_STATE_FLYING 3 // Птица поднимается 

#define GRAVITY 350.0f // Гравитация, если птица не летит, то она будет падать вниз
#define FLYING_SPEED 350.0f // Скорость полета птицы

#define FLYING_DURATION 0.25f // Длительность каждого взлета птицы при нажатии

#define ROTATION_SPEED 100.0f // Скорость вращения 

enum GameStates // Состояния игры
{
	eReady, // Состояние перед игрой
	ePlaying, // Игровое состояние после нажатия на кнопку мыши
	eGameOver // Конец игры
};