void musicBoss()
{//Play random musics
	void music1 = "data/music/boss1.ogg";
	void music2 = "data/music/boss2.ogg";
	void music3 = "data/music/boss3.ogg";
	void music;
	int  iR 	= rand()%99;

	if(iR >= 0 && iR <= 49){
		music = music1;
	}else if(iR >= 50 && iR <= 98){
		music = music2;
	}else{
		music = music3;
	}
		
	playmusic(music, 1);
}

void musicMrx()
{//Play defined music
	void music = "data/music/mrx.ogg";

	playmusic(music, 1);
}

void musicShiva()
{//Play random musics
	void music1 = "data/music/shiva1.ogg";
	void music2 = "data/music/shiva2.ogg";
	void music;
	int  iR 	= rand()%99;

	if(iR >= 0 && iR <= 98){
		music = music2;
	}else{
		music = music1;
	}
		
	playmusic(music, 1);
}

void musicSt1()
{//Play random musics
	void music 	= "data/music/st1b.ogg";
	int  iR 	= rand()%99;

	if(iR >= 50 && iR <= 99){
		playmusic(music, 1);
	}
} 

void musicSt2()
{//Play random musics
	void music = "data/music/st2b.ogg";
	int  iR 	= rand()%99;

	if(iR >= 50 && iR <= 99){
		playmusic(music, 1);
	}
}

void musicSt5()
{//Play random musics
	void music = "data/music/st5b.ogg";
	int  iR 	= rand()%99;

	if(iR >= 50 && iR <= 99){
		playmusic(music, 1);
	}
}

void musicSt6a()
{//Play random musics
	void music = "data/music/st6b.ogg";
	int  iR 	= rand()%99;

	if(iR >= 50 && iR <= 99){
		playmusic(music, 1);
	}
}

void musicSt6b()
{//Play random musics
	void music = "data/music/st6d.ogg";
	int  iR 	= rand()%99;

	if(iR >= 50 && iR <= 99){
		playmusic(music, 1);
	}
}

void musicSt7()
{//Play random musics
	void music = "data/music/st7b.ogg";
	int  iR 	= rand()%99;

	if(iR >= 50 && iR <= 99){
		playmusic(music, 1);
	}
}

void musicSt8()
{//Play random musics
	void music = "data/music/st8b.ogg";
	int  iR 	= rand()%99;

	if(iR >= 50 && iR <= 99){
		playmusic(music, 1);
	}
}