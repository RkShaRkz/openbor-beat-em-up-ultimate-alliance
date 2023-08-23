void main()
{//Script for add a second hitflash
	void self 		= getlocalvar("self");
	void target		= getentityproperty(self, "opponent");
	void tName		= getentityproperty(target, "defaultname");
	void tAnID		= getentityproperty(target, "animationID");
	void Frame		= getentityproperty(target, "animpos");
	
	if(tName == "Axel"){
		if(tAnID == openborconstant("ANI_FREESPECIAL")){
			if(Frame >= 6){
				spawn01("axel_burn", 0, 50, 1);
			}
		}
	}
	
	if(tName == "Blaze"){
		if(tAnID == openborconstant("ANI_FREESPECIAL")){
			if(Frame >= 9){
				spawn01("shock", 0, 50, 1);
			}
		}
	}
	
	if(tName == "Max"){
		if(tAnID == openborconstant("ANI_FREESPECIAL")){
			if(Frame >= 11){
				spawn01("impact", 0, 50, 1);
			}
		}
	}
	
	if(tName == "Bigben_FireP"){
		if(tAnID == openborconstant("ANI_IDLE")){
			if(Frame >= 0){
				spawn01("burn", 10, 60, 1);
			}
		}
	}
	
	if(tName == "Bigben_Fire"){
		if(tAnID == openborconstant("ANI_IDLE")){
			if(Frame >= 0){
				spawn01("burn", 10, 60, 1);
			}
		}
	}
	
	if(tName == "Jet"){
		if(tAnID == openborconstant("ANI_SPECIAL")){
			if(Frame >= 0){
				spawn01("burn", 0, 50, 1);
			}
		}
	}
	
	if(tName == "Jet0" || tName == "Jet1" || tName == "Jet2" || tName == "Jet3" || tName == "Jet4" || tName == "Jet5"){
		if(tAnID == openborconstant("ANI_SPECIAL") || tAnID == openborconstant("ANI_SPECIAL2")){
			if(Frame >= 0){
				spawn01("burn", 0, 50, 1);
			}
		}
	}
	
	if(tName == "Abadede" || tName == "Abadede0" || tName == "Abadede1"){
		if(tAnID == openborconstant("ANI_FOLLOW4")){
			if(Frame >= 10){
				spawn01("impact", 0, 50, 1);
			}
		}
	}
	
	if(tName == "R._Bear" || tName == "Bear0" || tName == "Bear1"){
		if(tAnID == openborconstant("ANI_FREESPECIAL3")){
			if(Frame >= 3){
				spawn01("impact", 0, 50, 1);
			}
		}
	}
	
	if(tName == "Uranium"){
		if(tAnID == openborconstant("ANI_SPECIAL") || tAnID == openborconstant("ANI_SPECIAL2")){
			if(Frame >= 0){
				spawn01("shock", 0, 50, 1);
			}
		}
	}
	
	if(tName == "Particle0" || tName == "Particle1" || tName == "Particle2" || tName == "Particle3"){
		if(tAnID == openborconstant("ANI_FREESPECIAL") || tAnID == openborconstant("ANI_SPECIAL") || tAnID == openborconstant("ANI_SPECIAL2")){
			if(Frame >= 0){
				spawn01("shock", 0, 50, 1);
			}
		}
	}
	
	if(tName == "Uranium" || tName == "Particle0" || tName == "Particle1" || tName == "Particle2" || tName == "Particle3"){
		if(tAnID == openborconstant("ANI_FREESPECIAL4")){
			if(Frame >= 0){
				spawn01("laserhit", 0, 50, 1);
			}
		}
	}
	
	if(tName == "Shiva" || tName == "Shiva0" || tName == "Shiva1"){
		if(tAnID == openborconstant("ANI_FREESPECIAL4")){
			if(Frame >= 4){
				spawn01("axel_burn", 0, 50, 1);
			}
		}
	}
	
	if(tName == "Shiva" || tName == "Shiva0" || tName == "Shiva1"){
		if(tAnID == openborconstant("ANI_FOLLOW4")){
			if(Frame >= 9){
				spawn01("axel_burn", 0, 50, 1);
			}
		}
	}
}

void spawn01(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
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