void main()
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