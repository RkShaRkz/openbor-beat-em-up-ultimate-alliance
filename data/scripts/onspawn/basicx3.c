void main()
{
	BasicX3();
}

void BasicX3()
{//Spawn random Enemy
	int  set 	= openborvariant("current_set");
	int  pCount = openborvariant("count_players");
	
	if(set == 0){
		if(pCount == 1){
			EnemyX(0, 0, 0);
		}else if(pCount == 2){
			EnemyX(0, 0, 0);
		}else if(pCount == 3){
			EnemyX(0, 0, 0);
			EnemyX(20, 0, 0);
		}else if(pCount == 4){
			EnemyX(0, 0, 0);
			EnemyX(20, 0, 0);
		}
	}
	
	if(set == 1){
		if(pCount == 1){
			EnemyX(0, 0, 0);
		}else if(pCount == 2){
			EnemyX(0, 0, 0);
			EnemyX(20, 0, 0);
		}else if(pCount == 3){
			EnemyX(0, 0, 0);
			EnemyX(20, 0, 0);
			EnemyX(10, 0, 15);
		}else if(pCount == 4){
			EnemyX(0, 0, 0);
			EnemyX(20, 0, 0);
			EnemyX(10, 0, 15);
			EnemyX(30, 0, 15);
		}
	}
	
	if(set == 2){
		if(pCount == 1){
			EnemyX(0, 0, 0);
		}else if(pCount == 2){
			EnemyX(0, 0, 0);
		}else if(pCount == 3){
			EnemyX(0, 0, 0);
			EnemyX(20, 0, 0);
		}else if(pCount == 4){
			EnemyX(0, 0, 0);
			EnemyX(20, 0, 0);
		}
	}
}

void EnemyX(float dx, float dy, float dz)
{	//Spawns random enemy next to caller.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
	//fY: Z location adjustment.

	void self 		= getlocalvar("self"); //Get calling entity.
	void vSpawn; 	//Spawn object.
    void vRName 	= getentityproperty(self,"defaultname"); // Get caller's real name.
	int  iDir		= getentityproperty(self,"direction"); // Get caller's direction.
	int  iR 		= rand()%99;

	if (iR >= 0 && iR <= 1){ 
		vRName = "Galsia0";
	} else if (iR >= 2 && iR <= 3){ 
		vRName = "Donovan0";
    } else if (iR >= 4 && iR <= 5){ 
		vRName = "Signal0";
	} else if (iR >= 6 && iR <= 7){ 
		vRName = "Biker0";
	} else if (iR >= 8 && iR <= 9){ 
		vRName = "Galsia1";
	} else if (iR >= 10 && iR <= 11){ 
		vRName = "Donovan1";
	} else if (iR >= 12 && iR <= 13){ 
		vRName = "Signal1";
	} else if (iR >= 14 && iR <= 15){ 
		vRName = "Biker1";
	} else if (iR >= 16 && iR <= 27){ 
		vRName = "Galsia2";
	} else if (iR >= 28 && iR <= 39){ 
		vRName = "Donovan2";
	} else if (iR >= 40 && iR <= 51){ 
		vRName = "Signal2";
	} else if (iR >= 52 && iR <= 63){ 
		vRName = "Biker2";
	} else if (iR >= 64 && iR <= 75){ 
		vRName = "Donovan3";
	} else if (iR >= 76 && iR <= 87){ 
		vRName = "Signal3";
	} else if (iR >= 88 && iR <= 99){ 
		vRName = "Biker3";	
    } else { 
		vRName = "Galsia3";
    }
	  
	clearspawnentry(); //Clear current spawn entry.
	setspawnentry("name", vRName); //Acquire spawn entity by name.

	vSpawn = spawn();

	bindentity(vSpawn, self, dx, dz, dy, iDir);

	return vSpawn; //Return spawn.
}