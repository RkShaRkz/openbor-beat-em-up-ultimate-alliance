#import "data/scripts/spawnlevel/music_all.c"

void main()
{
	setG();
	stageIntro();
	ragefull_bar1();
	ragefull_bar2();
	ragefull_bar3();
	ragefull_bar4();
	bar_mask1();
	bar_mask2();
	bar_mask3();
	bar_mask4();
	bar_mask1b();
	bar_mask2b();
	bar_mask3b();
	bar_mask4b();
}

void ragefull_bar1()
{//Spawn RageFull Bar
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "ragefull_bar1"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 2, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void bar_mask1()
{//Spawn Alpha Mask for player HUD
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "bar_mask1"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 2, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void bar_mask1b()
{//Spawn Alpha Mask for player HUD
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "bar_mask1b"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 2, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void ragefull_bar2()
{//Spawn RageFull Bar
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "ragefull_bar2"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 122, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void bar_mask2()
{//Spawn Alpha Mask for player HUD
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "bar_mask2"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 122, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void bar_mask2b()
{//Spawn Alpha Mask for player HUD
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "bar_mask2b"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 122, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void ragefull_bar3()
{//Spawn RageFull Bar
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "ragefull_bar3"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 242, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void bar_mask3()
{//Spawn Alpha Mask for player HUD
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "bar_mask3"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 242, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void bar_mask3b()
{//Spawn Alpha Mask for player HUD
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "bar_mask3b"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 242, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void ragefull_bar4()
{//Spawn RageFull Bar
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "ragefull_bar4"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 362, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void bar_mask4()
{//Spawn Alpha Mask for player HUD
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "bar_mask4"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 362, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void bar_mask4b()
{//Spawn Alpha Mask for player HUD
	void vSpawn;
	
	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "bar_mask4b"); //Acquire spawn entity by name.
	
	vSpawn = spawn();
	
	changeentityproperty(vSpawn, "position", 362, 0, 0); //Set spawn location.
	changeentityproperty(vSpawn, "direction", 1); //Set spawn direction.
	
	return vSpawn; //Return vSpawn.
}

void setG()
{// Set all global variables
	int ko1 = getglobalvar("ko1");
	int ko2 = getglobalvar("ko2");
	int ko3 = getglobalvar("ko3");
	int ko4 = getglobalvar("ko4");

	if(ko1 == NULL()){
		setglobalvar("ko1",0);
	}else{
		setglobalvar("ko1",ko1);
	}
	
	if(ko2 == NULL()){
		setglobalvar("ko2",0);
	}else{
		setglobalvar("ko2",ko2);
	}
	
	if(ko3 == NULL()){
		setglobalvar("ko3",0);
	}else{
		setglobalvar("ko3",ko3);
	}
	
	if(ko4 == NULL()){
		setglobalvar("ko4",0);
	}else{
		setglobalvar("ko4",ko4);
	}
}

void stageIntro()
{// Play intro scene in each stage
	int set 	= openborvariant("current_set");
	int stage 	= openborvariant("current_stage");
	int level 	= openborvariant("current_level");

	if(set == 0){
		if(stage == 1){
			if(level == 0){
				musicSt1();
				playwebm("data/scenes/st1.webm", 1);
			}
		}
		if(stage == 2){
			if(level == 3){
				musicSt2();
				playwebm("data/scenes/st2.webm", 1);
			}
			if(level == 5){
				musicSt2();
			}
		}
		if(stage == 3){
			if(level == 6){
				playwebm("data/scenes/st3.webm", 1);
			}
		}
		if(stage == 4){
			if(level == 13){
				playwebm("data/scenes/st4.webm", 1);
			}
		}
		if(stage == 5){
			if(level == 17){
				musicSt5();
				playwebm("data/scenes/st5.webm", 1);
			}
			if(level == 18){
				musicSt5();
			}
			if(level == 19){
				musicSt5();
			}
		}
		if(stage == 6){
			if(level == 20){
				musicSt6a();
				playwebm("data/scenes/st6.webm", 1);
			}
			if(level == 21){
				musicSt6b();
			}
		}
		if(stage == 7){
			if(level == 22){
				musicSt7();
				playwebm("data/scenes/st7.webm", 1);
			}
		}
		if(stage == 8){
			if(level == 24){
				musicSt8();
				playwebm("data/scenes/st8.webm", 1);
			}
			if(level == 25){
				musicSt8();
			}
		}
	}
	
	if(set == 1){
		if(stage == 1){
			if(level == 0){
				musicSt1();
				playwebm("data/scenes/st1.webm", 1);
			}
		}
		if(stage == 2){
			if(level == 3){
				musicSt2();
				playwebm("data/scenes/st2.webm", 1);
			}
			if(level == 5){
				musicSt2();
			}
		}
		if(stage == 3){
			if(level == 6){
				playwebm("data/scenes/st3.webm", 1);
			}
		}
		if(stage == 4){
			if(level == 13){
				playwebm("data/scenes/st4.webm", 1);
			}
		}
		if(stage == 5){
			if(level == 17){
				musicSt5();
				playwebm("data/scenes/st5.webm", 1);
			}
			if(level == 18){
				musicSt5();
			}
			if(level == 19){
				musicSt5();
			}
		}
		if(stage == 6){
			if(level == 20){
				musicSt6a();
				playwebm("data/scenes/st6.webm", 1);
			}
			if(level == 21){
				musicSt6b();
			}
		}
		if(stage == 7){
			if(level == 22){
				musicSt7();
				playwebm("data/scenes/st7.webm", 1);
			}
		}
		if(stage == 8){
			if(level == 24){
				musicSt8();
				playwebm("data/scenes/st8.webm", 1);
			}
			if(level == 25){
				musicSt8();
			}
		}
	}
	
	if(set == 2){
		if(stage == 1){
			if(level == 0){
				musicBoss();
				playwebm("data/scenes/survival.webm", 1);
			}
		}
	}
	
	if(set == 3){
		if(stage == 1){
			if(level == 0){
				musicBoss();
				playwebm("data/scenes/syndicate.webm", 1);
			}
		}
	}
}