void main()
{
	rageVel();
	painLand();
}

void rageVel()
{//Adjust velocity in Rage Run Hit
    void self 	= getlocalvar("self");
    void vAniID = getentityproperty(self,"animationID");
	void target = getentityproperty(self,"opponent");
	float xVel 	= getentityproperty(self,"xdir");
    int THeight	= getentityproperty(target, "y");

	if(vAniID == openborconstant("ANI_FREESPECIAL3")){
		changeentityproperty(self, "velocity", xVel/1.2, 0, 0);
		changeentityproperty(target, "velocity", xVel/2.8, 0, 0);
	}
	
	if(vAniID == openborconstant("ANI_FOLLOW4")){
		if(THeight <= 0){
			changeentityproperty(self, "velocity", xVel/1.4, 0, 0);
			changeentityproperty(target, "velocity", xVel/1.4, 0, 0);
		}
	}
}

void painLand()
{//Opponent forced do land and change to pain if hit in mid-air (KOF DESPERATION STYLE)
    void self 	= getlocalvar("self");
    void vAniID = getentityproperty(self,"animationID");
	void target = getentityproperty(self,"opponent");
    int Tx 		= getentityproperty(target,"x");
	int Ty 		= getentityproperty(target,"y");
	int Tz 		= getentityproperty(target,"z");
	
	if(vAniID == openborconstant("ANI_FREESPECIAL3")){
		if(Ty >= 1){
			setidle(target);
			executeanimation(target, openborconstant("ANI_PAIN"), 1);
			changeentityproperty(target,"position", Tx, Tz, 0);
			changeentityproperty(target,"damage_on_landing",0);
			changeentityproperty(target,"nograb",0);
			changeentityproperty(target,"aiflag","falling",0);
			changeentityproperty(target,"aiflag","drop",0);
			changeentityproperty(target,"aiflag","projectile",0);
			changeentityproperty(target,"takeaction", "common_attack_proc");
		}
	}
}