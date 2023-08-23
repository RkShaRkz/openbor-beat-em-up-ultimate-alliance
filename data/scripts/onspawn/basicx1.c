void main()
{
	BasicX1();
}

void BasicX1()
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

	if (iR >= 0 && iR <= 9){ 
		vRName = "Galsia0";
	} else if (iR >= 10 && iR <= 19){ 
		vRName = "Donovan0";
    } else if (iR >= 20 && iR <= 29){ 
		vRName = "Signal0";
	} else if (iR >= 30 && iR <= 44){ 
		vRName = "Galsia1";
	} else if (iR >= 45 && iR <= 59){ 
		vRName = "Donovan1";
	} else if (iR >= 60 && iR <= 74){ 
		vRName = "Signal1";
	} else if (iR >= 75 && iR <= 99){ 
		vRName = "Biker1";
    } else { 
		vRName = "Biker0";
    }	
	  
	clearspawnentry(); //Clear current spawn entry.
	setspawnentry("name", vRName); //Acquire spawn entity by name.

	vSpawn = spawn();

	bindentity(vSpawn, self, dx, dz, dy, iDir);

	return vSpawn; //Return spawn.
}