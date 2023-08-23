void rageS()
{//Shadow copy frame for Rage
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "parent");
	void tRName	= getentityproperty(target, "defaultname");
	void tAniID = getentityproperty(target, "animationID");
	int tFrame	= getentityproperty(target, "animpos");
	
	if(tRName == "Axel"){
		if(tAniID == openborconstant("ANI_FREESPECIAL"))
		{
			updateframe(self, tFrame);
		} else {
			killentity(self);
		}
	}
	
	if(tRName == "Blaze"){
		if(tAniID == openborconstant("ANI_FREESPECIAL"))
		{
			updateframe(self, tFrame);
		} else {
			killentity(self);
		}
	}
	
	if(tRName == "Max"){
		if(tAniID == openborconstant("ANI_FREESPECIAL"))
		{
			updateframe(self, tFrame);
		} else {
			killentity(self);
		}
	}
	
	if(tRName == "Sammy"){
		if(tAniID == openborconstant("ANI_FREESPECIAL")||
		   tAniID == openborconstant("ANI_FOLLOW3"))
		{
			updateframe(self, tFrame);
		} else {
			killentity(self);
		}
	}
	
	if(tRName == "Barbon" || tRName == "Barbon0" || tRName == "Barbon1" || tRName == "Barbon2"){
		if(tAniID == openborconstant("ANI_FREESPECIAL3"))
		{
			updateframe(self, tFrame);
		} else {
			killentity(self);
		}
	}
	
	if(tRName == "Jet" || tRName == "Jet0" || tRName == "Jet1" || tRName == "Jet2" || tRName == "Jet3" || tRName == "Jet4" || tRName == "Jet5"){
		if(tAniID == openborconstant("ANI_FOLLOW3"))
		{
			updateframe(self, tFrame);
		} else
			
		if(tAniID == openborconstant("ANI_FOLLOW4"))
		{
			updateframe(self, tFrame);
		} else
		
		{
			killentity(self);
		}
	}
	
	if(tRName == "Zamza" || tRName == "Zamza0" || tRName == "Zamza1" || tRName == "Zamza2"){
		if(tAniID == openborconstant("ANI_FREESPECIAL6"))
		{
			updateframe(self, tFrame);
		} else {
			killentity(self);
		}
	}
	
	if(tRName == "Abadede" || tRName == "Abadede0" || tRName == "Abadede1"){
		if(tAniID == openborconstant("ANI_FREESPECIAL3"))
		{
			updateframe(self, tFrame);
		} else
			
		if(tAniID == openborconstant("ANI_FOLLOW4"))
		{
			updateframe(self, tFrame);
		} else
		
		{
			killentity(self);
		}
	}
	
	if(tRName == "R._Bear" || tRName == "Bear0" || tRName == "Bear1"){
		if(tAniID == openborconstant("ANI_FREESPECIAL3"))
		{
			updateframe(self, tFrame);
		} else {
			killentity(self);
		}
	}
	
	if(tRName == "Uranium" || tRName == "Particle0" || tRName == "Particle1" || tRName == "Particle2" || tRName == "Particle3"){
		if(tAniID == openborconstant("ANI_FREESPECIAL4"))
		{
			updateframe(self, tFrame);
		} else {
			killentity(self);
		}
	}
	
	if(tRName == "Shiva" || tRName == "Shiva0" || tRName == "Shiva1"){
		if(tAniID == openborconstant("ANI_FREESPECIAL4"))
		{
			changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
			updateframe(self, tFrame);
		} else
			
		if(tAniID == openborconstant("ANI_FREESPECIAL5"))
		{
			changeentityproperty(self, "animation", openborconstant("ANI_IDLE2"));
			updateframe(self, tFrame);
		} else
		
		if(tAniID == openborconstant("ANI_FOLLOW4"))
		{
			changeentityproperty(self, "animation", openborconstant("ANI_IDLE3"));
			updateframe(self, tFrame);
		} else

		{
			killentity(self);
		}
	}
}

void nBmap()
{//Change subject_to_wall to 0 in st7b and st8b at top floor
	void self 	= getlocalvar("self");
	int nBmap	= openborvariant("numbasemaps");
	
	if(nBmap >= 1)	
	{
		changeentityproperty(self, "subject_to_wall", 0);
	}
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