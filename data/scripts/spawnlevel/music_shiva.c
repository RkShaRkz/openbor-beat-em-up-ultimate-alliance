void main()
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