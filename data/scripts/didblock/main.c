void guardCost()
{//Default Guard Cost if block
    void self 	= getlocalvar("self");
	int Gp		= getentityproperty(self,"guardpoints");

	changeentityproperty(self, "guardpoints", Gp-6 );
}

void spawn01(void vName, float fX, float fY, float fZ)
{	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.

	void self 		= getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Acquire spawn entity by name.

	if(iDirection == 0){ //Is entity facing left?                  
        fX = -fX; //Reverse X direction to match facing.
	}

    fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
    fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
    fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    return vSpawn; //Return spawn.
}

void spawnbind(void Name, float dx, float dy, float dz)
{// Spawn and bind other entity
	void self = getlocalvar("self");
	void vSpawn;

	vSpawn = spawn01(Name, dx, dy, 0);

	bindentity(vSpawn, self, dx, dz, dy, 0, 0);
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.

	return vSpawn; //Return vSpawn.
}