void main()
{
	MotoX0();
}

void MotoX0()
{//Spawn random Enemy
	void self 	= getlocalvar("self"); //Get calling entity.
	
	EnemyX(0, 0, 0);
}

void EnemyX(float dx, float dy, float dz)
{	//Spawns random enemy next to caller.
	//dx: X location adjustment.
	//dz: Y location adjustment.
	//dy: Z location adjustment.

	void self 		= getlocalvar("self"); //Get calling entity.
	void vSpawn; 	//Spawn object.
    void vRName 	= getentityproperty(self,"defaultname"); // Get caller's real name.
	int  iDir		= getentityproperty(self,"direction"); // Get caller's direction.
	int  XPos 		= openborvariant("xpos");
	int  iR 		= rand()%99;
	
	if (iR >= 0 && iR <= 69){ 
		vRName = "Moto1";
		dx = dx + 120;
		iDir = 0;
	} else if(iR >= 70 && iR <= 99){ 
		vRName = "Moto2";
		dx = dx + 120;
		iDir = 0;
	} else { 
		vRName = "Moto0";
		dx = dx + 120;
		iDir = 0;
	}
	  
	clearspawnentry(); //Clear current spawn entry.
	setspawnentry("name", vRName); //Acquire spawn entity by name.

	if (iDir == 0){ //Is entity facing left?                  
          dx = -dx; //Reverse X direction to match facing.
	}

      dx = dx + XPos;  //Get X location and add adjustment.
      dy = dy + getentityproperty(self, "a"); //Get Y location and add adjustment.
      dz = dz + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn();

	changeentityproperty(vSpawn, "position", dx, dz, dy); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDir); //Set direction.

	return vSpawn; //Return spawn.
}