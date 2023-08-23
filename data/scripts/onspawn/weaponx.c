void main()
{
	WeaponX();
}

void WeaponX()
{//Spawn random Weapon
	int  pCount = openborvariant("count_players");
	
	if(pCount == 1){
		spawnX(0, 0, 0);
	}else if(pCount == 2){
		spawnX(0, 0, 0);
		spawnX(50, 0, 0);
	}else if(pCount == 3){
		spawnX(0, 0, 0);
		spawnX(50, 0, 0);
		spawnX(25, 0, 15);
	}else if(pCount == 4){
		spawnX(0, 0, 0);
		spawnX(50, 0, 0);
		spawnX(25, 0, 15);
		spawnX(75, 0, 15);
	}
}

void spawnX(float dx, float dy, float dz)
{	//Spawns random weapon next to caller.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
	//fY: Z location adjustment.

	void self 		= getlocalvar("self"); //Get calling entity.
	void vSpawn; 	//Spawn object.
    void vRName 	= getentityproperty(self,"defaultname"); // Get caller's real name.
	int  iDir		= getentityproperty(self,"direction"); // Get caller's direction.
	int  iR 		= rand()%99;

	if (iR >= 0 && iR <= 39){ 
		vRName = "Kunai";
	} else if (iR >= 40 && iR <= 79){ 
		vRName = "Pipe";
	} else if (iR >= 80 && iR <= 99){ 
		vRName = "Sword";
    } else { 
		vRName = "Knife";
    }
	  
	clearspawnentry(); //Clear current spawn entry.
	setspawnentry("name", vRName); //Acquire spawn entity by name.

	vSpawn = spawn();

	bindentity(vSpawn, self, dx, dz, dy, iDir);

	return vSpawn; //Return spawn.
}