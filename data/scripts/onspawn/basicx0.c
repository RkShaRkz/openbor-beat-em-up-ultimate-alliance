void main()
{
	BasicX0();
}

void BasicX0()
{//Spawn random Enemy
	int  pCount = openborvariant("count_players");
	
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

	if (iR >= 0 && iR <= 49){ 
		vRName = "Donovan0";
	} else if (iR >= 50 && iR <= 99){ 
		vRName = "Signal0";
    } else { 
		vRName = "Galsia0";
    }
	  
	clearspawnentry(); //Clear current spawn entry.
	setspawnentry("name", vRName); //Acquire spawn entity by name.

	vSpawn = spawn();

	bindentity(vSpawn, self, dx, dz, dy, iDir);

	return vSpawn; //Return spawn.
}